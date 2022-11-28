module fulladder(input a, b, cin,
                 output s, cout);
  wire p, g;
  
  assign p = a ^ b;
  assign g = a & b;
  
  assign s = p ^ cin;
  assign cout = g | (p & cin);
  
endmodule

module adder_2(input [1:0] a, b,
               input cin,
               output [1:0] s,
               output cout);
  
  wire cout_L;
  
  fulladder adder_1_L( .a(a[0]), .b(b[0]), .cin(cin), .s(s[0]), .cout(cout_L) );
  fulladder adder_1_R( .a(a[1]), .b(b[1]), .cin(cout_L), .s(s[1]), .cout(cout) );
  
endmodule


module adder_4(input [3:0] a, b,
               input cin,
               output [3:0] s,
               output cout);
  
  wire cout_L;
  
  adder_2 adder_2_L( .a(a[1:0]), .b(b[1:0]), .cin(cin), .s(s[1:0]), .cout(cout_L) );
  adder_2 adder_2_R( .a(a[3:2]), .b(b[3:2]), .cin(cout_L), .s(s[3:2]), .cout(cout) );
  
endmodule

module adder_8(input [7:0] a, b,
               input cin,
               output [7:0] s,
               output cout);
  
  wire cout_L;
  
  adder_4 adder_4_L( .a(a[3:0]), .b(b[3:0]), .cin(cin), .s(s[3:0]), .cout(cout_L) );
  adder_4 adder_4_R( .a(a[7:4]), .b(b[7:4]), .cin(cout_L), .s(s[7:4]), .cout(cout) );
  
endmodule

module adder_16(input [15:0] a, b,
               input cin,
                output [15:0] s,
               output cout);
  
  wire cout_L;
  
  adder_8 adder_8_L( .a(a[7:0]), .b(b[7:0]), .cin(cin), .s(s[7:0]), .cout(cout_L) );
  adder_8 adder_8_R( .a(a[15:8]), .b(b[15:8]), .cin(cout_L), .s(s[15:8]), .cout(cout) );
  
endmodule

module adder_32(input [31:0] A, B,
               input Cin,
                output [31:0] S,
               output Cout);
  
  wire cout_L;
  
  adder_16 adder_16_L( .a(A[15:0]), .b(B[15:0]), .cin(Cin), .s(S[15:0]), .cout(cout_L) );
  adder_16 adder_16_R( .a(A[31:16]), .b(B[31:16]), .cin(cout_L), .s(S[31:16]), .cout(Cout) );
  
endmodule