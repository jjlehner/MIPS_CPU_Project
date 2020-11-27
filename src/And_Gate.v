module And_Gate
(
	input logic input_A,
	input logic input_B,

	output logic output_C
);
	assign output_C = input_A && input_B;
endmodule