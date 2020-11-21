module MUX_2
#(
	parameter BUS_WIDTH = 1
)
(
	input logic control,
	input logic [BUS_WIDTH:0] input_0,
	input logic [BUS_WIDTH:0] input_1,

	output logic [BUS_WIDTH:0] resolved
);

	assign resolved = (control) ? input_1 : input_0;

endmodule