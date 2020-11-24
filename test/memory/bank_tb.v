`include "rtl/memory/sdram/sdram_bank.vh"
`include "rtl/util.vh"

module bank_tb();

  `clock_gen(50)
  
  reg wr_en, w_sig;
  reg[12:0] c_ad;
  reg[511:0][31:0] out_data;
  wire[511:0][31:0] row;

  sdram_bank bank (
    .clock(clock),
    .write_enable(wr_en),
    .wait_signal(w_sig),
    .column_address(c_ad),
    .row(row)
  );

  assign row = out_data;

  initial begin
    wr_en <= 1;
    out_data <= 63556'hfaceface;
    c_ad <= 13'b1010101010100;
    @(posedge clock);
    wr_en <= 0;
    @(posedge clock);
    c_ad <= 13'b1010101010100;
    @(posedge clock);
    $display("row after: %h", row);
    $finish;
  end

endmodule