module Memory_Writeback_Register
(
	input	logic 	clk,

	//control logic forwarding
	input	logic 			register_write_memory,
	input 	logic			memory_to_register_memory,

	output	logic 			register_write_writeback,
	output 	logic			memory_to_register_writeback,

	//datapath
	input	logic [31:0]	ALU_output_memory,
	input	logic [4:0]		write_register_memory,
	input 	logic [31:0]	ALU_HI_output_memory,
	input	logic [31:0]	ALU_LO_output_memory,
	input 	logic [31:0]	read_data_memory,

	output	logic [31:0]	ALU_output_writeback,
	output	logic [4:0]		write_register_writeback,
	output	logic [31:0]	ALU_HI_output_writeback,
	output	logic [31:0]	ALU_LO_output_writeback,
	output	logic [31:0]	read_data_writeback
);

	always_ff @(posedge clk) begin
		register_write_writeback <= register_write_memory;
		memory_to_register_writeback <=memory_to_register_memory;

		ALU_output_writeback <= ALU_output_memory;
		write_register_writeback <= write_register_memory;
		ALU_HI_output_writeback <= ALU_HI_output_memory;
		ALU_LO_output_writeback <= ALU_LO_output_memory;
		read_data_writeback <= read_data_memory;
	end

endmodule