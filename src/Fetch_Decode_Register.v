module Fetch_Decode_Register
(
	input	logic 	clk,
	input	logic	enable, //active low
	input 	logic	clear,

	input	logic [31:0]	instruction_fetch,
	input	logic [31:0]	PC_plus_four_fetch,
	
	output	logic [31:0]	instruction_decode,
	output	logic [31:0]	PC_plus_four_decode

);

	always_ff @(posedge clk, posedge clear) begin
		if(!enable) begin
			if(clear) begin
				instruction_decode <= 0;
				PC_plus_four_decode <= 0;
			end else if(clk) begin
				instruction_decode <= instruction_fetch;
				PC_plus_four_decode <= PC_plus_four_fetch;
			end
		end
	end
	
endmodule