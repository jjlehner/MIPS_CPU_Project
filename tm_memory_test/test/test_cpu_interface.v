module test_cpu_interface (
    // Standard
    input logic clk, reset, cpu_enable,
    output logic[31:0] register_v0,
    output logic active,
    output logic[31:0] instr_address, data_address, data_writedata,
    input logic[31:0] instr_readdata, data_readdata,
    output logic data_write, data_read
  );

  initial begin
    data_read = 1;
    instr_address <= 32'h04;
    data_address <= 32'hffff0004;
    active <= 1;
  end

  integer i = 0;

  always @(posedge clk) if (cpu_enable === 1) begin

    i = i + 1;

    if (i === 100) begin
     $finish;
    end
    if (i % 2 === 0) begin
      $display("read (inst) %h, write (data) %h", instr_address, data_address);
      data_read = 0;
      data_write = 1;
      data_writedata = data_readdata;
    end else begin
      $display("read (inst) %h, read (data) %h", instr_address, data_address);
      data_write = 0;
      data_read = 1;
    end

    @(posedge cpu_enable);

    if (instr_address == 32'h2C) begin
      instr_address = 32'h4;
    end else begin
      instr_address = instr_address + 4;
    end

    if (i % 2 == 1) 
      if (data_address == 32'hffff001C) begin
        data_address = 32'hffff0004;
      end else begin
        data_address = data_address + 4;
      end
    end


    $display("instruction: %h", instr_readdata);
    $display("data: %h", data_readdata);
  end
endmodule
