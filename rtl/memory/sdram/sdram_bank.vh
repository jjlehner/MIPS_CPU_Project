/* moduledoc

  A single 512MB bank of SDRAM (synchronous dynamic random access memory).  
  Rows have to be refreshed at least every 64ms or they DIE.  
  The time since a row was last refreshed is stored and if it reaches 1023 clock cycles, a wait signal is sent and the next row to refresh is refreshed.  
  1023 was chosen as 64ms/8192 = 1056 clock cycles & factoring in the time spent refreshing a row, a row must be refreshed every 1048 clock cycles or so, which is close to 1023. 1023 is simpler to detect logically than 1048 so it is used instead.
  A refresh cycle takes ~8 clock cycles.

*/

module sdram_bank(
    input clock,
    input write_enable,
    input[12:0] column_address,
    output reg wait_signal = 0,
    inout[511:0][31:0] row
  );

  //////////////////////////////////////////////////////////////////////////
  // Set up the registers which dicate when the memory is being refreshed //
  //////////////////////////////////////////////////////////////////////////
  
  reg [9:0] refresh_counter = 0;
  reg[12:0] next_refresh = 0;

  /////////////////////////////////////////
  // Set up the storage array of the ram //
  /////////////////////////////////////////

  reg[511:0][31:0] ram[8191:0];

  ///////////////////////////////////////////////////////////////////////////////
  // Because we have a single data port, we need to declare an output register //
  ///////////////////////////////////////////////////////////////////////////////

  logic[511:0][31:0] data_out;
  assign row = write_enable? 16384'bZ : data_out;

  //////////////////////////////////////////////////////////////////////
  // If the ram is not "busy", either update it or send the read data //
  //////////////////////////////////////////////////////////////////////

  always @(posedge clock) begin
    if (~wait_signal) begin
      if (write_enable) begin
        ram[column_address] <= row;
      end else begin
        data_out <= ram[column_address];
      end
    end
  end

  ////////////////////////////////////
  // Set up the auto-refresh system //
  ////////////////////////////////////

  initial begin
    forever begin
      @(posedge clock);
      refresh_counter <= refresh_counter + 1;
      if (refresh_counter == 10'h3FF) begin
        wait_signal <= 1;
        #660; // Using a 66ns refresh time
        wait_signal <= 0;
        next_refresh <= next_refresh + 1;
      end
    end
  end

  //
  // Initialise memory value
  //

  integer i;
  initial begin
    for (i = 0; i < 8192; i = i + 1)
      ram[i] = 0;
  end

endmodule