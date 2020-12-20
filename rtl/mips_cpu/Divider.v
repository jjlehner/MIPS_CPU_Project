module Divider(
  input logic clk, start, signedctrl,
  input logic [31:0] input_1, input_2,
  input reset,
  output logic [31:0] output_1,
  output logic [31:0] output_2,
  output logic stall
);

/*
input1 = dividend, input2 = divisor
output1 = quotient, output2 = remainder
logic stall;
Divison algorithm as explained in the lectures and textbook.
Takes 32 clock cycles in every case
*/

logic [63:0] temp1, temp2, divisor, remainder, tempsub;
logic [31:0] div1, div2, quotient;
logic [5:0] n;
logic signdiff, dividendsign;
logic [63:0] output_2_temp;
assign output_2 = output_2_temp[31:0];
always_comb begin
  if(signedctrl) begin
    if($signed(input_1) < 0) begin
      div1 = -input_1;//remainder
      dividendsign = 1;
    end else begin
      div1 = input_1; //remainder
    end
    if($signed(input_2) < 0) begin
      div2 = -input_2;
    end else begin
      div2 = input_2; //divisor
    end
    temp1 = {32'b0, div1}; //remainder
    temp2 = {div2, 32'b0}; //devisor
    tempsub = temp1 - temp2;

    if(($signed(input_1) < 0 && $signed(input_2) > 0) || ($signed(input_2) < 0 && $signed(input_1) > 0)) begin
      signdiff = 1;
    end
  end else if(!stall) begin
    temp1 = {32'b0, input_1}; //remainder
    temp2 = {input_2, 32'b0}; //devisor
    tempsub = temp1 - temp2;
  end

  if(n == 0) begin
    signdiff = 0;
    dividendsign = 0;
  end
end

always_ff @(posedge clk, posedge start, posedge reset) begin
  if(reset) begin
    stall <= 0;
    remainder <= 0;
    quotient <= 0;
    divisor <=0;
    n <= 0;
    output_1 <= 0;
    output_2_temp <= 0;
  end else begin
    if(start && !stall) begin

    if($signed(tempsub) < 0) begin
      remainder <= temp1;
      quotient <= 32'b0;
    end else begin
      remainder <= tempsub;
      quotient <= {31'b0, 1'b1};
    end

    divisor <= {temp2[63], temp2[63:1]};
    n <= 1;
    stall <= 1;

  end else if(stall) begin
    if($signed(remainder - divisor) < 0) begin
      quotient <= quotient << 1;
    end else begin
      remainder <= $signed(remainder - divisor);
      quotient <= {quotient[30:0], 1'b1};
    end
    divisor <= divisor >> 1;
    n <= n + 1;
  end

  if(n+1 == 33) begin
      if($signed(remainder - divisor) < 0) begin
          if(signedctrl) begin

            if(signdiff) begin
              output_1 <= -(quotient << 1);
            end else begin
              output_1 <= quotient << 1;
            end

            if(dividendsign) begin
              output_2_temp <= 0-remainder;
            end else begin
              output_2_temp <= remainder;
            end

          end else begin
            output_1 <= quotient << 1;
            output_2_temp <= remainder;
          end

      end else begin
        if(signedctrl) begin
          if(signdiff) begin
            output_1 <= -({quotient[30:0], 1'b1});
          end else begin
            output_1 <= {quotient[30:0], 1'b1};
          end

          if(dividendsign) begin
            output_2_temp <= -(remainder - divisor);
          end else begin
            output_2_temp <= $signed(remainder - divisor);
          end
        end else begin
          output_2_temp <= $signed(remainder - divisor);
          output_1 <= {quotient[30:0], 1'b1};
        end
      end

      stall <= 0;
      n <= 0;


    end
  end

end

endmodule