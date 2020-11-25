/* moduledoc



*/

`include "rtl/memory/sdram/sdram_bank.vh"

module sdram_block (
    input clock,
    input wr_en,
    input [12:0] column_address,
    input  [1:0] bank_address,
    inout [31:0] rw_data
  );

  .wire wr_en_0, wr_en_1, wr_en_2, wr_en_3;

  sdram_bank bank_0 (
    .clock(clock),
    .write_enable(wr_en_0)
  );
  
  sdram_bank bank_1 (
    .clock(clock),
    .write_enable(wr_en_1)
  );

  sdram_bank bank_2 (
    .clock(clock),
    .write_enable(wr_en_2)
  );

  sdram_bank bank_3 (
    .clock(clock),
    .write_enable(wr_en_3)
  );

  always @(bank_address) begin
    // Somehow force a block-wide delay of 140 timesteps here
  end

  always_ff @(posedge clock) begin

  end
  

endmodule