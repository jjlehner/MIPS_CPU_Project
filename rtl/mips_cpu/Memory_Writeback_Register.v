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
	input	logic [5:0]		op_memory,
	input	logic [3:0]		byteenable_memory,
	input	logic [31:0]	src_A_ALU_memory,
	input	logic [31:0]	src_B_ALU_memory,


	output	logic 			register_write_writeback,
	output 	logic			memory_to_register_writeback,
	output	logic			HI_register_write_writeback,
	output	logic			LO_register_write_writeback,
	output	logic			HALT_writeback,
	output	logic [5:0]		op_writeback,
	output	logic [3:0]     byteenable_writeback,
	output	logic [31:0] 	src_A_ALU_writeback,
	output	logic [31:0]	src_B_ALU_writeback,


	//datapath
	input	logic [31:0]	ALU_output_memory,
	input	logic [4:0]		write_register_memory,
	input 	logic [31:0]	ALU_HI_output_memory,
	input	logic [31:0]	ALU_LO_output_memory,
	input	logic [31:0]	read_data_memory,
	
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
			HALT_writeback <= 0;
			op_writeback <= 0;
			byteenable_writeback <= 0;
			src_A_ALU_writeback <= 0;
			src_B_ALU_writeback <= 0;

			read_data_writeback <= 0;
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
			HALT_writeback <= HALT_memory;

			//TODO place in correct place
			op_writeback <= op_memory;
			byteenable_writeback <= byteenable_memory;
			src_A_ALU_writeback <= src_A_ALU_memory;
			src_B_ALU_writeback <= src_B_ALU_memory;

			read_data_writeback <= read_data_memory;
		end

	end

endmodule