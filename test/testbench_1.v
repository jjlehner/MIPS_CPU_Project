module mips_cpu_bus_tb;
    timeunit 1ns / 10ps;


    parameter TIMEOUT_CYCLES = 10000;

    reg clk;
    reg rst;

    wire active;
    wire[31:0] register_v0;

    wire[31:0] address;
    wire write;
    wire read;
    wire[31:0] writedata;
    reg[31:0] readdata;

// what ram are we using
    
    mips_cpu_bus cpuInst(clk, reset, active, register_v0, address, write, read, waitrequest, writedata, byteenable, readdata);

    // Generate clock
    initial begin
        clk <= 0;

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
