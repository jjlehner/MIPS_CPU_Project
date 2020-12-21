module Execute_Memory_Register
(
	input	logic 	clk,
	input	logic	reset,

	//control logic forwarding
	input	logic 			register_write_execute,
	input 	logic			memory_to_register_execute,
	input	logic			memory_write_execute,	
	input	logic			HI_register_write_execute,
	input	logic			LO_register_write_execute,
	input	logic 			program_counter_multiplexer_jump_execute,
	input	logic			j_instruction_execute,
	input	logic			HALT_execute,
	input	logic [5:0]		op_execute,
	input	logic [31:0]	src_A_ALU_execute,
	input	logic [31:0]	src_B_ALU_execute,
	input	logic			program_counter_jalr_control_execute,

	output	logic 			register_write_memory,
	output 	logic			memory_to_register_memory,
	output	logic			memory_write_memory,
	output	logic 			HI_register_write_memory,
	output	logic			LO_register_write_memory,
	output	logic 			program_counter_multiplexer_jump_memory,
	output	logic			j_instruction_memory,
	output	logic			HALT_memory,
	output	logic [5:0]		op_memory,
	output	logic [31:0]	src_A_ALU_memory,
	output	logic [31:0]	src_B_ALU_memory,
	output	logic			program_counter_jalr_control_memory,

	//datapath
	input	logic [31:0]	ALU_output_execute,
	input	logic [31:0]	ALU_HI_output_execute,
	input	logic [31:0]	ALU_LO_output_execute,
	input	logic [31:0]	write_data_execute,
	input	logic [4:0]		write_register_execute,
	input	logic [31:0]	j_program_counter_execute,

	output	logic [31:0]	ALU_output_memory,
	output	logic [31:0]	ALU_HI_output_memory,
	output	logic [31:0]	ALU_LO_output_memory,
	output	logic [31:0]	write_data_memory,
	output	logic [4:0]		write_register_memory,
	output	logic [31:0]	j_program_counter_memory

);

	always_ff @(posedge clk, posedge reset) begin
		if(reset) begin
			register_write_memory <= 0;
			memory_to_register_memory <= 0;
			memory_write_memory <= 0;
			HI_register_write_memory <= 0;
			LO_register_write_memory <= 0;
			program_counter_multiplexer_jump_memory <= 0;
			ALU_output_memory <= 0;
			ALU_HI_output_memory <= 0;
			ALU_LO_output_memory <= 0;
			write_data_memory <= 0;
			write_register_memory <= 0;
			j_instruction_memory <= 0;
			j_program_counter_memory <= 0;
			HALT_memory <= 0;
			op_memory <= 0;
			src_A_ALU_memory <= 0;
			program_counter_jalr_control_memory <= 0;
			src_B_ALU_memory <= 0;
		end
		else begin
			register_write_memory <= register_write_execute;
			memory_to_register_memory <= memory_to_register_execute;
			memory_write_memory <= memory_write_execute;
			HI_register_write_memory <= HI_register_write_execute;
			LO_register_write_memory <= LO_register_write_execute;
			program_counter_multiplexer_jump_memory <= program_counter_multiplexer_jump_execute;
			j_instruction_memory <= j_instruction_execute;
			ALU_output_memory <=ALU_output_execute;
			ALU_HI_output_memory <=ALU_HI_output_execute;
			ALU_LO_output_memory <=ALU_LO_output_execute;
			write_data_memory <=write_data_execute;
			write_register_memory <=write_register_execute;
			j_program_counter_memory <= j_program_counter_execute;
			HALT_memory <= HALT_execute;
			op_memory <= op_execute;
			src_A_ALU_memory <= src_A_ALU_execute;
			program_counter_jalr_control_memory <= program_counter_jalr_control_execute;
			src_B_ALU_memory <= src_B_ALU_execute;
		end

	end

endmodule