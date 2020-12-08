module Program_Counter(
	input	logic clk,
	input 	logic [31:0] address_input,
	input	logic enable, //active low
	input	logic reset,
	output	logic halt,
	output	logic [31:0] address_output

);
	always_comb begin
		halt = (address_output == 0);
	end
	always_ff @(posedge clk, posedge reset) begin
		if(reset) begin
			address_output <= 32'hBFC00000;
		end
		if (!enable && !reset) begin
			address_output <= address_input;
		end
	end

endmodule