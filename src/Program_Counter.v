module Program_Counter(
	input 	logic [31:0] address_input,
	input	logic clk,
	input	logic enable, //active low
	output	logic [31:0] address_output

);

	always_ff @(posedge clk) begin
		if (!enable) begin
			address_output <= address_input;
		end
	end

endmodule