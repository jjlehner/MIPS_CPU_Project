module And_Gate
(
	input logic branch_d,
	input logic equal_id,

	output logic PC_src_D
);
	assign PC_src_D = branch_d && equal_id;
endmodule