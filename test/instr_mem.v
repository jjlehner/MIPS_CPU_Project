module RAM_32x2048_delay0(
input logic clk,reset, active,
input logic[31:0] instr_address,
output logic[31:0] instr_readdata,
);
parameter RAM_INIT_FILE = "instrmem.txt"; /*this file is non existent yet*/

reg [31:0] memory [8192:0];

/*zero initialise*/
initial begin
integer i;
/*zero initialise*/
for(i=0; i<8192; i++) begin
   memory[i] = 0;
end
/or_isit this/
always @(posedge clk)
    begin
	if (reset) begin
		for(i=0; i<8192; i++) begin
		    memory[i] = 0;
		end
	end
    end
/*ram init*/
$readmemh(RAM_INIT_FILE, memory);
end
assign instr_readdata = memory[instr_address];


endmodule
