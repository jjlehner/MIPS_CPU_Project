module Fetch_Decode_Register
(
	input	logic 	clk,
	input	logic	enable, //active low
	input 	logic	clear,
	input	logic	reset,

	input	logic [31:0]	instruction_fetch,
	input	logic [31:0]	program_counter_plus_four_fetch,
	
	output	logic [31:0]	instruction_decode,
	output	logic [31:0]	program_counter_plus_four_decode

);

	always_ff @(posedge clk, posedge reset) begin
		if(reset) begin
			instruction_decode <= 0;
				program_counter_plus_four_decode <= {32{1'b0}};
		end
		else if(!enable) begin
			if(clear) begin
				instruction_decode <= 0;
				program_counter_plus_four_decode <= {32{1'b0}};
			end else begin
				instruction_decode <= instruction_fetch;
				program_counter_plus_four_decode <= program_counter_plus_four_fetch;
			end
		end
		
	end
	
	
endmodule