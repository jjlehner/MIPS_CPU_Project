module RAM_32x2048_delay1(
	input logic clk,
	input logic[31:0] address,
	input logic write,
	input logic read,
	input logic[31:0] writedata,
	output logic[31:0] readdata,
	output waitrequest
);
	typedef enum logic[1:0] {
            read_instr = 2'b00
            write_instr = 2'b01
            read_data = 2'b10
	    write_data = 2'b11
	}state_t;

	parameter RAM_INIT_FILE = "";

	reg [31:0] tmp [0:2048];
	reg [31:0] mem [32'hbfc00000:32'hbfffffff];

	reg[3:0] stall_length;
	reg[1:0] state;


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
	
		if (write && state==writeinstr) begin
		    mem[address] <= writedata;
		end
		readdata <= mem[address]; // read after writing, delay1


	always @(*)
		if (read && !write && state==read_data)
		    readdata = mem[address][31:0];
		else
		    readdata = readdata
	end

	always @(posedge clk)
		if (write && !read && state==write_data) begin
		    mem[address][31:0] <= writedata;
		end
	end

endmodule
