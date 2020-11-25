/* moduledoc

   I'm not 100% sure how we're connecting our CPU to a testbench - presumably this will be the topmost block therefore I'll have to switch the logics and the wires.

*/

module memory_controller (

    /////////////////////
    // Inputs from CPU //
    /////////////////////

    input        write_enable,
    input [31:0] read_address, write_address, write_data,


    ////////////////////
    // Outputs to CPU //
    ////////////////////

    output       wait_request,
    output[31:0] read_data,


    //////////////////////////////
    // Inputs from interconnect //
    //////////////////////////////

    logic[1:0] response,
    logic      read_valid, write_valid,


    /////////////////////////////
    // Outputs to interconnect //
    /////////////////////////////

    output logic[31:0] address,
    output logic [3:0] byte_enable,
    output logic       read, write, lock,

  );

  // Todo: Implement logic to create the signals we need

endmodule