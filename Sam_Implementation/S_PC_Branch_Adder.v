module S_PC_Branch_Adder(	
	input	logic [31:0]	Current_Inst,	
    input   logic [31:0]    Branch_Val
	output	logic [31:0]	Next_Inst
);


assign Branch_Val = Branch_Val << 2 ;
assign Next_Inst = Current_Inst + Branch_Val_Extended ;

endmodule 