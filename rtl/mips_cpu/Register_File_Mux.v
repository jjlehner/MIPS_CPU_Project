module Register_File_Mux(

	input	logic 			forward_one_decode,
	input	logic			forward_two_decode,
	input	logic			using_HI_LO,
	input	logic [31:0]	read_data_1_reg,
	input	logic [31:0] 	read_data_2_reg,
	input	logic [31:0]	HI_data_reg,
	input	logic [31:0] 	LO_data_reg,
	input	logic [31:0]	ALU_output_memory,

	output	logic [31:0]	comparator_1,
	output	logic [31:0]	comparator_2,
	output	logic [31:0]	resolved_reg_file_output_one,
	output	logic [31:0]	resolved_reg_file_output_two
);

	assign comparator_1 = (forward_one_decode) ? ALU_output_memory : read_data_1_reg;
	assign comparator_2 = (forward_two_decode) ? ALU_output_memory : read_data_2_reg;
	assign resolved_reg_file_output_one = using_HI_LO ? LO_data_reg : read_data_1_reg;
	assign resolved_reg_file_output_two = using_HI_LO ? HI_data_reg : read_data_1_reg;

endmodule