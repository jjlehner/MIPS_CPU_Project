module Sign_Extension
(
	input	logic	[15:0] short_input,
	output	logic	[31:0] extended_output
);
	assign extended_output = {{16{short_input[15]}},short_input};
endmodule