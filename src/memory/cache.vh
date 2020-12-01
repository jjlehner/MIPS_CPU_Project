`include "src/memory/utils.vh"

/*
  I've done 4kB of cache presently however this is easy to change.
  I need to look more into whjat an optimal amount is.
  
  Word size: 32 bits/4 bytes (it just makes sense)
  Block Size: ???
  Cache Size: ???
*/

module cache (
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

  logic[31:0][0:0] l1_cache[0:0];
  

  

endmodule