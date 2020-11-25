module ALU
(
	input 	logic [2:0]		ALU_operation,
	input 	logic [31:0]	input_1,
	input	logic [31:0]	input_2,

	output	logic [31:0]	ALU_output

);

	always_comb begin
		case(ALU_operation)
			3'b000: 	ALU_output = input_1 & input_2;
			3'b001:		ALU_output = input_1 | input_2;
			3'b010: 	ALU_output = input_1 + input_2;
			3'b110: 	ALU_output = input_1 - input_2;
			3'b111:		ALU_output = (input_1 < input_2) ? {{31{1'b0}},1'b1} : {32{1'b0}};
			default:	ALU_output = {32{1'bx}}; //Not a recognised operation
		endcase
	end
endmodule