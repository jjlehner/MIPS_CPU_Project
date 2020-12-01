//SHAMT will be routed to the ALU via input_1
module ALU
(
	input 	logic [5:0]		ALU_operation,
	input 	logic [31:0]	input_1,
	input	logic [31:0]	input_2,

	output	logic [31:0]	ALU_output,
	output	logic [31:0]	ALU_HI_output,
	output	logic [31:0]	ALU_LO_output

);

	logic [4:0] shift_amount = input_1[10:6];
	logic [63:0] sign_extened_input_1 = { { 32{ input_1[31] } }, input_1[31:0] };			
	logic [63:0] sign_extened_input_2 = { { 32{ input_2[31] } }, input_2[31:0] };			
	logic [63:0] extended_input_1 = { { 32{ 1'b0 } }, input_1 };
	logic [63:0] extended_input_2 = { { 32{ 1'b0 } }, input_2 };
	logic [63:0] ALU_HI_LO_output;
	assign ALU_HI_output = ALU_HI_LO_output[63:32];
	assign ALU_LO_output = ALU_HI_LO_output[31:0];
	always_comb begin
		ALU_HI_LO_output = {64{1'bx}};
		ALU_output = {32{1'bx}};
		case(ALU_operation)
			6'b000000: 	ALU_output = input_2 << shift_amount; 					//SLL
			6'b000001:	ALU_output = input_2 >> shift_amount; 					//SRL
			6'b000011: 	ALU_output = input_2 >>> shift_amount;					//SRA
			6'b000100:	ALU_output = input_2 << input_1[4:0];					//SLLV
			6'b000110: 	ALU_output = input_2 >> input_1[4:0];					//SRLV
			6'b000111: 	ALU_output = input_2 >>> input_1[4:0];					//SRAV
			6'b001000:	ALU_output = input_2; 									//JR
			6'b001001:	ALU_output = input_2;									//JALR
			6'b010000:	ALU_output = input_2;									//MFHI
			6'b010001:	ALU_output = input_2;									//MTHI
			6'b010010:	ALU_output = input_2;									//MFLO
			6'b010011:	ALU_output = input_2;									//MTLO
			6'b011000:	ALU_HI_LO_output = $signed(sign_extened_input_1) * $signed(sign_extened_input_2);	//MULT	
			6'b011001:	ALU_HI_LO_output = extended_input_1 * extended_input_2;	//MULTU
			6'b011010:	begin													//DIV
				ALU_HI_LO_output = {$signed(input_1) / $signed(input_2) ,{32{1'b0}}};		
				ALU_HI_LO_output = ALU_HI_LO_output + {{32{1'b0}},$signed(input_1) % $signed(input_2)};
			end
			6'b011011: 	begin													//DIVU
				ALU_HI_LO_output = {input_1 / input_2, {32{1'b0}}};		
				ALU_HI_LO_output = ALU_HI_LO_output + {{32{1'b0}},input_1 % input_2};
			end
			6'b100000: 	ALU_output = $signed(input_1) + $signed(input_2);		//ADD
			6'b100001:	ALU_output = input_1 + input_2;							//ADDU
			6'b100010:	ALU_output = $signed(input_1) - $signed(input_2);		//SUB
			6'b100011:	ALU_output = input_1 - input_2;							//SUBU
			6'b100100:	ALU_output = input_1 & input_2;							//AND
			6'b100101:	ALU_output = input_1 | input_2;							//OR
			6'b100110:	ALU_output = input_1 ^~ input_2;						//XOR
			6'b100111:	ALU_output = ~(input_1|input_2);						//NOR
			6'b101010:	ALU_output = ($signed(input_1) < $signed(input_2)) ? {{31{1'b0}},1'b1} : {32{1'b0}};	//SLT
			6'b101011:	ALU_output = (input_1 < input_2) ? {{31{1'b0}},1'b1} : {32{1'b0}};						//SLTU
			default:	ALU_output = {32{1'bx}}; 								//Not a recognised operation
		endcase
	end
endmodule