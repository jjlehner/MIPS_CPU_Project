module RAM_32x2048_delay0(
input logic clk,
input logic[31:0] instr_address,
output logic[31:0] instr_readdata,
);
parameter RAM_INIT_FILE = "";

reg [31:0] memory [8192:0];

initial begin
integer i;
/*zero initialise*/
for(i=0; i<8192; i++) begin
   memory[i] = 0;
end
/*ram init*/
$readmemh(RAM_INIT_FILE, memory);
end
assign instr_readdata = memory[instr_address[9:2]];


endmodule
