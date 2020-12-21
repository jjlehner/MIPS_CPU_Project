//TODO should probably remove dependency on byteenable and do case statement on address
module Memory_Filter(
	input	logic [5:0] op_writeback,
	input	logic [3:0] byteenable_writeback,
	input	logic [31:0] src_A_writeback,
	input	logic [31:0] src_B_writeback,
	input	logic [31:0] read_data_writeback,
	input	logic reset,
	output	logic [31:0] filtered_output_writeback
);
	always_comb begin
		if(reset) begin
			filtered_output_writeback = 0;
		end else begin
			case(op_writeback)
				6'b100000 : begin //LB
					case(byteenable_writeback)
						4'b0001 : filtered_output_writeback = {{24{read_data_writeback[7]}},read_data_writeback[7:0]};
						4'b0010 : filtered_output_writeback = {{24{read_data_writeback[15]}},read_data_writeback[15:8]};
						4'b0100 : filtered_output_writeback = {{24{read_data_writeback[23]}},read_data_writeback[23:16]};
						4'b1000 : filtered_output_writeback = {{24{read_data_writeback[31]}},read_data_writeback[31:24]};
						default : filtered_output_writeback = read_data_writeback;
					endcase
				end
				6'b100100 : begin //Load Byte Unsigned
					case(byteenable_writeback)
						4'b0001 : filtered_output_writeback = {{24{1'b0}},read_data_writeback[7:0]};
						4'b0010 : filtered_output_writeback = {{24{1'b0}},read_data_writeback[15:8]};
						4'b0100 : filtered_output_writeback = {{24{1'b0}},read_data_writeback[23:16]};
						4'b1000 : filtered_output_writeback = {{24{1'b0}},read_data_writeback[31:24]};
						default : filtered_output_writeback = read_data_writeback;
					endcase
				end
				6'b100001 : begin //Load Half-Word
					case(byteenable_writeback)
						4'b0011 : filtered_output_writeback = {{16{read_data_writeback[15]}},read_data_writeback[15:0]};
						4'b1100 : filtered_output_writeback = {{16{read_data_writeback[31]}}, read_data_writeback[31:16]};
						default : filtered_output_writeback = read_data_writeback;
					endcase
				end
				6'b100101 : begin //Load Half-Word Unsigned
					case(byteenable_writeback)
						4'b0011 : filtered_output_writeback = {{16{1'b0}},read_data_writeback[15:0]};
						4'b1100 : filtered_output_writeback = {{16{1'b0}},read_data_writeback[31:16]};
						default : filtered_output_writeback = read_data_writeback;
					endcase
				end
				6'b100010 : begin //Load word left
					case(byteenable_writeback)
						4'b0001 : filtered_output_writeback = {read_data_writeback[7:0], src_B_writeback[23:0]};
						4'b0011 : filtered_output_writeback = {read_data_writeback[15:0], src_B_writeback[15:0]};
						4'b0111 : filtered_output_writeback = {read_data_writeback[23:0], src_B_writeback[7:0]};
						4'b1111 : filtered_output_writeback = read_data_writeback;
						default : filtered_output_writeback = read_data_writeback;
					endcase
				end
				6'b100110 : begin //Load word right
					case(byteenable_writeback)
						4'b1111 : filtered_output_writeback = read_data_writeback;
						4'b1110 : filtered_output_writeback = {src_B_writeback[31:24],read_data_writeback[31:8]};
						4'b1100 : filtered_output_writeback = {src_B_writeback[31:16],read_data_writeback[31:16]};
						4'b1000 : filtered_output_writeback = {src_B_writeback[31:8],read_data_writeback[31:24]};
						default : filtered_output_writeback = read_data_writeback;
					endcase
				end
				default : begin
					filtered_output_writeback = read_data_writeback;
				end
			endcase
		end
	end

endmodule