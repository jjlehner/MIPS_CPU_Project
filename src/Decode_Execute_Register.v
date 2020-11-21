module Decode_Execute_Register
(
	input	logic 	clk,
	input 	logic	clear,

	//control logic forwarding
	input	logic 		register_write_decode,
	input 	logic		memory_to_register_decode,
	input	logic		memory_to_write_decode,
	input	logic [2:0]	ALU_operation_id_decode,
	input	logic		ALU_src_decode,
	input	logic		register_destination_decode,

	output	logic 		register_write_execute,
	output 	logic		memory_to_register_execute,
	output	logic		memory_to_write_execute,
	output	logic [2:0]	ALU_operation_id_execute,
	output	logic		ALU_src_execute,
	output	logic		register_destination_execute,

	//datapath
	input	logic [31:0]	instruction_fetch,
	input	logic [31:0]	PC_plus_four_fetch,
	
	output	logic [31:0]	instruction_decode,
	output	logic [31:0]	PC_plus_four_decode

);

	always_ff @(posedge clk) begin
		
	end
	always_ff @(posedge clear) begin

	end
endmodule