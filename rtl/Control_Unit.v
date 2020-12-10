module Control_Unit(
	/* verilator lint_off UNUSED */
	input logic[31:0] 	instruction,

	output logic 		register_write,
	output logic 		memory_to_register,
	output logic 		memory_write,
	output logic [1:0]	ALU_src_B,
	output logic [1:0]	register_destination,
	output logic 		branch,
	output logic 		hi_lo_register_write,
	output logic [5:0] 	ALU_function,
	output logic 		program_counter_multiplexer_jump,
	output logic		j_instruction,
	output logic		ALU_output_memory
);

	logic [5:0] op;
	logic [4:0] rt;
	logic [5:0] funct;	
	
	always_comb begin
		op = instruction[31:26];
		rt = instruction[20:16]; 
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
				program_counter_multiplexer_jump = ( funct ==  6'b001000 || funct == 6'b001001 ); //checks if instruction is jr or jalr
			end
			
			6'b000001:	begin		//BLTZ,BLTZAL, BGEZ,BGEZAL instruction
				register_write			= (rt == 5'b10001 || rt == 5'b10000);
				memory_to_register		= 0;
				memory_write			= 0;
				ALU_src_B				= 2'b10;
				register_destination 	= 2'b10;
				branch					= 1;
				hi_lo_register_write	= 0;
				ALU_function			= 6'b111111;
				program_counter_multiplexer_jump = 0;
			end
			/*
			6'b000010: 	begin		//J instruction
				
			end
			6'b000011: 	controls <= {12{1'bx}};	//JAL instruction
			*/
			6'b000100: 	begin 		//BEQ instruction
				register_write			= 0;
				memory_to_register		= 0;
				memory_write			= 0;
				ALU_src_B				= 0;
				register_destination 	= 0;
				branch					= 1;
				hi_lo_register_write	= 0;
				ALU_function			= 6'b111111;
				program_counter_multiplexer_jump = 0;
			end
			
			6'b000101: 	begin		//BNE
				register_write			= 0;
				memory_to_register		= 0;
				memory_write			= 0;
				ALU_src_B				= 0;
				register_destination 	= 0;
				branch					= 1;
				hi_lo_register_write	= 0;
				ALU_function			= 6'b111111;
				program_counter_multiplexer_jump = 0;
			end
			
			
			6'b000110:	begin					//BLEZ instruction
				register_write			= 0;
				memory_to_register		= 0;
				memory_write			= 0;
				ALU_src_B				= 0;
				register_destination 	= 0;
				branch					= 1;
				hi_lo_register_write	= 0;
				ALU_function			= 6'b111111;
				program_counter_multiplexer_jump = 0;
			end	
			6'b000111:	begin					//BGTZ 
				register_write			= 0;
				memory_to_register		= 0;
				memory_write			= 0;
				ALU_src_B				= 0;
				register_destination 	= 0;
				branch					= 1;
				hi_lo_register_write	= 0;
				ALU_function			= 6'b111111;
				program_counter_multiplexer_jump = 0;
			end
			/*
			6'b001000: 	controls <= {12{1'bx}};	//ADDI
			*/
			6'b001001: begin					//ADDIU
				register_write			= 1;
				memory_to_register		= 0;
				memory_write			= 0;
				ALU_src_B				= 1;
				register_destination 	= 0;
				branch					= 0;
				hi_lo_register_write	= 0;
				ALU_function			= 6'b100001;
				program_counter_multiplexer_jump = 0;
			end
			/*
			6'b001010: 	controls <= {12{1'bx}};	//SLTI
			6'b001011: 	contorls <= {12{1'bx}};	//SLTIU
			6'b001100: 	controls <= {12{1'bx}};	//ANDI
			6'b001101: 	controls <= {12{1'bx}};	//ORI
			6'b001110: 	controls <= {12{1'bx}};	//XORI
			*/
			6'b001111: 	begin					//LUI 
				register_write			= 1;
				memory_to_register		= 0;
				memory_write			= 0;
				ALU_src_B				= 1;
				register_destination 	= 0;
				branch					= 0;
				hi_lo_register_write	= 0;
				ALU_function			= 6'b111111;
				program_counter_multiplexer_jump = 0;
			end
			
			/*
			6'b100000: 	controls <= {12{1'bx}};	//LB
			6'b100001: 	controls <= {12{1'bx}};	//LH
			*/
			6'b100011:	begin				//LW
				register_write			= 1;
				memory_to_register		= 1;
				memory_write			= 0;
				ALU_src_B				= 1;
				register_destination 	= 0;
				branch					= 0;
				hi_lo_register_write	= 0;
				ALU_function			= 6'b100001;//add unsigned function
				program_counter_multiplexer_jump = 0;
			end
			/*
			6'b100100: 	controls <= {12{1'bx}};	//LBU
			6'b100101: 	controls <= {12{1'bx}};	//LHU
			6'b101000: 	controls <= {12{1'bx}};	//SB
			6'b101001: 	controls <= {12{1'bx}};	//SH
			*/
			6'b101011: 	begin	//SW
				register_write			= 0;
				memory_to_register		= 1;
				memory_write			= 1;
				ALU_src_B				= 1;
				register_destination 	= 0;
				branch					= 0;
				hi_lo_register_write	= 0;
				ALU_function			= 6'b100001;//add unsigned function
				program_counter_multiplexer_jump = 0;
			end
			/*
			6'b010000: 	controls <= {12{1'bx}};	//Exception instruction MFC0 and MTC0 instruction
			*/
			default : begin						//ilegal operation
				register_write			= 1'bx;
				memory_to_register		= 1'bx;
				memory_write			= 1'bx;
				ALU_src_B				= 2'bxx;
				register_destination 	= 2'bxx;
				branch					= 1'bx;
				hi_lo_register_write	= 1'bx; //checks if instruction is mult/multu/div/divu
				ALU_function			= 6'bxxxxxx;
				program_counter_multiplexer_jump  = 1'bx;
			end
		endcase
	end
endmodule