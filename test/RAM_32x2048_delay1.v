module RAM_32x2048_delay1(
	input logic clk
	input logic[31:0] address,
	input logic write,
	input logic read,
	input logic[31:0] writedata,
	output logic[31:0] readdata
);
	parameter RAM_INIT_FILE = "";

	reg [31:0] memory [2047:0];

	initial begin
		integer i;
		for(i=0; i<2048; i++) begin
		    memory[i] = 0;
		end
		
		//delay1
		if ( RAM_INIT_FILE != "") begin
		    $display("RAM: INIT: loading contents from $s", RAM_INIT_FILE);
		    $readmemh(RAM_INIT_FILE, memory);
		end

	end

	
	always @(posedge clk) begin
	
		if (write) begin
		    memory[address] <= writedata;
		end
		
		readdata <= memory[address]; // read after writing, delay1

	end

endmodule
