`define PIPELINED true
module Register_File(	
	input	logic 			clk,
	input 	logic 			pipelined,
	input 	logic			write_enable,
	input	logic [4:0]		read_address_1, read_address_2, write_address,
	input	logic [31:0]	write_data,
	output	logic [31:0]	read_data_1,read_data_2
);
	
	logic [31:0] registers[31:0];

	//Combinational read of register file 

	//Register 0 is hard wired to zero so sourcing output from that register
	//should always produce zero
	assign read_data_1 = (read_address_1 != 0) ? registers[read_address_1] : 0;
	assign read_data_2 = (read_address_2 != 0) ? registers[read_address_2] : 0;

	//If the register file is pipelined, the register file should be updated on
	//the negative clock edge rather than the positive clock edge. A bitwise xor
	//acts like a controllable not gate, allowing the module to be set whether
	//it is being pipelined or not
	logic modified_write_clk;
	assign modified_write_clk = clk ^ pipelined;
	always_ff @(posedge modified_write_clk) begin
		if(write_enable) registers[write_address]<= write_data;
	end
endmodule