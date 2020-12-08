interface Harvard_Interface_RAM_side(
    input logic clk,
    output logic resetl,
    input logic active,
    input logic [31:0] register_v0,

    /* New clock enable. See below. */
    output logic clk_enable,

    /* Combinatorial read access to instructions */
    input logic[31:0]  instr_address,
    output logic[31:0]   instr_readdata,

    /* Combinatorial read and single-cycle write access to instructions */
    input logic[31:0] data_address,
    input logic data_write,
    input logic data_read,
    input logic[31:0] data_writedata,
    output logic[31:0] data_readdata
);


endinterface //Harvard_Interface
