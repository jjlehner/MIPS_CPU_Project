module Decode_Execute_Register
(
	input	logic 	clk,
	input 	logic	clear,
	input	logic	reset,

	//control logic forwarding
	input	logic 			register_write_decode,
	input 	logic			memory_to_register_decode,
	input	logic			memory_write_decode,
	input	logic [1:0]		ALU_src_B_decode,
	input	logic [1:0]		register_destination_decode,
	input	logic			HI_register_write_decode,
	input	logic			LO_register_write_decode,
	input	logic [5:0]		ALU_function_decode,
	input	logic			program_counter_multiplexer_jump_decode,
	input	logic			j_instruction_decode,
	input	logic			using_HI_LO_decode,
	input	logic			HALT_decode,
	input	logic [5:0]		op_decode,
	
	output	logic 			register_write_execute,
	output 	logic			memory_to_register_execute,
	output	logic			memory_write_execute,
	output	logic [1:0]		ALU_src_B_execute,
	output	logic [1:0]		register_destination_execute,
	output	logic			HI_register_write_execute,
	output	logic			LO_register_write_execute,
	output	logic [5:0]		ALU_function_execute,		
	output	logic 			program_counter_multiplexer_jump_execute,
	output	logic			j_instruction_execute,
	output	logic			using_HI_LO_execute,
	output	logic			HALT_execute,
	output	logic [5:0]		op_execute,

	input 	logic [4:0]		Rs_decode,
	input 	logic [4:0]		Rt_decode,
	input	logic [4:0]		Rd_decode,
	input	logic [31:0]	sign_imm_decode,		

	output 	logic [4:0]		Rs_execute,
	output	logic [4:0]		Rt_execute,
	output	logic [4:0]		Rd_execute,
	output	logic [31:0]	sign_imm_execute,

	//datapath
	input	logic [31:0]	src_A_decode,
	input	logic [31:0]	src_B_decode,
	input	logic [31:0] 	program_counter_plus_four_decode,
	input	logic [31:0]	j_program_counter_decode,

	output	logic [31:0]	src_A_execute,
	output	logic [31:0]	src_B_execute,
	output	logic [31:0] 	program_counter_plus_four_execute,
	output	logic [31:0]	j_program_counter_execute


);

	always_ff @(posedge clk, posedge reset) begin
		if(!reset&&!clear) begin
			register_write_execute <= register_write_decode;
			memory_to_register_execute <= memory_to_register_decode;
			memory_write_execute <= memory_write_decode;
			ALU_src_B_execute <= ALU_src_B_decode;
			register_destination_execute <= register_destination_decode;
			HI_register_write_execute <= HI_register_write_decode;
			LO_register_write_execute <= LO_register_write_decode;
			ALU_function_execute <= ALU_function_decode;
			Rs_execute <= Rs_decode;
			Rt_execute <= Rt_decode;
			Rd_execute <= Rd_decode;
			sign_imm_execute <= sign_imm_decode;
			program_counter_multiplexer_jump_execute <= program_counter_multiplexer_jump_decode;
			j_instruction_execute <= j_instruction_decode;
			using_HI_LO_execute <= using_HI_LO_decode;
			op_execute <= op_decode;
			
			program_counter_plus_four_execute <= program_counter_plus_four_decode;
			j_program_counter_execute <= j_program_counter_decode;
			src_A_execute <= src_A_decode;
			src_B_execute <= src_B_decode;

			HALT_execute <= HALT_decode;
		end
		else begin
			register_write_execute <= 0;
			memory_to_register_execute <= 0;
			memory_write_execute <= 0;
			ALU_src_B_execute <= 0;
			register_destination_execute <= 2'b00;
			HI_register_write_execute <= 0;
			LO_register_write_execute <= 0;
			ALU_function_execute <= {6{1'b0}};
			Rt_execute <= {5{1'b0}};
			Rd_execute <= {5{1'b0}};
			Rs_execute <= {5{1'b0}};
			sign_imm_execute <= {32{1'b0}};
			program_counter_multiplexer_jump_execute <= 0;
			j_instruction_execute <= 0;
			using_HI_LO_execute <= 0;
			op_execute <= 0;

			program_counter_plus_four_execute <= {32{1'b0}};
			j_program_counter_execute <= {32{1'b0}};
			src_A_execute <= {32{1'b0}};
			src_B_execute <= {32{1'b0}};

			HALT_execute <= 0;
		end
	end
	
	

endmodule