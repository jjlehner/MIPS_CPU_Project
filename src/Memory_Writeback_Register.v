module Memory_Writeback_Register
(
	input	logic 	clk,

	//control logic forwarding
	input	logic 			register_write_memory,
	input 	logic			memory_to_register_memory,

	output	logic 			register_write_writeback,
	output 	logic			memory_to_register_writeback,

	//datapath
	input	logic [31:0]	ALU_out_memory,
	input	logic [4:0]		write_register_memory,

	output	logic [31:0]	ALU_out_writeback,
	output	logic [4:0]		write_register_writeback

);

	always_ff @(posedge clk) begin
		register_write_writeback <= register_write_memory;
		memory_to_register_writeback <= memory_to_register_memory;
		ALU_out_writeback <= ALU_out_memory;
		write_register_writeback <= write_register_memory;
	end

endmodule