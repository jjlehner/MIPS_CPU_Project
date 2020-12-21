module RAM_32x2048_delay1(
	input logic clk,
	input logic[31:0] address,
	input logic write,
	input logic read,
	input logic[31:0] writedata,
	input logic[3:0] byteenable,
	output logic[31:0] readdata,
	output logic[31:0] test,
	output	logic waitrequest,
	output logic [31:0]val
);
	parameter RAM_INIT_FILE = "";

	reg [31:0] tmp [0:400000];
	reg [31:0] lower_mem [32'h0:32'h0F00];
	reg [31:0] mem [32'hbfc00000:32'hc0000000];

	logic [7:0] a;
	logic [7:0] b;
	logic [7:0] c;
	logic [7:0] d;
	logic [31:0] writedata_mod;

	initial begin
		integer i;
		integer j;

		/*zero initialise*/
		for(i=0; i<400000; i++) begin
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
	always @(posedge read, posedge write) begin
		waitrequest <= 1;
	end
	

	always @(posedge clk) begin
			if (write) begin
				if(address >= 32'hbfc00000 && address <= 32'hc0000000) begin
					mem[address] <= writedata_mod; // read after writing, delay1
					waitrequest <= 0;
				end else if(address >= 32'h0 && address <= 32'h0F00) begin
					lower_mem[address] <= writedata_mod; // read after writing, delay1
					waitrequest <= 0;
				end
			end
			else if (read) begin
				if(address == 32'h0) begin
					readdata <= 32'h0;
				end
				else if(address >= 32'hbfc00000 && address <= 32'hc0000000) begin
					readdata <= mem[address]; // read after writing, delay1
				end else if(address > 32'h0 && address <= 32'h0F00) begin
					readdata <= lower_mem[address]; // read after writing, delay1
				end
				waitrequest <= 0;
			end
			if(!read && !write) begin
				readdata <= 0;
			end
	end
	always_comb begin
		a = !byteenable[3] ? writedata[31:24] : 4'h0;
		b = !byteenable[2] ? writedata[23:16] : 4'h0;
		c = !byteenable[1] ? writedata[15:8] : 4'h0;
		d = !byteenable[0] ? writedata[7:0] : 4'h0;

		writedata_mod = {a,b,c,d};
		val = mem[32'hBD000000];
	end
endmodule
