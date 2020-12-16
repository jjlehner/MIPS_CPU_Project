module mips_cpu_bus_tb_delay1;
    timeunit 1ns / 10ps;

    parameter RAM_INIT_FILE = "datamem.txt";
    parameter TIMEOUT_CYCLES = 10000;

    reg clk;
    reg rst;
    wire active;
    wire[31:0] register_v0;

    wire[31:0] address;
    wire write;
    wire read;
    reg waitrequest;
    wire[31:0] writedata;
    wire[3:0] byteenable;
    reg[31:0] readdata;

    RAM_32x2048_delay1 #(RAM_INIT_FILE) raminst(clk, address, write, read, writedata, readdata, waitrequest);
    
    mips_cpu_bus cpuInst(clk, rst, active, register_v0, address, write, read, waitrequest, writedata, byteenable, readdata);

    // Generate clock
    initial begin
        $dumpfile("mips_cpu_bus_tb_delay1_waves.vcd");
	    $dumpvars(0, mips_cpu_bus_tb_delay1);
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
        rst <= 0;

        @(posedge clk);
        rst <= 1;

        @(posedge clk);
        rst <= 0;

        @(posedge clk);
        assert(active==1)
        else $display("TB : CPU did not set active=1 after reset.");

        while (active) begin
            @(posedge clk);
        end

        $display("TB : finished; running=0");

        $finish;
        
    end
    

endmodule
