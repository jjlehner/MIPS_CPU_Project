/* moduledoc

*/

`include "rtl/controller/instruction_decompose.vh"
`include "rtl/controller/instruction_decode.vh"

module control (
    input [31:0] instruction,
    output [3:0] alu_op,
    output[25:0] j_tgt,
    output[15:0] i_imm,
    output [4:0] r_src, r_tgt, r_dst, s_arg,
    output mem_wr_en, reg_wr_en, use_alu,
    output pc_branch, pc_jump,
    output i_type, j_type, r_type
  );
  
  wire [5:0] op_code, fn_code;

  //////////////////////////////////////////////////////////////////
  // The instruction decomposer splits the instruction into parts //
  //////////////////////////////////////////////////////////////////

  instruction_decompose i_decompose (
    .instruction(instruction),
    .j_tgt(j_tgt),
    .i_imm(i_imm),
    .op_code(op_code),
    .fn_code(fn_code),
    .r_src(r_src),
    .r_tgt(r_tgt),
    .r_dst(r_dst),
    .s_arg(s_arg)
  );

  ///////////////////////////////////////////////////////////////////////
  // The split up instruction is fed into the control signal generator //
  ///////////////////////////////////////////////////////////////////////

  instruction_decode i_decode (
    .op_code(op_code),
    .fn_code(fn_code),
    .mem_wr_en(mem_wr_en),
    .reg_wr_en(reg_wr_en),
    .use_alu(use_alu),
    .pc_branch(pc_branch),
    .pc_jump(pc_jump),
    .i_type(i_type),
    .j_type(j_type),
    .r_type(r_type)
  );


endmodule