module RAM_32x2048_delay0(
	input logic clk,
	input logic[31:0] instr_address,
	output logic[31:0] instr_readdata,
	input logic[31:0] data_address,
	input logic data_write,
	input logic data_read,
	input logic[31:0] data_writedata,
	output logic[31:0] data_readdata
);
	parameter RAM_INIT_FILE = "";

	reg [31:0] tmp [0:2048];
	reg [31:0] mem [32'hbffffffe:32'hbfc00000];
	reg [31:0] datamem [0:512];

	//initialising instr mem with testcase
	initial begin
		integer i;
		integer j;
		/*zero initialise*/
		for(i=0; i<2048; i++) begin
		    tmp[i] = 32'h0000;
		end

		for(i=32'hbfc00000; i<32'hbfffffff; i++) begin
		    mem[i] = 32'h0000;
		end

		for(i=0; i<512; i++) begin
		    datamem[i] = 32'h0000;
		end
		/*ram init*/
		$readmemh(RAM_INIT_FILE, tmp, 0);
		j = 0;
		for(i=32'hbfc00000; i<32'hbfffffff; i=i+32'h00000004) begin
		    mem[i] = tmp[j];
		    j++;
		end
	end
	
	//read access to instructions
	assign instr_readdata = mem[instr_address][31:0];

	//combinatorial read
	always @(*) begin
		if (data_write==0 && data_read==1) 
			data_readdata = datamem[data_address][31:0];
		else
			//avoid latching
			data_readdata = data_readdata;
	end

	//single cycle write
	always @(posedge clk) begin
		if (data_write==1 && data_read==0) begin
		    datamem[data_address][31:0] <= data_writedata;
		end
	end

endmodule
