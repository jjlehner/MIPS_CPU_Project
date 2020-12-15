module RAM_32x2048_delay1(
	input logic clk,
	input logic[31:0] address,
	input logic write,
	input logic read,
	input logic[31:0] writedata,
	output logic[31:0] readdata
);
	parameter RAM_INIT_FILE = "";

	reg [31:0] tmp [0:2048];
	reg [31:0] mem [32'hbfffffff:32'hbfc00000];


	initial begin
		integer i;
		integer j;
		/*zero initialise*/
		for(i=0; i<2048; i++) begin
		    tmp[i] = 32'h0000;
		end

		for(i=32'hbfc00000; i<32'hc0000000; i++) begin
		    mem[i] = 32'h0000;
		end

		/*ram init*/
		$readmemh(RAM_INIT_FILE, tmp, 0);
		j = 0;
		for(i=32'hbfc00000; i<32'hc0000000; i=i+32'h00000004) begin
		    mem[i] = tmp[j];
		    j++;
		end
	end

	
	always @(posedge clk) begin
	
		if (write) begin
		    mem[address] <= writedata;
		end
		
		readdata <= mem[address]; // read after writing, delay1

	end

endmodule
