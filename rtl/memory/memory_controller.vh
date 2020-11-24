/* moduledoc

  The memory controller has all of the memory.
  If you're impatient it tells u to wait.
  Legend has it that the clock ticks differently here.
  WELCOME TO MEMORY LAND, EST 2020

*/

`include "rtl/memory/sdram/sdram_block.vh"
`include "rtl/util.vh"


module memory_controller (
  input wr_en,
  input [31:0] read_address,
  input [31:0] write_address,
  input [31:0] write_data,
  output[31:0] wait_signal,
  output[31:0] read_data
  );

  ////////////////////////////////////////////////
  // Create a clock with a frequency of 135 MHz //
  ////////////////////////////////////////////////

  `clock_gen(37)

  
endmodule