`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/04/24 15:05:07
// Design Name: 
// Module Name: adder_4bits_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module adder_4bits_tb(

    );
    
    reg [3:0] a;
    reg [3:0] b;
    reg ci;
    
    wire [3:0] s;
    wire co;
    
    adder_4bits u0(.a(a), .b(b), .ci(ci), .s(s), .co(co));
    
    initial
        begin
            a = 0;
            b = 0;
            ci = 0; //0+0=0
            
            #100;
            a = 4'b0001;
            b = 4'b0010; //1+2=3 -> s = 0011
            
            #100;
            a = 4'b0010;
            b = 4'b0100; //2+4=6 -> s = 0110
            
            #100
            a = 4'b1111;
            b = 4'b0001; //15+1=16 -> 1 0000 -> s = 0000 co = 1
            
            #100
            ci = 1'b1; //s = 0001 co = 1
        end
    
endmodule
