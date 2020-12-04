`include "cache.vh"
`include "util.vh"

module cache_test ();
  /* Standard signals */
  logic clk;

  /* Avalon memory mapped bus controller (master) */
  logic[31:0] address;
  logic write;
  logic read;
  wire waitrequest;
  logic[31:0] writedata;
  logic[3:0] byteenable;
  wire[31:0] readdata;
  cache c(
    .clk(clk),
    .reset(reset),
    .active(active),
    .address(address),
    .write(write),
    .read(read),
    .waitrequest(waitrequest),
    .readdata(readdata),
    .writedata(writedata),
    .byteenable(byteenable)
  );

  always `do (
    clk = 0;
    #10;
    clk = 1;
    #10;
  )

  initial `do (
    address <= 32'hffff;
    writedata <= 32'habababab;
    write <= 1;
    @(negedge waitrequest);
    write <= 0;
    @(posedge clk);
    address <= 32'hfafafa;
    read <= 1;
    @(negedge waitrequest);
    read <= 0;
    $display("Read: %h", readdata);
    @(posedge clk);
    address <= 32'hffff;
    read <= 1;
    @(negedge waitrequest);
    read <= 0;
    $display("Read: %h", readdata);
    $finish;
  )

endmodule