/* moduledoc



*/

`include "rtl/memory/sdram/sdram_bank.vh"

module sdram_block (
    input clock,
    input clock_enable,
    input wr_en,
    input [12:0] column_address,
    input  [1:0] bank_address,
    inout [31:0] rw_data
  );

  sdram_bank bank_0 (
    .clock(clock)
  );
  
  sdram_bank bank_1 (

  );

  sdram_bank bank_2 (

  );

  sdram_bank bank_3 (

  );

  always_ff @(posedge clock) begin

  end
  

endmodule