module Hazard_Unit(
	input	logic 		branch_decode,
	input	logic [4:0]	Rs_decode,
	input	logic [4:0]	Rt_decode,
	input	logic [4:0]	Rs_execute,
	input	logic [4:0]	Rt_execute,
	input	logic [4:0]	write_register_execute,
	input	logic		memory_to_register_execute,
	input	logic		register_write_execute,
	input	logic [4:0]	write_register_memory,
	input	logic 		memory_to_register_memory,
	input	logic		register_write_memory,
	input	logic [4:0]	write_register_writeback,
	input	logic		register_write_writeback,
	input	logic		program_counter_multiplexer_jump_memory,
	input	logic		HI_register_write_memory,
	input	logic		LO_register_write_memory,
	input	logic		LO_register_write_writeback,
	input	logic		HI_register_write_writeback,
	input	logic		using_HI_LO_execute,
	input	logic		program_counter_jalr_control_memory,

	output	logic 		stall_fetch,
	output	logic 		stall_decode,
	output	logic 		forward_register_file_output_A_decode,
	output	logic 		forward_register_file_output_B_decode,
	output	logic 		flush_execute_register,
	output	logic [2:0] forward_register_file_output_A_execute,
	output	logic [2:0] forward_register_file_output_B_execute,
	output	logic 		flush_decode_register
);

	logic lwstall;
	logic branchstall;

	always_comb begin
		//Forwarding data hazards
		if ((Rs_execute !=0) && (Rs_execute == write_register_memory) && register_write_memory) begin		
			forward_register_file_output_A_execute = 3'b010;
		end else if(using_HI_LO_execute && LO_register_write_memory) begin
			forward_register_file_output_A_execute = 3'b100;
		end else if ((Rs_execute !=0) && (Rs_execute == write_register_writeback) && register_write_writeback) begin
			forward_register_file_output_A_execute = 3'b001;
		end else if (using_HI_LO_execute && LO_register_write_writeback ) begin
			forward_register_file_output_A_execute = 3'b011;
		end else begin
			forward_register_file_output_A_execute = 3'b000;
		end

		if ((Rt_execute !=0) && (Rt_execute == write_register_memory) && register_write_memory) begin		
			forward_register_file_output_B_execute = 3'b010;
		end else if (using_HI_LO_execute && HI_register_write_memory) begin		
			forward_register_file_output_B_execute = 3'b100;
		end else if ((Rt_execute !=0) && (Rt_execute == write_register_writeback) && register_write_writeback) begin
			forward_register_file_output_B_execute = 3'b001;
		end else if (using_HI_LO_execute && HI_register_write_writeback) begin
			forward_register_file_output_B_execute = 3'b011;
		end else begin
			forward_register_file_output_B_execute = 3'b000;
		end
		//^^^^^^^^^^^^^^^^^^^

		//Data hazards solvable by stalls
		lwstall = ((Rs_decode == Rt_execute) || (Rt_decode == Rt_execute)) && memory_to_register_execute;

		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

		//Controls hazards solvable by stalls
		forward_register_file_output_A_decode = (Rs_decode != 0) && (Rs_decode == write_register_memory) && register_write_memory;
		forward_register_file_output_B_decode = (Rt_decode != 0) && (Rt_decode == write_register_memory) && register_write_memory;

		branchstall = branch_decode && register_write_execute && (write_register_execute == Rs_decode || write_register_execute == Rt_decode) || branch_decode && memory_to_register_memory && (write_register_memory == Rs_decode || write_register_memory == Rt_decode);
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

		stall_fetch = branchstall || lwstall;
		stall_decode = branchstall || lwstall;
		flush_decode_register = program_counter_multiplexer_jump_memory || program_counter_jalr_control_memory;
		flush_execute_register = branchstall || lwstall || program_counter_multiplexer_jump_memory || program_counter_jalr_control_memory;
	

	end
endmodule