module Unsigned_Multiplier(
  input logic clk, start, reset,
  input logic [31:0] input_1, input_2,
  output logic [31:0] hi_output, lo_output, 
  output logic stall
);

//input 1 = multiplicand, input 2 = multiplier

logic [31:0] accumulator, multiplicand, multiplier;
logic [5:0] count;

logic carry, tempcarry;
logic [31:0] result, tempresult;

always_comb begin
  if(!stall) begin
    {tempcarry, tempresult} = input_1 + 32'b0;
  end else begin
    {carry, result} = multiplicand + accumulator;
  end
end

always_ff @(posedge clk, posedge start, posedge reset) begin

  if(reset) begin
    accumulator <= 0;
    multiplicand <= 0;
    multiplier <= 0;
    count <= 0;
	stall <= 0;
  end else if(start && !stall) begin
    multiplicand <= input_1;

    if(input_2[0] == 1) begin
      {accumulator, multiplier} <= {tempcarry, tempresult, input_2[31:1]};
    end else begin
      {accumulator, multiplier} <= {1'b0, 32'b0, input_2[31:1]};
    end

    stall <= 1;
    count <= 31;
  end else if(stall) begin
    if(count-1 == 0) begin
      if(multiplier[0] == 1) begin
        {hi_output, lo_output} <= {carry, result, multiplier[31:1]};
      end else begin
        {hi_output, lo_output} <= {1'b0, accumulator, multiplier[31:1]};
      end
      accumulator <= 0;
      multiplicand <= 0;
      multiplier <= 0;
      stall <= 0;
    end else begin
      if(multiplier[0] == 1) begin
        {accumulator, multiplier} <= {carry, result, multiplier[31:1]};
      end else begin
        {accumulator, multiplier} <= {1'b0, accumulator, multiplier[31:1]};
      end
      count <= count-1;
    end

  end

end

endmodule