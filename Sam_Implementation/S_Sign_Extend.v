module S_Sign_Extend(	
	input	logic [31:0]	Inst,	
	output	logic [31:0]	InstSignExt
);

assign InstSignExt[15:0] = Inst[15:0] ;
assign InstSignExt[31:16] = Inst[15] ;

endmodule

