/* moduledoc
  
  This module will take opcode and function code from the instruction and use them to calculate what control signals need to be high.

  ## Input
  op_code: The opcode of the instruction, which identifies the type of instruction (r-type & b-type) or the specific instruction (j-type)  
  fn_code: The function code for r type instructions, which identifies the function to perform.  

  ## Output
  reg_wr_en: Write enable for the registers. We need this to ensure registers don't get overwritten when they shouldn't be.  
  mem_wr_en: Write enable for main memory. We need this to ensure main memory doesn't get overwritten when it shouldn't be.  
  use_alu:   A selector for a future MUX. Indicates whether or not we should use the output from the ALU or from main memory.  
  pc_branch: Indicates whether the program counter is liable to be changed by a branch. Currently I'm going to use it for ALU result reduction (XOR => BNE) especially. Will also probably be used in a MUX after logic operations.  
  pc_jump:   Indicates whether the program counter is liable to be changed by a jump. Will probably be used as a selector for a future MUX.  
  i_type:    Indicates whether an instruction takes an immediate operand. Probably will be used in a MUX before the ALU & maybe elsewhere.
  j_type:    Indicates whether an instruction is a jump type instruction. I may end up removing this as it's only high for half of jump instructions and we have pc_jump.  
  r_type:    Indicates whether an instruction is a r type instruction. I may end up removing this as it's essentialy !(i_type) with a couple of exceptions for J and JAL.  
  
*/

module instruction_decode (
    input  [5:0] op_code, fn_code,
    output logic [3:0] alu_op,
    output reg_wr_en, mem_wr_en,
    output use_alu,
    output pc_branch, pc_jump,
    output i_type, j_type, r_type
  );

  /////////////////////////////////////////////////
  // Determine if the instruction changes the pc //
  /////////////////////////////////////////////////

  assign pc_branch = (op_code == 6'b000001) | (op_code[5:2] == 4'b0001);
  assign pc_jump   = (op_code == 6'b000000 & fn_code[5:1] == 5'b00100) | (op_code[5:1] == 5'b00001);

  ///////////////////////////////////////
  // Determine the type of instruction //
  ///////////////////////////////////////

  assign r_type = op_code == 6'b000000;
  assign j_type = op_code[5:1] == 5'b00001;
  assign i_type = ~(j_type | r_type);

  ///////////////////////////////////////////////////////////
  // Determine if it is a load instruction or uses the ALU //
  ///////////////////////////////////////////////////////////

  assign use_alu = ~op_code[0];

  /////////////////////////////////////////////////////
  // Determine whether it writes or writes to memory //
  /////////////////////////////////////////////////////
  
  assign mem_wr_en = op_code[5] & ~op_code[4] & op_code[3]; //SB, SH and SW all take this form

  /////////////////////////////////////////////////////////
  // Determine whether it writes or writes to a register //
  /////////////////////////////////////////////////////////

  /* Icarus verilog doesn't support slices in always_comb so I couldn't make this ternary */

  assign reg_wr_en = (
    (op_code == 6'b000000) & ~(fn_code[5:2] == 4'b0110 | fn_code[5:1] == 5'b01000 | fn_code == 6'b001000)
    | (op_code != 6'b000000) & ~(mem_wr_en | pc_branch | op_code == 6'b000010)
  );

  //////////////////////////////////////////////////////////////////////////////////////////
  // Statements that aren't simple logic are in an always_comb block rather than assigned //
  //////////////////////////////////////////////////////////////////////////////////////////

  always_comb begin   

    ////////////////////////////////////////////////////////////////////////
    // Translate opcodes for branch etc. into a function code for the ALU //
    ////////////////////////////////////////////////////////////////////////

    casex (op_code)
      6'b000000: casex (fn_code)  // All R type instructions
      6'b000?00: alu_op = 4'b0101; // SLL, SLLV
      6'b000?10: alu_op = 4'b0111; // SRL, SRLV
      6'b000?11: alu_op = 4'b0110; // SRA, SRAV
      6'b011000: alu_op = 4'b1110; // MULT
      6'b011001: alu_op = 4'b1111; // MULTU
      6'b011010: alu_op = 4'b1100; // DIV
      6'b011011: alu_op = 4'b1101; // DIVU
      6'b100001: alu_op = 4'b1010; // ADDU
      6'b100011: alu_op = 4'b1011; // SUBU
      6'b100100: alu_op = 4'b0000; // AND
      6'b100101: alu_op = 4'b0001; // OR
      6'b100110: alu_op = 4'b0010; // XOR
      6'b101010: alu_op = 4'b1000; // SLT
      6'b101011: alu_op = 4'b1001; // SLTU
      default:   alu_op = 4'bzzzz; // Not an instruction that uses the ALU - I didn't know what to put lol
      endcase
      6'b000001: alu_op = 4'b0011; // BGEZ, BGEZAL, BLTZ, BLTZAL
      6'b00010?: alu_op = 4'b0010; // BNE, BEQ
      6'b00011?: alu_op = 4'b0100; // BLEZ, BGTZ
      6'b001001: alu_op = 4'b1010; // ADDIU
      6'b001010: alu_op = 4'b1000; // SLTI
      6'b001011: alu_op = 4'b1001; // SLTIU
      6'b001100: alu_op = 4'b0000; // ANDI
      6'b001101: alu_op = 4'b0001; // ORI
      6'b001110: alu_op = 4'b0010; // XORI
      default:   alu_op = 4'bzzzz; // Not an instruction that uses the ALU - I didn't know what to put lol
    endcase
  end

endmodule