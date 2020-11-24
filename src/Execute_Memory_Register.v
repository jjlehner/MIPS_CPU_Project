module Execute_Memory_Register
(
	input	logic 	clk,

	//control logic forwarding
	input	logic 			register_write_execute,
	input 	logic			memory_to_register_execute,
	input	logic			memory_to_write_execute,	

	output	logic 			register_write_memory,
	output 	logic			memory_to_register_memory,
	output	logic			memory_to_write_memory,

	//datapath
	input	logic [31:0]	ALU_out_execute,
	input	logic [31:0]	write_data_execute,
	input	logic [4:0]		write_register_execute,

	output	logic [31:0]	ALU_out_memory,
	output	logic [31:0]	write_data_memory,
	output	logic [4:0]		write_register_memory

);

	always_ff @(posedge clk) begin
		register_write_memory <= register_write_execute;
		memory_to_register_memory <=memory_to_register_execute;
		memory_to_write_memory <= memory_to_write_execute;
		ALU_out_memory <= ALU_out_execute;
		write_data_memory <= write_data_execute;
		write_register_memory <= write_register_execute;
	end

endmodule