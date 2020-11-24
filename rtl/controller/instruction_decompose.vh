/* moduledoc

  This module is essentially macros to extract the bitfields from the instruction for each type.  
  This will be input to a more advanced decoder to convert the bitfields into control signals.

  ## Input  
  instruction: 32 bit instruction fetched from memory

  ## Output  
  j_tgt: The address to jump to on a j-type instruction. This is a location in memory.  
  i_imm: The immediate value for i-type instructions. This is a literal value which an operation will be performed on.  
  op_code: The opcode of the instruction, which identifies the type of instruction (r-type & b-type) or the specific instruction (j-type)  
  fn_code: The function code for r type instructions, which identifies the function to perform.  
  r_src: The source register for r type instructions, ie the 1st argument for our function.  
  r_tgt: The target register for r type instructions, either the register where the result will be stored for 2 argument functions or the 2nd argument for 3 argument functions  
  r_dst: The destination register for r type instructions, where the result will be stored for 3 argument functions.  
  s_arg: The shift argument for non-variable shifts, ie how much to shift by.  
  
*/

module instruction_decompose (
    input [31:0] instruction,
    output[25:0] j_tgt,
    output[15:0] i_imm,
    output[5:0]  op_code, fn_code,
    output[4:0]  r_src, r_tgt, r_dst, s_arg
  );

  //////////////////////
  // All instructions //
  //////////////////////

  assign op_code[5:0] = instruction[31:26];

  /////////////////////////////
  // I & R type instructions //
  /////////////////////////////

  assign r_src[4:0] = instruction[25:21];
  assign r_tgt[4:0] = instruction[20:16];

  /////////////////////////
  // R type instructions //
  /////////////////////////

  assign r_dst[4:0] = instruction[15:11];
  assign s_arg[4:0] = instruction[10:6];
  assign fn_code[5:0] = instruction[5:0];

  /////////////////////////
  // J type instructions //
  /////////////////////////

  assign j_tgt = instruction[25:0];

  /////////////////////////
  // I type instructions //
  /////////////////////////

  assign i_imm = instruction[15:0];

endmodule