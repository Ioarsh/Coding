module mux4(input [3:0] d0, d1, d2, d3,
            input [1:0] s,
            output [3:0] y);
  
  wire [3:0] lowmux_out, highmux_out;
  
  mux2 lowmux(.d0(d0), .d1(d1), .s(s[0]), .y(lowmux_out));
  mux2 highmux(.d0(d2), .d1(d3), .s(s[0]), .y(highmux_out));
  mux2 finalmux(.d0(lowmux_out), .d1(highmux_out), .s(s[1]), .y(y));
  
endmodule
