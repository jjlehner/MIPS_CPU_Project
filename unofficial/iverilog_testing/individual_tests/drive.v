module drive();

	logic clk;
	logic Rt_decode;
	logic Rt_execute;
	logic reset;
	Decode_Execute_Register decode_execute_register(
		.reset(reset),
		.clk(clk),
		.Rt_decode(Rt_decode),
		.Rt_execute(Rt_execute),
		.clear(1'b0)
	);
	
	initial begin
		$dumpfile("out.vcd");
	    $dumpvars(0, drive);
		#1;
		clk=1;
		#1;
		clk=0;
		reset = 1;
		#1;
		clk=1;
		#1;
		reset =0;
		clk=0;
		#1;
		clk=1;
		#1;
		Rt_decode = 5'h1;

		clk=0;
		#1;
		clk=1;
		#1;
		clk=0;
		#1;
		clk = 1;
		#0;
		clk = 0;
		#1;
		clk = 1;
		#0;
		clk = 0;
		#1;
		clk = 1;
		#0;
		clk = 0;
		#1;
		clk = 1;
		#0;
		clk = 0;
		#1;
		clk = 1;
		#0;
		clk = 0;

	end
endmodule