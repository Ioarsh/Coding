module counter (clk, reset, q);
  input      clk;
  input      reset;

  output[31:0]     q;

  reg[31:0]        q;
  
  wire[31:0]      d;
  
  wire overflow;
  
  adder_32 adder( .A(q), .B(32'b1), .Cin(1'b0), .S(d), .Cout(overflow) );
  
  always @(posedge clk or posedge reset)
  begin
    if (reset) begin
      // Asynchronous reset when reset goes high
      q <= 32'b0;
    end else begin
      // Assign D to Q on positive clock edge
      q <= d;
    end
  end
endmodule

`include "adder_32.v"