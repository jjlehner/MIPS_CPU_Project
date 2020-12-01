module Control_Unit(
	/* verilator lint_off UNUSED */
	input logic[31:0] instruction,

	output logic register_write,
	output logic memory_to_register,
	output logic memory_write,
	output logic ALU_src_B,
	output logic register_destination,
	output logic branch,
	output logic hi_lo_register_write,
	output logic [5:0] ALU_function

);

	logic [5:0] op;
	logic [5:0] funct;	
	
	always_comb begin
		op = instruction[31:26];
		funct = instruction[5:0];
		case(op)
			6'b000000:	begin		//R-type instruction
					register_write			= 1;
					memory_to_register		= 0;
					memory_write			= 0;
					ALU_src_B				= 0;
					register_destination 	= 1;
					branch					= 0;
					hi_lo_register_write	= ( funct == 6'b011000 || funct == 6'b011001 || funct == 6'b011010 || funct == 6'b011011 ); //checks if instruction is mult/multu/div/divu
					ALU_function			= funct;
			end
			/*
			6'b000001:	begin		//BLTZ instruction or BGEZ instruction
				
			end
			6'b000010: 	begin		//J instruction
				
			end
			6'b000011: 	controls <= {12{1'bx}};	//JAL instruction
			6'b000100: 	controls <= {12{1'bx}};	//BEQ instruction
			6'b000101: 	controls <= {12{1'bx}};	//BNE instruction
			6'b000110: 	controls <= {12{1'bx}};	//BLEZ instruction
			6'b000111: 	controls <= {12{1'bx}};	//BGTZ instruction
			6'b001000: 	controls <= {12{1'bx}};	//ADDI
			6'b001001: 	controls <= {12{1'bx}};	//ADDIU
			6'b001010: 	controls <= {12{1'bx}};	//SLTI
			6'b001011: 	contorls <= {12{1'bx}};	//SLTIU
			6'b001100: 	controls <= {12{1'bx}};	//ANDI
			6'b001101: 	controls <= {12{1'bx}};	//ORI
			6'b001110: 	controls <= {12{1'bx}};	//XORI
			6'b001111: 	controls <= {12{1'bx}};	//LUI
			6'b100000: 	controls <= {12{1'bx}};	//LB
			6'b100001: 	controls <= {12{1'bx}};	//LH
			6'b100011: 	controls <= {12{1'bx}};	//LW
			6'b100100: 	controls <= {12{1'bx}};	//LBU
			6'b100101: 	controls <= {12{1'bx}};	//LHU
			6'b101000: 	controls <= {12{1'bx}};	//SB
			6'b101001: 	controls <= {12{1'bx}};	//SH
			6'b101011: 	controls <= {12{1'bx}};	//SW
			6'b010000: 	controls <= {12{1'bx}};	//Exception instruction MFC0 and MTC0 instruction
			*/
			default : begin						//ilegal operation
				register_write			= 1'bx;
				memory_to_register		= 1'bx;
				memory_write			= 1'bx;
				ALU_src_B				= 1'bx;
				register_destination 	= 1'bx;
				branch					= 1'bx;
				hi_lo_register_write	= 1'bx; //checks if instruction is mult/multu/div/divu
				ALU_function			= 6'bxxxxxx;
			end
		endcase
	end
endmodule