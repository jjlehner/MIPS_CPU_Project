//Harvard bus
module mips_cpu(
	input logic clk,
    input logic reset,
    output logic active,
    output logic [31:0] register_v0,

    /* New clock enable. See below. */
    input logic clk_enable,

    /* Combinatorial read access to instructions */
    output logic[31:0]  instr_address,
    input logic[31:0]   instr_readdata,

    /* Combinatorial read and single-cycle write access to instructions */
    output logic[31:0] data_address,
    output logic data_write,
    output logic data_read,
    output logic[31:0] data_writedata,
    input  logic[31:0] data_readdata
);

    logic internal_clk;
    
    logic HI_LO_output;

    //Fetch datapath
    logic [31:0] program_counter_prime;
    logic [31:0] program_counter_fetch;
    logic [31:0] program_counter_plus_four_fetch;
    
    //decode Controls
    logic       program_counter_source_decode;
    logic       register_write_decode;
    logic       memory_to_register_decode;
    logic       memory_write_decode;
    logic       ALU_src_A_decode;
    logic       ALU_src_B_decode;
    logic       register_destination_decode;
    logic       branch_decode;
    logic       hi_lo_register_write_decode;
    logic       equal_decode;
    logic [5:0] ALU_function_decode;

    //decode datapath
    //TODO move instruction logic to control
    //TODO consider using alias rather than assign because that's less confusing
    logic [31:0]    program_counter_branch_decode;
    logic [31:0]    instruction_decode;
    logic [31:0]    program_counter_plus_four_decode;
    logic [4:0]     read_address_1;
	    assign      read_address_1= instruction_decode[25:21];
    logic [4:0]     read_address_2;
	    assign      read_address_2= instruction_decode[20:16];
    logic [15:0]    immediate;
	    assign      immediate = instruction_decode[15:0];
    logic [4:0]     Rd_decode;
        assign      Rd_decode = instruction_decode[15:11];
    logic [31:0]    shifter_output_decode;
    logic [31:0]    register_file_output_A_decode;
    logic [31:0]    register_file_output_B_decode;
    logic [31:0]    register_file_output_A_resolved_decode;
    logic [31:0]    register_file_output_B_resolved_decode;
    logic [31:0]    sign_imm_decode;

    //Execute Controls

    logic           register_destination_execute;
    logic [4:0]     Rt_execute;
    logic [4:0]     Rd_execute;
    logic [4:0]     write_register_execute;
    
    //Execute Datapath
    logic [31:0]    register_file_output_A_execute;
    logic [31:0]    register_file_output_B_execute;
    logic [31:0]    source_A_ALU_execute;
    logic [31:0]    source_B_ALU_execute;
    logic [31:0]    write_data_execute;

    //Writeback controls
    logic register_write_writeback;
    logic HI_LO_write_writeback;

    //Writeback datapath
    logic [4:0] write_register_writeback;
    logic [31:0] result_writeback;
    logic [31:0] result_HI_writeback;
    logic [31:0] result_LO_writeback;

    //Hazard Unit Outputs
    logic       stall_fetch;
    logic       stall_decode;
    logic       forward_A_decode;
    logic       forward_B_decode;
    logic       flush_execute;
    logic [1:0] forward_A_execute;
    logic [1:0] forward_B_execute;

    assign internal_clk = clk && clk_enable;
    assign instr_address = program_counter_prime;

    Register_File register_file(
        .clk(internal_clk),.pipelined(1), 
        .HI_LO_output(HI_LO_output), 
        .write_enable(register_write_writeback), 
        .HI_LO_write_enable(HI_LO_write_writeback),
        .read_address_1(read_address_1), 
        .read_address_2(read_address_2), 
        .write_address(write_register_writeback), 
        .write_data(result_writeback), 
        .HI_write_data(result_HI_writeback), 
        .LO_write_data(result_LO_writeback), 
        .read_data_1(register_file_output_A_decode),
        .read_data_2(register_file_output_B_decode)
    );

    Program_Counter pc (
        .clk(internal_clk),
        .address_input(program_counter_prime),
        .enable(stall_fetch),
        .address_output(program_counter_fetch)
    );

    Adder plus_four_adder(
        .a(program_counter_fetch),
        .b({{28{1'b0}},4'b1111}),
        .z(program_counter_plus_four_fetch)
    );

    MUX_2INPUT #(.BUS_WIDTH(32)) program_counter_multiplexer (
        .control(program_counter_source_decode),
        .input_0(program_counter_plus_four_fetch),
        .input_1(program_counter_branch_decode),
        .resolved(program_counter_prime)
    );

    Fetch_Decode_Register fetch_decode_register(
        .clk(internal_clk),
        .enable(stall_decode),
        .clear(program_counter_source_decode),
        .instruction_fetch(data_readdata),
        .program_counter_plus_four_fetch(program_counter_plus_four_fetch),
        .instruction_decode(instruction_decode),
        .program_counter_plus_four_decode(program_counter_plus_four_decode)
    );

    Control_Unit control_unit(
        .instruction(instruction_decode),
        .register_write(register_write_decode),
        .memory_to_register(memory_to_register_decode),
        .memory_write(memory_write_decode),
        .ALU_src_A(ALU_src_A_decode),
        .ALU_src_B(ALU_src_B_decode),
        .register_destination(register_destination_decode),
        .branch(branch_decode),
        .hi_lo_register_write(hi_lo_register_write_decode),
        .ALU_function(ALU_function_decode)
    );

    MUX_2INPUT #(.BUS_WIDTH(32)) register_file_output_A_mux 
    (
        .control(forward_A_decode),
        .input_0(register_file_output_A_decode),
        .input_1(/*Either Result_write_back or high register output*/),
        .resolved(register_file_output_A_resolved_decode)
    );

    MUX_2INPUT #(.BUS_WIDTH(32))register_file_output_B_mux
    (
        .control(forward_B_decode),
        .input_0(register_file_output_B_decode),
        .input_1(/*Either Result_write_back or lo register output*/),
        .resolved(register_file_output_B_resolved_decode)
    );

    Equal_Comparator reg_output_comparator(
        .a(register_file_output_A_resolved_decode),
        .b(register_file_output_B_resolved_decode),
        .c(equal_decode)
    );

    And_Gate program_counter_source_and_gate_decode(
        .input_A(branch_decode),
        .input_B(equal_decode),
        .output_C(program_counter_source_decode)
    );

    Sign_Extension sign_extender_decode(
        .short_input(immediate),
        .extended_output(sign_imm_decode)
    );

    Left_Shift shifter_decode(
        .shift_input(sign_imm_decode),
        .shift_output(shifter_output_decode)
    );

    Adder adder_decode(
        .a(shifter_output_decode),
        .b(program_counter_plus_four_decode),
        .z(program_counter_branch_decode)
    );

    Decode_Execute_Register decode_execute_register(
        .clk(internal_clk),
        .clear(flush_execute),
        .register_write_decode(register_write_decode),
        .memory_to_register_decode(memory_to_register_decode),
        .memory_write_decode(memory_write_decode),
        .ALU_src_A(register_file_output_A_resolved_decode),
        .ALU_src_B(register_file_output_B_resolved_decode),
        .register_destination_decode(register_destination_decode),
        .hi_lo_register_write_decode(hi_lo_register_write_decode),
        .ALU_fuction_decode(ALU_fuction_decode),
        .Rs_decode(read_address_1),
        .Rt_decode(read_address_2),
        .Rd_decode(Rd_decode),
        .sign_imm_decode(sign_imm_decode),

        .register_write_execute(register_write_decode),
        .memory_to_register_execute(memory_to_register_execute),
        .memory_write_execute(memory_write_execute),
        .ALU_src_A_execute(ALU_src_A_execute),
        .ALU_src_B_execute(ALU_src_B_execute),
        .register_destination_execute(register_destination_execute),
        .hi_lo_register_write_execute(hi_lo_register_write_execute),
        .ALU_function_execute(ALU_function_execute),
        .Rs_execute(rs_execute),
        .Rt_execute(rt_execute),
        .Rd_execute(rd_execute),
        .sign_imm_execute(sign_imm_execute),

        .read_data_one_decode(register_file_output_A_decode),
        .read_data_two_decode(register_file_output_B_decode),
        .read_data_one_execute(register_file_output_A_execute),
        .read_data_two_execute(register_file_output_B_execute)
    );

    MUX_2INPUT #(.BUS_WIDTH(5)) write_register_execute_mux(
        .control(register_destination_execute),
        .input_0(Rt_execute),
        .input_1(Rd_execute),
        .resolved(write_register_execute)
    );

    MUX_4INPUT #(.BUS_WIDTH(32)) register_file_output_A_execute_mux(
        .control(forward_A_execute),
        .input_0(register_file_output_A_execute),
        .input_1(result_writeback),
        .input_2(ALU_out_memory),
        .input_3(), //intentionally left unconnected

        .resolved(source_A_ALU_execute)
    );

    MUX_4INPUT #(.BUS_WIDTH(32)) register_file_output_B_execute_mux(
        .control(forward_B_execute),
        .input_0(register_file_output_B_execute),
        .input_1(result_writeback),
        .input_2(ALU_out_memory),
        .input_3(), //intentionally left unconnected

        .resolved(write_data_execute)
    );

    MUX_2INPUT #(.BUS_WIDTH(32)) source_B_ALU_mux(
        .control(ALU_src_B_execute),
        .input_0(write_data_execute),
        .input_1(sign_imm_execute),

        .resolved(source_B_ALU_execute)
    );

    
    always_ff @(posedge clk) begin
        if (reset) begin
            
        end
    end



endmodule