module Left_Shift
#(
	parameter shift_distance = 2
)
(
	input	logic [31:0] 	shift_input,
	output	logic [31:0]	shift_output
);
 
	assign shift_output = shift_input << shift_distance;

endmodule