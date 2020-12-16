module Memory_Writeback_Register
(
	input	logic 	clk,
	input	logic	reset,

	//control logic forwarding
	input	logic 			register_write_memory,
	input 	logic			memory_to_register_memory,
	input	logic 			HI_register_write_memory,
	input	logic			LO_register_write_memory,
	input	logic			HALT_memory,

	output	logic 			register_write_writeback,
	output 	logic			memory_to_register_writeback,
	output	logic			HI_register_write_writeback,
	output	logic			LO_register_write_writeback,
	output	logic			HALT_writeback,
	
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

	always_ff @(posedge clk, posedge reset) begin
		if(reset) begin
			register_write_writeback <= 0;
			memory_to_register_writeback <= 0;
			HI_register_write_writeback <= 0;
			LO_register_write_writeback <= 0;
			ALU_output_writeback <= 0;
			write_register_writeback <= 0;
			ALU_HI_output_writeback <= 0;
			ALU_LO_output_writeback <= 0;
			read_data_writeback <= 0;
			HALT_writeback <= 0;
		end
		else begin
			register_write_writeback <= register_write_memory;
			memory_to_register_writeback <=memory_to_register_memory;

			HI_register_write_writeback <= HI_register_write_memory;
			LO_register_write_writeback <= LO_register_write_memory;

			ALU_output_writeback <= ALU_output_memory;
			write_register_writeback <= write_register_memory;
			ALU_HI_output_writeback <= ALU_HI_output_memory;
			ALU_LO_output_writeback <= ALU_LO_output_memory;
			read_data_writeback <= read_data_memory;
			HALT_writeback <= HALT_memory;
		end

	end

endmodule