`include "src/memory/utils.vh"

/*
  I've done 4kB of cache presently however this is easy to change.
  I need to look more into whjat an optimal amount is.
  
  Word size: 8 bits/1 byte (it just makes sense)
  Block Size: 4 words
  Set Size: 4 Blocks
  Cache Size: 4096 Sets
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

  //  Cache signals //
  logic miss;
  logic[3:0][8:0] l1_cache[3:0][4095:0]; // We can change size easily enough
  wire[11:0] cache_address;
  wire [1:0] offset;
  wire[17:0] tag;
  
  // Signals from CPU interface //
  logic cpu_write, cpu_read, cpu_wait;
  // more to come
  
  assign offset = address[1:0];
  assign cache_address = address[13:2]; // address % 12 ignoring offset
  assign tag = address[31:14];

  always @(posedge cpu_write) `do (
    // Write to both cache and RAM
    // When to release wait_request?
    // I assume as soon as cache is done?
  )

  always @(posedge cpu_read) `do (
    // Look in cache for read address
  )
  
  always @(posedge miss) `do (
    // Look in RAM for read address
  )


  

endmodule