//SHAMT will be routed to the ALU via input_1
module ALU
(
	input					clk,
	input	logic [2:0]		fetch_state,

	input 	logic [5:0]		ALU_operation,
	input 	logic [31:0]	input_1,
	input	logic [31:0]	input_2,
	input	logic			reset,

	output	logic [31:0]	ALU_output,
	output	logic [31:0]	ALU_HI_output,
	output	logic [31:0]	ALU_LO_output,
	output	logic			ALU_STALL
);
	logic [4:0]  shift_amount;
	assign shift_amount = input_1[4:0];

	logic mult_start;
	logic mult_start_enable;

	logic [31:0] temp_HI_mult;
	logic [31:0] temp_LO_mult;
	logic [31:0] temp_HI_div;
	logic [31:0] temp_LO_div;

	logic [1:0] HI_LO_driven_by;
	// logic [31:0] temp_HI_div;
	// logic [31]

	logic temp_STALL;
	assign ALU_STALL = temp_STALL;

	always_latch begin
		if(!clk) begin
			mult_start_enable = mult_start && (fetch_state == 3'b010 || fetch_state == 3'b110);
		end
	end

	multiplier mult(
		.clk(clk),
		.start(clk&mult_start_enable),
		.input_1(input_1),
		.input_2(input_2),
		.hi_output(temp_HI_mult),
		.lo_output(temp_LO_mult),
		.stall(temp_STALL),
		.reset(reset)
	);


	always_comb begin
		ALU_output = {32{1'bx}};
		mult_start = 0;
		HI_LO_driven_by = 0;
		case(ALU_operation)
			6'b000000: 	ALU_output = input_2 << shift_amount; 					//SLL
			6'b000010:	ALU_output = input_2 >> shift_amount; 					//SRL
			6'b000011: 	ALU_output = input_2 >>> shift_amount;					//SRA
			6'b000100:	ALU_output = input_2 <<	input_1;					//SLLV
			6'b000110: 	ALU_output = input_2 >> input_1;					//SRLV
			6'b000111: 	ALU_output = input_2 >>> input_1;					//SRAV
			6'b001000:	ALU_output = input_2; 									//JR
			6'b001001:	ALU_output = input_2;									//JALR
			6'b010000:	ALU_output = input_2;									//MFHI TODO Some thing wrong here
			6'b010001:	HI_LO_driven_by = 2'b10;									//MTHI
			6'b010010:	ALU_output = input_1;									//MFLO
			6'b010011:	HI_LO_driven_by = 2'b10;									//MTLO
			6'b011000:	mult_start = 1;	//MULT	
			6'b011001:	mult_start = 1;											//MULTU
			//6'b011010:	mult_start = 1;
			// 6'b011011: 	begin													//DIVU
			// 	ALU_HI_LO_output = {input_1 / input_2, {32{1'b0}}};		
			// 	ALU_HI_LO_output = ALU_HI_LO_output + {{32{1'b0}},input_1 % input_2};
			// end
			6'b100000: 	ALU_output = $signed(input_1) + $signed(input_2);		//ADD
			6'b100001:	ALU_output = input_1 + input_2;							//ADDU
			6'b100010:	ALU_output = $signed(input_1) - $signed(input_2);		//SUB
			6'b100011:	ALU_output = input_1 - input_2;							//SUBU
			6'b100100:	ALU_output = input_1 & input_2;							//AND
			6'b100101:	ALU_output = input_1 | input_2;							//OR
			6'b100110:	ALU_output = input_1 ^ input_2;						//XOR
			6'b100111:	ALU_output = ~(input_1|input_2);						//NOR
			6'b101010:	ALU_output = ($signed(input_1) < $signed(input_2)) ? {{31{1'b0}},1'b1} : {32{1'b0}};	//SLT
			6'b101011:	ALU_output = (input_1 < input_2) ? {{31{1'b0}},1'b1} : {32{1'b0}};						//SLTU
			6'b101100:	ALU_output = (input_2 << 16); //LUI
			//6'b111100:	ALU_HI_LO_output = {{32{1'b0}}, input_1};
			//6'b111101:	ALU_HI_LO_output = {input_1, {32{1'b0}}};
			6'b111110:  ALU_output = input_1;									//NOTE - Made up to allow values to flow through ALU unchanged from input_1
			6'b111111:	ALU_output = input_2;									//NOTE - Made up to allow values to flow through ALU unchanged from input_2.
			default:	ALU_output = {32{1'bx}}; 								//Not a recognised operation
		endcase

		case(HI_LO_driven_by)
			2'b00: begin
				ALU_HI_output = temp_HI_mult;
				ALU_LO_output = temp_LO_mult;
			end
			2'b01: begin
				ALU_HI_output = temp_HI_div;
				ALU_LO_output = temp_LO_div;
			end
			2'b10: begin
				ALU_HI_output = input_1;
				ALU_LO_output = input_1;
			end
			default :begin
				ALU_HI_output = 0;
				ALU_LO_output = 0;	
			end
		endcase
	end
endmodule