`include "rtl/cache.v"

module test_cache();
  // Standard
  logic clk, reset, active;
  logic[31:0] register_v0;
  
  // Avalon
  logic[31:0] address, writedata, readdata;
  logic read, write, waitrequest = 0;
  logic[3:0] byteenable;
 
  initial forever begin
    $display("time: %d", $time/20);
    clk = 0;
    #10;
    clk = 1;
    #10;
  end

  always @(posedge clk) if (~waitrequest) begin
    if (read) begin
      waitrequest <= 1;
      case(address)
        32'h4: readdata <= 32'h1234;
        32'h8: readdata <= 32'h4321;
        32'hC: readdata <= 32'h12344321;
        32'h10: readdata <= 32'h43211234;
        32'h14: readdata <= 32'h123;
        32'h18: readdata <= 32'h3210;
        32'h1C: readdata <= 32'hfffffff0;
        32'h20: readdata <= 32'hfdfdfdfd;
        32'h24: readdata <= 32'hfa0fa0ff;
        32'h28: readdata <= 32'hfaceface;
        32'h2C: readdata <= 32'haceeeeee;
        32'hffff0004: readdata <= 32'h11001001;
        32'hffff0008: readdata <= 32'h22222222;
        32'hffff000C: readdata <= 32'h33332211;
        32'hffff0010: readdata <= 32'h321321ff;
        32'hffff0014: readdata <= 32'h23890831;
        32'hffff0018: readdata <= 32'hf3193011;
        32'hffff001C: readdata <= 32'hccacc123;
        default: readdata <= 32'hz;
      endcase
      waitrequest <= 0;

    end if (write) begin
      waitrequest <= 1;
      $display("let's all pretend %h was written to ram at address %h", writedata, address);
      waitrequest <= 0;
    end
  end

  cache c (
    .clk(clk),
    .reset(reset),
    .active(active),
    .register_v0(register_v0),
    .address(address),
    .write(write),
    .read(read),
    .waitrequest(waitrequest),
    .writedata(writedata),
    .byteenable(byteenable),
    .readdata(readdata)
  );
endmodule
