`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/04/26 13:41:48
// Design Name: 
// Module Name: ALU
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


module ALU(
        input [31:0] input1,
        input [31:0] input2,
        input [3:0] aluCtrOut,
        output zero, 
        output [31:0] aluRes
    );
    
    reg ZERO;
    reg [31:0] ALURes;
    
    always @ (input1 or input2 or aluCtrOut)
    begin
        case (aluCtrOut)
            4'b0000: ALURes = input1 & input2; //AND
            4'b0001: ALURes = input1 | input2; //OR
            4'b0010: ALURes = input1 + input2; //add
            4'b0110: ALURes = input1 - input2; //sub
            4'b0111: ALURes = (input1 < input2); //set on less than
            4'b1100: ALURes = ~(input1 | input2); //NOR
            default: ALURes = 32'b0;
        endcase
        
        if (ALURes == 0) ZERO = 1;
        else ZERO = 0;
        
    end
    
    assign zero = ZERO;
    assign aluRes = ALURes;
    
endmodule
