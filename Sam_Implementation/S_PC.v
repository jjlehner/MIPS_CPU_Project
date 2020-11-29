module S_PC	
    input clk,
	input	logic [31:0]	Next_Inst,
	output	logic [31:0]	Current_Inst
);

reg[31:0] S_PC[0];

always_ff @ (posedge clk)
begin
    Current_Inst <= Next_Inst;
end 

endmodule