/* moduledoc



*/

`include "rtl/memory/sdram/sdram_block.vh"
`include "rtl/util.vh"


module memory_controller (
  input wr_en,
  input [31:0] read_address,
  input [31:0] write_addres,
  input [31:0] write_data,
  output[31:0] read_data
  );

  ////////////////////////////////////////////////
  // Create a clock with a frequency of 135 MHz //
  ////////////////////////////////////////////////

  `clock_gen(37)
  
  always @(posedge clock) begin
    
  end

endmodule