module S_PC_Plus(	
	input	logic [31:0]	Current_Inst,
	output	logic [31:0]	Next_Inst
);

assign Next_Inst = Current_Inst + b'100000' ;

endmodule

