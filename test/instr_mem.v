module RAM_32x2048_delay0(
input logic[31:0] instr_address,
output logic[31:0] instr_readdata,
);
parameter RAM_INIT_FILE = "instrmem.txt"; /*this file is non existent yet*/

reg [31:0] memory [8192:0];

/*zero initialise*/
initial
begin
/*ram init*/
$readmemh(RAM_INIT_FILE, memory, 0, 8191);
end
assign instr_readdata = memory[instr_address];


endmodule
