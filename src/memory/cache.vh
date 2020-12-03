//`include "src/memory/util.vh"
`include "util.vh"
/*
  I've done [weird amount] of cache presently however this is easy to change.
  I need to look more into what an optimal amount is.
  
  Block: Tag: 18 bits, word: 32 bits
  Set:   4 blocks
  Cache: 4096 Sets
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
  logic miss = 0;
  logic[3:0][49:0] cache[4095:0]; // We can change size easily enough, size is weird because tag...
  wire[11:0] cache_address;
  wire [1:0] offset;
  wire[17:0] tag;
  
  // Signals from CPU interface //
  //logic cpu_write, cpu_read, cpu_wait;
  // more to come
  
  assign offset = address[1:0];
  assign cache_address = address[13:2]; // address % 12 ignoring offset
  assign tag = address[31:14];

  always @(posedge write) `do (
    $display("writing %h to %h, tag: %h", writedata, address, tag);
    waitrequest <= 1;
    cache[cache_address][3] <= cache[cache_address][2];
    cache[cache_address][2] <= cache[cache_address][1];
    cache[cache_address][1] <= cache[cache_address][0];
    cache[cache_address][0] <= {tag, writedata};
    $display("Wrote %h to cache", cache[cache_address][0]);
    waitrequest <= 0;
  )

  always @(posedge read) `do (
    $display("reading %h, looking for %h", address, tag);
    waitrequest <= 1;
    readdata <= cache[cache_address][0][49:32] == tag?
      cache[cache_address][0][31:0] : cache[cache_address][1][49:32] == tag?
      cache[cache_address][1][31:0] : cache[cache_address][2][49:32] == tag?
      cache[cache_address][2][31:0] : cache[cache_address][3][49:32] == tag?
      cache[cache_address][0][31:0] : 50'hz;
    miss <= readdata == 50'hz;
    waitrequest <= 0;
  )
  
  always @(posedge miss) `do (
    $display("miss on %h", address);
    // Look in RAM for read address
  )
endmodule