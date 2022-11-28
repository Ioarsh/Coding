module test_counter;

  reg clk;
  reg reset;
  wire[31:0] out;
  
  reg [31:0] In1, In2;
  reg Cin;
  wire[31:0] adder_out;
  wire Cout;
  
  
  // Instantiate design under test
  counter my_counter(.clk(clk), .reset(reset), .q(out));
  
  adder_32 my_adder(.A(In1), .B(In2), .Cin(Cin), .S(adder_out), .Cout(Cout));
          
  initial begin
    // Dump waves
    $dumpfile("dump.vcd");
    $dumpvars(1);
    
    #0
    clk = 0;
    reset = 1;
    
    In1 = 70000;
    In2 = 80000;
    Cin = 0;
    
    #1
    reset = 0;
    
    In1 = 900000;
    In2 = 500000;
    
    #20
    $finish;

  end
  
  always begin
    #1 clk = ~clk;
  end
  
    initial begin
      $monitor("clk = %d : reset = %d : out = %d", clk, reset, out);
      $monitor("In1 = %d : In2 = %d : Cin = %d : adder_out = %d : Cout = %d", In1, In2, Cin, adder_out, Cout);
  end

endmodule