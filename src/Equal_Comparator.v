module Equal_Comparator
(
	input logic 	[31:0] a,
	input logic 	[31:0] b,

	output logic 	c
);
	assign c = (a == b);
endmodule