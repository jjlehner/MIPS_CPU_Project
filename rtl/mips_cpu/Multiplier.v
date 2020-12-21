module Multiplier
(
  input logic clk, start, reset,
  input logic [31:0] input_1, input_2,
  output logic [31:0] hi_output, lo_output,
  output logic stall
);

/*
  Signed 2's complement multiplication using booth's algorithm. Takes 32 clock
  cycles in every case.
*/

logic [31:0] tempadd, tempsub;
logic [31:0] add, sub;
logic [31:0] A, Q, M;
logic q0;
logic [5:0] n;

always_comb begin
  if(!stall) begin
    tempsub = -(input_1);
    tempadd = input_1;
  end else begin
    sub = A - M;
    add = A + M;
  end
end

always_ff @(posedge clk, posedge start, posedge reset) begin  
  if(reset) begin
    A <=0;
    Q <=0;
    M <= 0;
    q0 <= 0;
    n <= 0;
    stall <= 0;
    hi_output <= 0;
    lo_output <= 0;
  end  
  else if(start && !stall) begin
    Q <= input_2;
    M <= input_1;

    case({input_2[0], q0})
      2'b10: {A, Q, q0} <= {tempsub[31], tempsub, input_2};
      2'b01: {A, Q, q0} <= {tempadd[31], tempadd, input_2};
      default: {A, Q, q0} <= {A[31], A, input_2};
    endcase

    stall <= 1;
    n <= 31;
  end
  else if (stall) begin

    if(n == 0) begin
      hi_output <= A;
      lo_output <= Q;
      A <= 0;
      Q <= 0;
      M <= 0;
      stall <= 0;
    end else if(n-1 == 0) begin
      case({Q[0], q0})
        2'b10:
          {hi_output, lo_output} <= {sub[31], sub, Q[31:1]};
        2'b01:
          {hi_output, lo_output} <= {add[31], add, Q[31:1]};
        default:
          {hi_output, lo_output} <= {A[31], A, Q[31:1]};
      endcase

      A <= 0;
      Q <= 0;
      M <= 0;
      stall <= 0;
    end else begin
      case({Q[0], q0})
        2'b10: {A, Q, q0} <= {sub[31], sub, Q};
        2'b01: {A, Q, q0} <= {add[31], add, Q};
        default: {A, Q, q0} <= {A[31], A, Q};
      endcase
      n <= n-1;
    end

  end

end

endmodule
