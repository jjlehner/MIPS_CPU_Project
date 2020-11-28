module Decode_Execute_Register
(
	input	logic 	clk,
	input 	logic	clear,

	//control logic forwarding
	input	logic 			register_write_decode,
	input 	logic			memory_to_register_decode,
	input	logic			memory_write_decode,
	input	logic			ALU_src_A_decode,
	input	logic			ALU_src_B_decode,
	input	logic			register_destination_decode,
	input	logic			hi_lo_register_write_decode,
	input	logic [5:0]		ALU_function_decode,
	input 	logic [4:0]		Rs_decode,
	input 	logic [4:0]		Rt_decode,
	input	logic [4:0]		Rd_decode,
	input	logic [31:0]	sign_imm_decode,		

	output	logic 			register_write_execute,
	output 	logic			memory_to_register_execute,
	output	logic			memory_write_execute,
	output	logic			ALU_src_A_execute,
	output	logic			ALU_src_B_execute,
	output	logic			register_destination_execute,
	output	logic			hi_lo_register_write_execute,
	output	logic [5:0]		ALU_function_execute,		
	output 	logic [4:0]		Rs_execute,
	output	logic [4:0]		Rt_execute,
	output	logic [4:0]		Rd_execute,
	output	logic [31:0]	sign_imm_execute,	

	//datapath
	input	logic [31:0]	read_data_one_decode,
	input	logic [31:0]	read_data_two_decode,

	output	logic [31:0]	read_data_one_execute,
	output	logic [31:0]	read_data_two_execute

);

	always_ff @(posedge clk, posedge clear) begin
		if(clear) begin
			register_write_execute <= 0;
			memory_to_register_execute <= 0;
			memory_to_write_execute <= 0;
			ALU_operation_id_execute <= 0;
			ALU_src_execute <= 0;
			register_destination_execute <= 0;
			Rd_execute <= 0;
			Rs_execute <= 0;
			Rt_execute <= 0;
			Sign_Imm_execute <= 0;

			read_data_one_execute <= 0;
			read_data_two_execute <= 0;
			
		end else if(clk) begin
			register_write_execute <= register_write_decode;
			memory_to_register_execute <= memory_to_register_decode;
			memory_to_write_execute <= memory_to_write_decode;
			ALU_operation_id_execute <= ALU_operation_id_decode;
			ALU_src_execute <= ALU_src_decode;
			register_destination_execute <= register_destination_decode;
			Rt_execute <= Rt_decode;
			Rd_execute <= Rd_decode;
			Rs_execute <= Rs_decode;
			Sign_Imm_execute <= Sign_Imm_decode;

			read_data_one_execute <= read_data_one_decode;
			read_data_two_execute <= read_data_two_decode;
		end
	end
	

endmodule