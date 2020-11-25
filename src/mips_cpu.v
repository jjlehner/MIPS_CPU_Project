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

    logic register_write_writeback;
    logic HI_LO_write_writeback;
    logic [31:0] instruction_decode;
    logic [4:0] read_address_1 = instruction_decode[25:21];
    logic [4:0] read_address_2 = instruction_decode[20:16];
    logic [4:0] write_register_writeback;
    logic [31:0] result_writeback;
    logic [31:0] result_HI_writeback;
    logic [31:0] result_LO_writeback;
    logic [31:0] register_file_output_1;
    logic [31:0] register_file_output_2;
    logic HI_LO_output;

    //Fetch datapath
    logic [31:0] program_counter_prime;
    logic [31:0] program_counter_fetch;
    logic [31:0] program_counter_plus_four;
    
    //Decoder Controls
    logic program_counter_source_decoder;
    
    //Decoder datapath
    logic [31:0] program_counter_branch_decoder;
    //Hazard Unit Outputs
    logic stall_fetch;

    assign internal_clk = clk && clk_enable;

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
        .read_data_1(register_file_output_1),
        .read_data_2(register_file_output_2)
    );

    Program_Counter pc (
        .clk(internal_clk),
        .address_input(program_counter_prime),
        .enable(stall_fetch),
        .address_output(program_counter_fetch)
    );

    Adder adder(
        .a(program_counter_fetch),
        .b({{28{1'b0}},4'b1111}),
        .z(program_counter_plus_four)
    );

    MUX_2INPUT #(.BUS_WIDTH(32)) program_counter_multiplexer (
        .control(program_counter_source_decoder),
        .input_0(program_counter_plus_four),
        .input_1(program_counter_branch_decoder),
        .resolved(program_counter_prime)
    );

    always_ff @(posedge clk) begin
        if (reset) begin
            
        end
    end



endmodule