module mips_cpu_bus_tb_delay1;

	parameter VCD_FILE = "out.vcd";

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
    logic [31:0] test;
    RAM_32x2048_delay1 #(RAM_INIT_FILE) raminst(
        .clk(clk), 
        .address(address), 
        .write(write),
        .read(read),
        .writedata(writedata),
        .readdata(readdata),
        .waitrequest(waitrequest),
        .test(test),
        .byteenable(byteenable)
    );
    
    mips_cpu_bus cpuInst(clk, rst, active, register_v0, address, write, read, waitrequest, writedata, byteenable, readdata);

    // Generate clock
    initial begin
        $display("PARAMATER RAM_INIT_FILE ------- %S",RAM_INIT_FILE);
        $dumpfile(VCD_FILE);
	    $dumpvars(0, mips_cpu_bus_tb_delay1);
        clk = 0;

        repeat (TIMEOUT_CYCLES) begin
            #1;
            clk = !clk;
            #1;
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
        $display("%0d",register_v0);

        $finish;
        
    end
    

endmodule
