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
    output logic[3:0] byteenable, // Not needed as this is done in cache?
    input logic[31:0] readdata
  );

  logic cpu_enable, wr_en, re_en;
  logic[31:0] instr_ad, instr_rd, data_ad, data_rd;
  
  // Is this right? I feel like it'd work but will vastly restrict speed
  // by only running the CPU when the data is requested from the cache
  // ie. only about half the time

  assign cpu_enable = ~waitrequest;

  // In this setup it will try and fetch instructions on the posedge of the clock and r/w data on the negedge
  // This can easily be changed but should lead to a slight speedup?

  always @(posedge clk) if (!waitrequest) `do (
    address <= instr_ad;
    read <= 1;
    @(negedge waitrequest);
    read <= 0;
    instr_rd <= readdata;
  )

  always @(negedge clk) if (!waitrequest) `do (
    if (re_en) `do (
      address <= read_ad;
      read <= 1;
      @(negedge waitrequest);
      read <= 0;
      data_rd <= readdata;
    )
    if (wr_en) `do (
      address <= write_ad;
      write <= 1;
      @(negedge waitrequest);
      write <= 0;
    )
  )
  
  mips_cpu cpu (
    .clk(clk),
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
