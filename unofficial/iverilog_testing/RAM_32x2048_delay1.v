module RAM_32x2048_delay1(
	input logic clk,
	input logic[31:0] address,
	input logic write,
	input logic read,
	input logic[31:0] writedata,
	output logic[31:0] readdata,
	output logic[31:0] test,
	output	logic waitrequest
);
	parameter RAM_INIT_FILE = "";

	reg [31:0] tmp [0:2048];
	reg [31:0] mem [32'hbfc00000:32'hc0000000];


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
			$display("%h %d", i,mem[i]);
		    j++;
		end
		waitrequest = 0;

	end
	logic [1:0] state;
	always @(posedge read, posedge write) begin
		waitrequest <= 1;
		state = 2'b01;
	end
	
	always @(posedge clk) begin
		if(state == 2'b01) begin
			state <= 2'b11;
		end
		else if(state == 2'b11) begin
			if (write) begin
			    mem[address] <= writedata;
				waitrequest <= 0;
			end
			else if (read) begin
				$display("%h %h %h", address, mem[address],readdata);
				readdata <= mem[address]; // read after writing, delay1
				waitrequest <= 0;
			end
			test <= mem[address];
			state <= 2'b00;
		end
	end

endmodule
