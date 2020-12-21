module cpu_interface (
    /* Standard signals */
    input logic clk,
    input logic reset,
    output logic active,
    output logic[31:0] register_v0,

    /* Avalon memory mapped bus controller (master) */
    output logic[31:0] address,
    output logic write = 0,
    output logic read = 0,
    input logic waitrequest,
    output logic[31:0] writedata,
    input logic[31:0] readdata
  );

  logic cpu_enable = 1;
  logic wr_en, re_en;
  logic[31:0] instr_ad, instr_rd, data_ad, data_rd;

  always @(posedge clk) if (cpu_enable) `do (
    cpu_enable <= 0;
    address <= instr_ad;
    read <= 1;
    @(negedge waitrequest);
    read <= 0;
    instr_rd <= readdata;
    if (re_en === 1) begin
      address <= data_ad;
      read <= 1;
      @(negedge waitrequest);
      read <= 0;
      data_rd = readdata;
    end
    if (wr_en === 1) begin
      address <= data_ad;
      write <= 1;
      @(negedge waitrequest);
      write <= 0;
    end
    cpu_enable <= 1;
  )
/*  mips_cpu cpu (
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
  );*/
  
  test_cpu_interface cpu (
    .clk(clk),
    .reset(reset),
    .active(active),
    .cpu_enable(cpu_enable),
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
