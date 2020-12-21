module Comparator
(
	input logic		[5:0]  	op,
	input logic		[4:0]	rt,
	input logic 	[31:0] 	a,
	input logic 	[31:0] 	b,
	output logic 	c
);
	always_comb begin
		case(op)
			6'b000001: begin
				if(rt == 5'b00001 || rt == 5'b10001) begin
					c = $signed(a) >= $signed(0);
				end
				else if(rt == 5'b00000 || rt == 5'b10000) begin
					c = $signed(a) < $signed(0);
				end
				else c = 0;
			end
			6'b000100: begin
				c = (a == b);
			end
			6'b000101: begin
				c = (a != b);
			end
			6'b000110: begin
				c = $signed(a) <= $signed(0);
			end
			6'b000111: begin
				c =  $signed(a) > $signed(0);
			end
			default: begin
				c= 0;
			end
		endcase
	end
endmodule