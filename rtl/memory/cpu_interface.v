`include "src/memory/utils.vh"

module cpu_interface (
    /* Standard signals */
    input logic clk,
    input logic reset,
    output logic active,
    output logic[31:0] register_v0,

    /* Avalon memory mapped bus controller (master) */
    output logic[31:0] address,
    output logic write,
    output logic read,
    input logic waitrequest,
    output logic[31:0] writedata,
    output logic[3:0] byteenable,
    input logic[31:0] readdata
  );

  logic cpu_enable, wr_en, re_en;
  logic[31:0] instr_ad, instr_rd, data_ad, data_rd;
  
  // Is this right? I feel like it'd work but will vastly restrict speed
  // by only running the CPU when the data is requested from the cache
  // ie. only about half the time

  assign cpu_enable = ~waitrequest;
  
  

  /*
    Somehow I want to detect when the CPU wants something it can't
    have from memory and pause its clock cycle.

    Also do I use a mux here or just the if?

    We need to send a stall signal if we don't have an instruction ready
    
    Writing to memory takes priority as we may need this data for
    future instructions, unless we implement logic to predict this?

    My brain's telling me this will never send a clock to the CPU but
    at the same time I'm not sure?
  */
  /*
  always @(clk) if (!wait_request) `do (
    cpu_clock <= clk;
    if (wr_en) `do (
      // Write data
      address <= data_ad;
      write <= 1;
      read <= 0;
      @(negedge wait_request);
      write <= 0;
      // Get instruction
      address <= instr_address;
      read <= 1;
      write <= 0;
      @(negedge wait_request);
      instr_readdata <= readdata;
      read <= 0;
    ) else if (re_en) `do (
      // Get read data
      address <= data_ad;
      write <= 0;
      read <= 1;
      @(negedge wait_request);
      data_readdata <= readdata;
      // Get instruction
      address <= instr_address;
      @(negedge wait_request);
      instr_readdata <= readdata;
      read <= 0;
    ) else `do (
      // Get instruction
      address <= instr_address;
      read <= 1;
      write <= 0;
      @(negedge wait_request);
      instr_readdata <= readdata;
      read <= 0;
    )
  )
*/
  mips_cpu cpu (
    .clk(cpu_clock),
    .reset(reset),
    .active(active),
    .register_v0(register_v0),
    .instr_address(instr_ad),
    .instr_readdata(instr_rd),
    .data_address(data_ad),
    .data_write(wr_en),
    .data_read(re_en),
    .data_writedata(writedata),
    .data_readdata(data_rd)
  );

endmodule
