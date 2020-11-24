module Hazard_Unit(
	input	logic 		branch_decode,
	input	logic [4:0]	Rs_decode,
	input	logic [4:0]	Rt_decode,
	input	logic [4:0]	Rs_encode,
	input	logic [4:0]	Rt_encode,
	input	logic [4:0]	write_register_execute,
	input	logic		memory_to_register_execute,
	input	logic		register_write_execute,
	input	logic [4:0]	write_register_memory,
	input	logic 		memory_to_register_memory,
	input	logic		register_write_memory,
	input	logic [4:0]	write_register_writeback,
	input	logic		register_write_writeback,

	output	logic 		stall_fetch,
	output	logic 		stall_decode,
	output	logic 		forward_register_file_output_1_decode,
	output	logic 		forward_register_file_output_2_decode,
	output	logic 		flush_execution_register,
	output	logic [1:0] forward_register_file_output_1_execution,
	output	logic [1:0] forward_register_file_output_2_execution
);

	logic lwstall;
	logic branchstall;

	always_comb begin
		//Forwarding data hazards
		if ((Rs_encode !=0) && (Rs_encode == write_register_memory) && register_write_memory) begin		
			forward_register_file_output_1_execution = 2'b10;
		end else if ((Rs_encode !=0) && (Rs_encode == write_register_writeback) && register_write_writeback) begin
			forward_register_file_output_1_execution = 2'b01;
		end else begin
			forward_register_file_output_1_execution = 2'b00;
		end

		if ((Rt_encode !=0) && (Rt_encode == write_register_memory) && register_write_memory) begin		
			forward_register_file_output_2_execution = 2'b10;
		end else if ((Rt_encode !=0) && (Rt_encode == write_register_writeback) && register_write_writeback) begin
			forward_register_file_output_2_execution = 2'b01;
		end else begin
			forward_register_file_output_2_execution = 2'b00;
		end
		//^^^^^^^^^^^^^^^^^^^

		//Data hazards solvable by stalls
		lwstall = ((Rs_decode == Rt_encode) || (Rt_decode == Rt_encode)) && memory_to_register_execute;

		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

		//Controls hazards solvable by stalls
		forward_register_file_output_1_decode = (Rs_decode != 0) && (Rs_decode == write_register_memory) && register_write_memory;
		forward_register_file_output_2_decode = (Rt_decode != 0) && (Rt_decode == write_register_memory) && register_write_memory;

		branchstall = branch_decode && register_write_execute && (write_register_execute == Rs_decode || write_register_execute == Rt_decode) || branch_decode && memory_to_register_memory && (write_register_memory == Rs_decode || write_register_memory == Rt_decode);
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

		stall_fetch = branchstall || lwstall;
		stall_decode = branchstall || lwstall;
		flush_execution_register = branchstall || lwstall;

	end
endmodule