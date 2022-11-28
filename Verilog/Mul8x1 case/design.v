module mux_8(input [15:0] i0,i1,i2,i3,i4,i5,i6,i7, //input 8x1 
             input [2:0] Sel, //3-bit selection
             output reg [15:0] o);
  always@(*)
    begin
      case(Sel)
        0:o=i0;
        1:o=i1;
        2:o=i2;
        3:o=i3;
        4:o=i4;
        5:o=i5;
        6:o=i6;
        7:o=i7;
      endcase
    end
endmodule

/*module mux8( Out,Sel,In1,In2,In3,In4,In5,In6,In7,In8); 
	input [15:0]  In1,In2,In3,In4,In5,In6,In7,In8;
	input [2:0] Sel;
  output [15:0] Out; 
  reg [15:0] Out; 
always @ (In1 or In2 or In3 or In4 or In5 or In6 or In7 or In8 or Sel) 
begin 
 case (Sel) 
  3'b000 : Out = In1; 
  3'b001 : Out = In2; 
  3'b010 : Out = In3; 
  3'b011 : Out = In4; 
  3'b100 : Out = In5; 
  3'b101 : Out = In6; 
  3'b110 : Out = In7; 
  3'b111 : Out = In8; 
  default : Out = 16'bx; 
 endcase 
end  
endmodule*/