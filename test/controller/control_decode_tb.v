`include "rtl/controller/control_decode.vh"

module control_decode_tb();
  logic clock;
  logic[31:0] instruction;
  logic[25:0] j_tgt;
  logic[15:0] i_imm;
  logic[5:0]  op_code, fn_code;
  logic[4:0]  r_src, r_tgt, r_dst, s_arg;
  logic[3:0]  alu_op;
  logic mem_wr_en, reg_wr_en;
  logic pc_branch, pc_jump;
  logic i_type, j_type, r_type;

  control_decode c_sig_gen (
    .j_tgt(j_tgt),
    .i_imm(i_imm),
    .op_code(op_code),
    .fn_code(fn_code),
    .r_src(r_src),
    .r_tgt(r_tgt),
    .r_dst(r_dst),
    .s_arg(s_arg),
    .mem_wr_en(mem_wr_en),
    .reg_wr_en(reg_wr_en),
    .pc_branch(pc_branch),
    .pc_jump(pc_jump),
    .i_type(i_type),
    .j_type(j_type),
    .r_type(r_type)
  );

  initial begin
    forever begin
      clock = 0;
      #5;
      clock = 1;
      #5;
    end
  end

  initial begin
    #100;

    instruction <= 32'h18080001; //BLEZ $a0, 1
    #100;
    $display("BLEZ");
    $display("opcode: %b", op_code);
    $display("fncode: %b", fn_code);
    $display("mem write: %b", mem_wr_en);
    $display("reg write: %b", reg_wr_en);
    
    instruction <= 32'h00481021; //ADDU $v0, $v0, $t0
    #100;
    $display("ADDU");
    $display("opcode: %b", op_code);
    $display("fncode: %b", fn_code);
    $display("mem write: %b", mem_wr_en);
    $display("reg write: %b", reg_wr_en);

    instruction <= 32'h20000003; //ADDI $a0, $0, 3
    #100;
    $display("ADDI");
    $display("opcode: %b", op_code);
    $display("fncode: %b", fn_code);
    $display("mem write: %b", mem_wr_en);
    $display("reg write: %b", reg_wr_en);

    instruction <= 32'h0800003C; // J 3C
    #100;
    $display("J");
    $display("opcode: %b", op_code);
    $display("fncode: %b", fn_code);
    $display("mem write: %b", mem_wr_en);
    $display("reg write: %b", reg_wr_en);

    instruction <= 32'h03e00008; // JR $ra
    #100;
    $display("JR");
    $display("opcode: %b", op_code);
    $display("fncode: %b", fn_code);
    $display("mem write: %b", mem_wr_en);
    $display("reg write: %b", reg_wr_en);

    $finish;
  end

endmodule