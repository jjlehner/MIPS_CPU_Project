module mips_cpu_bus_tb_delay0;
    timeunit 1ns / 10ps;

    parameter RAM_INIT_FILE = "datamem.txt";
    parameter TIMEOUT_CYCLES = 10000;

	reg clk;
	/* verilator lint_off UNUSED */
	reg reset;
	/* verilator lint_off UNDRIVEN */
	wire active;
	wire [31:0] register_v0;

	/* New clock enable. See below. */
	reg clk_enable;

	/* Combinatorial read access to instructions */
	wire[31:0]  instr_address;
	reg[31:0]   instr_readdata;

	/* Combinatorial read and single-cycle write access to instructions */
	wire[31:0] data_address;
	wire data_write;
	wire data_read;
	wire[31:0] data_writedata;
	reg[31:0] data_readdata;

    RAM_32x2048_delay0 #(RAM_INIT_FILE) raminst(clk, instr_address, instr_readdata, data_address, data_write, data_read, data_writedata, data_readdata);

    
    mips_cpu_harvard cpuInst(clk, reset, active, register_v0, clk_enable, instr_address, instr_readdata, data_address, data_write, data_read, data_writedata, data_readdata);

    // Generate clock
    initial begin
	$dumpfile("mips_cpu_bus_tb_delay0_waves.vcd");
	$dumpvars(0, mips_cpu_bus_tb_delay0);

        clk = 0;

        repeat (TIMEOUT_CYCLES) begin
            #10;
            clk = !clk;
            #10;
            clk = !clk;
        end

        $fatal(2, "Simulation did not finish within %d cycles.", TIMEOUT_CYCLES);
    end

    initial begin
        reset <= 0;

        @(posedge clk);
        reset <= 1;

        @(posedge clk);
        reset <= 0;

        @(posedge clk);
        assert(active==1)
        else $display("TB : CPU did not set active=1 after reset.");

        while (active) begin
            @(posedge clk);
        end

        $display("TB : finished; active=0");

        $finish;
        
    end
    

endmodule
