`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/24 13:37:03
// Design Name: 
// Module Name: Mux32
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


module Mux32(
        input selectSignal,
        input [31:0] input1,
        input [31:0] input2,
        output [31:0] out
    );
    
    assign out = selectSignal ? input1 : input2;
    
endmodule
