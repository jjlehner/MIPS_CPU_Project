module ALU_Input_Mux(
	input	logic		ALU_src_A_execute,
	input	logic [1:0]	ALU_src_B_execute,
	input	logic [2:0]	forward_one_execute,
	input	logic [2:0]	forward_two_execute,

	input	logic [4:0] sa_execute,
	input	logic [31:0] read_data_1_reg,
	input	logic [31:0] result_writeback,
	input	logic [31:0] ALU_output_memory,
	input	logic [31:0] LO_result_writeback,
	input	logic [31:0] ALU_LO_output_memory,
	input	logic [31:0] read_data_2_reg,
	input	logic [31:0] ALU_HI_output_memory,
	input	logic [31:0] HI_result_writeback,
	input	logic [31:0] sign_imm_execute,
	input	logic [31:0] program_counter_plus_eight_execute,

	output	logic [31:0] src_A_ALU_execute,
	output  logic [31:0] src_B_ALU_execute,
	output	logic [31:0] write_data_execute,
	output	logic [31:0] src_B_mid
);
	logic [31:0] src_mux_input_0_A;
	logic [31:0] src_mux_input_0_B;
	always_comb begin
		case(forward_one_execute) 
			3'b000: src_mux_input_0_A = read_data_1_reg;
			3'b001: src_mux_input_0_A = result_writeback;
			3'b010: src_mux_input_0_A = ALU_output_memory;
			3'b011: src_mux_input_0_A = LO_result_writeback;
			3'b100: src_mux_input_0_A = ALU_LO_output_memory;
			default:src_mux_input_0_A = 0;
		endcase
		case(ALU_src_A_execute)
			1'b0: src_A_ALU_execute = src_mux_input_0_A;
			1'b1: src_A_ALU_execute = {{27{1'b0}},sa_execute};
			default: src_A_ALU_execute = 0;
		endcase
		case(forward_two_execute)
			3'b000: src_mux_input_0_B = read_data_2_reg;
			3'b001: src_mux_input_0_B = result_writeback;
			3'b010: src_mux_input_0_B = ALU_output_memory;
			3'b011: src_mux_input_0_B = HI_result_writeback;
			3'b100: src_mux_input_0_B = ALU_HI_output_memory;
			default:src_mux_input_0_B = 0;
		endcase
		case(ALU_src_B_execute)
			2'b00: src_B_ALU_execute = src_mux_input_0_B;
			2'b01: src_B_ALU_execute = sign_imm_execute;
			2'b10: src_B_ALU_execute = program_counter_plus_eight_execute;
			default: src_B_ALU_execute = 0;
		endcase
		write_data_execute = src_mux_input_0_B;
		src_B_mid = src_mux_input_0_B;
	end

endmodule