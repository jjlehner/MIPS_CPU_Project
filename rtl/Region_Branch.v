module Region_Branch(
	input	logic [1:0] 	pc_prefix,
	input	logic [27:0]	offset,
	output	logic [31:0]	j_program_counter_execute
);

	assign pc_new = {pc_prefix, offset, j_program_counter_execute};
endmodule