module Fetch_Decode_Register
(
	input	logic 	clk,
	input	logic	enable, //active low
	input 	logic	clear,
	input	logic	reset,

	input	logic	HALT_fetch,
	output	logic	HALT_decode,
	
	input	logic [31:0]	program_counter_plus_four_fetch,
	
	output	logic [31:0]	program_counter_plus_four_decode

);

	always_ff @(posedge clk, posedge reset) begin
		if(reset) begin
			program_counter_plus_four_decode <=  32'hBFC00004;
			HALT_decode <= 0;
		end
		else if(!enable) begin
			if(clear) begin
				program_counter_plus_four_decode <= {32{1'b0}};
				HALT_decode <= 0;
			end else begin
				program_counter_plus_four_decode <= program_counter_plus_four_fetch;
				HALT_decode <= HALT_fetch;
			end
		end
		
	end
	
	
endmodule