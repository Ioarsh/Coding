module mux_8tb;
  reg[15:0]i0,i1,i2,i3,i4,i5,i6,i7;
  reg [15:0] o;
  reg [2:0] Sel;
  mux_8 MUX(i0,i1,i2,i3,i4,i5,i6,i7,Sel,o);
  initial begin
    $dumpfile("mux_8tb.vcd");
    $dumpvars(0,mux_8tb);
	Sel=0;i0=1;i1=2;i2=3;i3=4;i4=5;i5=6;i6=7;i7=8;
    
    #10
    Sel=1;
    #10
    Sel=2;
    #10
    Sel=3;
    #10
    Sel=4;
    #10
    Sel=5;
    #10
    Sel=6;
    #10
    Sel=7;
    #10
    Sel=8;
    #10
    i4=10;
    Sel=4;
    #10
    $finish;
  end
  initial begin
    $monitor("in0 = %d : in1 = %d : in2 = %d : in3 = %d: in4 = %d : in5 = %d : in6 = %d : in7 = %d : Sel = %d : o = %d", i0,i1,i2,i3,i4,i5,i6,i7,Sel,o);
  end
endmodule 

/*module mux8_tb;
 reg [2:0] Sel;
  reg [15:0] In1,In2,In3,In4,In5,In6,In7,In8;
  wire [15:0] Out;
  initial begin
    $dumpfile("mux8_tb.vcd");
    $dumpvars(0, mux8_tb);
    
    #1
    Sel = 0;
    In1 = 2;
    In2 = 4;
    In3 = 6;
    In4 = 8;
    In5 = 10;
    In6 = 12;
    In7 = 14;
    In8 = 16;
    
	#1
    Sel = 1;
    
    #1
    Sel = 2;
    
    #1
    Sel = 3;

    #1
    Sel = 4;

    #1
    Sel = 5;

    #1
    Sel = 6;

    #1
    Sel = 7;

    #2
    $finish;
    
  end
  
  mux8 mymux8(.Out(Out),.Sel(Sel),.In1(In1), .In2(In2), .In3(In3), .In4(In4), .In5(In5), .In6(In6), .In7(In7), .In8(In8));
  
  initial begin
    $monitor("in1 = %d : in2 = %d : in3 = %d : in4 = %d : in5 = %d : in6 = %d : in7 = %d : in8 = %d : s = %d : out = %d", In1,In2,In3,In4,In5,In6,In7,In8, Sel, Out);
  end

endmodule

*/