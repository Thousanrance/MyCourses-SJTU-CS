`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/10 17:02:01
// Design Name: 
// Module Name: instMemory
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


module InstMemory(
        input [31:0] address,
        output [31:0] inst
    );
    
    reg [31:0] instFile [0:1023];
    
    assign inst = (address / 4 <= 1023 ? instFile[address / 4] : 0); //check valid
    
endmodule