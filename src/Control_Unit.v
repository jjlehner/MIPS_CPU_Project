module Control_Unit(
	input logic[31:0] instruction,

	output logic register_write,
	output logic memory_to_register,
	output logic memory_write,
	output logic ALU_src,
	output logic [1:0] register_destination,
	output logic branch

	output logic [2:0] ALU_control_id,

);

	logic [5:0] op;
	logic [5:0] funct;

	logic [8:0] controls;
	assign op = instruction[31:26];
	assign funct = instruction[5:0];

	assign {register_write, register_destinaton, ALU_src, branch, memory_write, memory_to_register} = controls;
	always_comb begin
		case(op)
			6'b000000: controls <= 7'b1010000; //R-type instruction
			6'b000001: controls <= 7'b0xxx100;//BLTZ instruction or BGEZ instruction
			6'b000010: controls <= 7'b0xxx100;//J instruction
			6'b000011: controls <= 7'b1;//JAL instruction
			6'b000100: //BEQ instruction
			6'b000101: //BNE instruction
			6'b000110: //BLEZ instruction
			6'b000111: //BGTZ instruction
			6'b001000: //ADDI
			6'b001001: //ADDIU
			6'b001010: //SLTI
			6'b001011: //SLTIU
			6'b001100: //ANDI
			6'b001101: //ORI
			6'b001110: //XORI
			6'b001111: //LUI
			6'b100000: //LB
			6'b100001: //LH
			6'b100011: //LW
			6'b100100: //LBU
			6'b100101: //LHU
			6'b101000: //SB
			6'b101001: //SH
			6'b101011: //SW
			6'b010000: //Exception instruction MFC0 and MTC0 instruction
			default : controls <= 7'bxxxxxxx; //ilegal operation
		endcase
	end
endmodule