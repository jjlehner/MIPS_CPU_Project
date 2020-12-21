`define PIPELINED true
module Register_File(	
	input	logic 			clk, HALT_writeback,
	input 	logic 			pipelined, reset,
	input 	logic			write_enable,	HI_write_enable, LO_write_enable,
	input	logic [4:0]		read_address_1, read_address_2, write_address,
	input	logic [31:0]	write_data,		HI_write_data,	LO_write_data,
	output	logic [31:0]	read_data_1,	read_data_2,
	output	logic [31:0]	read_data_LO,	read_data_HI,
	output	logic [31:0]	read_register_2,
	// output	logic [31:0] 	registers_out_0_DELETE_ME,
	// output	logic [31:0] 	registers_out_1_DELETE_ME,
	// output	logic [31:0] 	registers_out_2_DELETE_ME,
	// output	logic [31:0] 	registers_out_3_DELETE_ME,
	output	logic [31:0] 	registers_out_4_DELETE_ME,
	output	logic [31:0] 	registers_out_5_DELETE_ME,
	output	logic [31:0] 	registers_out_6_DELETE_ME
	// output	logic [31:0] 	registers_out_7_DELETE_ME,
	// output	logic [31:0] 	registers_out_8_DELETE_ME,
	// output	logic [31:0] 	registers_out_9_DELETE_ME,
	// output	logic [31:0] 	registers_out_10_DELETE_ME,
	// output	logic [31:0] 	registers_out_11_DELETE_ME,
	// output	logic [31:0] 	registers_out_12_DELETE_ME,
	// output	logic [31:0] 	registers_out_13_DELETE_ME,
	// output	logic [31:0] 	registers_out_14_DELETE_ME,
	// output	logic [31:0] 	registers_out_15_DELETE_ME,
	// output	logic [31:0] 	registers_out_16_DELETE_ME,
	// output	logic [31:0] 	registers_out_17_DELETE_ME,
	//output	logic [31:0] 	registers_out_31_DELETE_ME
);
	
	logic [31:0] registers[31:0];
	// assign registers_out_0_DELETE_ME = registers[0];
	// assign registers_out_1_DELETE_ME = registers[1];
	// assign registers_out_2_DELETE_ME = registers[2];
	// assign registers_out_3_DELETE_ME = registers[3];
	assign registers_out_4_DELETE_ME = registers[4];
	assign registers_out_5_DELETE_ME = registers[5];
	assign registers_out_6_DELETE_ME = registers[6];
	// assign registers_out_7_DELETE_ME = registers[7];
	// assign registers_out_8_DELETE_ME = registers[8];
	// assign registers_out_9_DELETE_ME = registers[9];
	// assign registers_out_10_DELETE_ME = registers[10];
	// assign registers_out_11_DELETE_ME = registers[11];
	// assign registers_out_12_DELETE_ME = registers[12];
	// assign registers_out_13_DELETE_ME = registers[13];
	// assign registers_out_14_DELETE_ME = registers[14];
	// assign registers_out_15_DELETE_ME = registers[15];
	// assign registers_out_16_DELETE_ME = registers[16];
	// assign registers_out_17_DELETE_ME = registers[17];
	//assign registers_out_31_DELETE_ME = registers[31];

	logic [31:0] HI_reg, LO_reg;

	//Combinational read of register file 
	//Register 0 is hard wired to zero so sourcing output from that register
	//should always produce zero
	
	assign read_data_LO = LO_reg;
	assign read_data_HI = HI_reg;
	assign read_register_2 = registers[2];
	//If the register file is pipelined, the register file should be updated on
	//the negative clock edge rather than the positive clock edge. A bitwise xor
	//acts like a controllable not gate, allowing the module to be set whether
	//it is being pipelined or not
	logic modified_write_clk;
	assign modified_write_clk = clk ^ pipelined;
	always_comb begin
		if(read_address_1 != 0) read_data_1 = registers[read_address_1];
		else read_data_1 = 0;
		if(read_address_2 != 0) read_data_2 = registers[read_address_2];
		else read_data_2 = 0;
	end
	always_ff @(posedge modified_write_clk, posedge reset) begin
		if(reset) begin
			for(int i = 0; i < 32; i++) begin
				registers[i] <= 32'h0;
			end
			LO_reg <= 0;
			HI_reg <= 0;
		end
		else begin
			if(write_enable && !HALT_writeback) registers[write_address]<= write_data;
			if(HI_write_enable) begin
				HI_reg <= HI_write_data;
			end
			if(LO_write_enable) begin
				LO_reg <= LO_write_data;
			end
		end
	end
endmodule