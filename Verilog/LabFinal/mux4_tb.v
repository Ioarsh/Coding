module mux4_tb;
  reg[3:0] in0, in1, in2, in3;
  wire[3:0] out;
  reg[1:0] s;
  
  initial begin
    $dumpfile("mux4_tb.vcd");
    $dumpvars(0, mux4_tb);
    
    #1
    s = 0;
    in0 = 2;
    in1 = 4;
    in2 = 6;
    in3 = 9;
    
    #1
    s = 1;
    
    #1
    s = 2;

    #1
    s = 3;
    
    #1
    s = 0;
    
    #1
    s = 1;
    
    #1
    s = 2;

    #1
    s = 3;

    #2
    $finish;
    
  end
  
  mux4 mymux4(.y(out), .d0(in0), .d1(in1), .d2(in2), .d3(in3), .s(s));
  
  initial begin
    $monitor("in0 = %d : in1 = %d : in2 = %d : in3 = %d : s = %d : out = %d", in0, in1, in2, in3, s, out);
  end

endmodule
