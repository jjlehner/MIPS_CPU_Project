/* moduledoc

*/

`timescale 100ps/1ps

`include "rtl/controller/control.vh"
`include "rtl/datapath/datapath.vh"
`include "rtl/memory/memory_controller.vh"
`include "rtl/util.vh"

module mips (

  );
  
  //////////////////////////////////////////////////////////////////
  // Create a 30MHz clock. Each clock cycle will be 330 timesteps //
  //////////////////////////////////////////////////////////////////

  `clock_gen(165)

endmodule