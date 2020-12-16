//TODO should probably remove dependency on byteenable and do case statement on address
module Memory_Filter(
	input	logic [5:0] op_writeback,
	input	logic [3:0] byteenable_writeback,
	input	logic [31:0] src_A_writeback,
	input	logic [31:0] read_data_writeback,
	input	logic reset,
	output	logic [31:0] filtered_output_writeback
);
	logic [31:0] temp_filtered;
	always_comb begin
		if(reset) begin
			filtered_output_writeback = 0;
		end else begin
			case(op_writeback)
				6'b100000 : begin //LB
					case(byteenable_writeback)
						4'b0001 : temp_filtered = read_data_writeback;
						4'b0010 : temp_filtered = read_data_writeback >> 8;
						4'b0100 : temp_filtered = read_data_writeback >> 16;
						4'b1000 : temp_filtered = read_data_writeback >> 24;
						default : temp_filtered = read_data_writeback;
					endcase
					temp_filtered = {{24{temp_filtered[7]}},temp_filtered[7:0]};
				end
				6'b100100 : begin //Load Byte Unsigned
					case(byteenable_writeback)
						4'b0001 : temp_filtered = read_data_writeback;
						4'b0010 : temp_filtered = read_data_writeback >> 8;
						4'b0100 : temp_filtered = read_data_writeback >> 16;
						4'b1000 : temp_filtered = read_data_writeback >> 24;
						default : temp_filtered = read_data_writeback;
					endcase
					temp_filtered = {{24{1'b0}},temp_filtered[7:0]};
				end
				6'b100001 : begin //Load Half-Word
					temp_filtered = {{16{read_data_writeback[15]}},read_data_writeback[15:0]};
				end
				6'b100101 : begin //Load Half-Word Unsigned
					temp_filtered = {{16{1'b0}},read_data_writeback[15:0]};
				end
				6'b100010 : begin //Load word left
					case(byteenable_writeback)
						4'b0001 : temp_filtered = {read_data_writeback[7:0], src_A_writeback[23:0]};
						4'b0011 : temp_filtered = {read_data_writeback[15:0], src_A_writeback[15:0]};
						4'b0111 : temp_filtered = {read_data_writeback[23:0], src_A_writeback[7:0]};
						4'b1111 : temp_filtered = read_data_writeback;
						default : temp_filtered = read_data_writeback;
					endcase
				end
				6'b100110 : begin //Load word right
					case(byteenable_writeback)
						4'b1111 : temp_filtered = read_data_writeback;
						4'b1110 : temp_filtered = {src_A_writeback[31:24],read_data_writeback[31:8]};
						4'b1100 : temp_filtered = {src_A_writeback[31:16],read_data_writeback[31:16]};
						4'b1000 : temp_filtered = {src_A_writeback[31:8],read_data_writeback[31:24]};
						default : temp_filtered = read_data_writeback;
					endcase
				end
				default : begin
					temp_filtered = read_data_writeback;
				end
			endcase
			filtered_output_writeback = temp_filtered;
		end
	end

endmodule