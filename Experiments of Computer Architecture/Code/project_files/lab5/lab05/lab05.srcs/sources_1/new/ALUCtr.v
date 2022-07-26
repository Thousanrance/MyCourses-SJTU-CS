`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/10 15:11:46 
// Design Name: 
// Module Name: ALUCtr
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


module ALUCtr(
        input [2:0] aluOp,
        input [5:0] funct,
        output reg [3:0] aluCtrOut,
        output reg shamtSign,
        output reg jrSign
    );
    
    always @ (aluOp or funct)
    begin
        casex ({aluOp, funct})
            9'b000xxxxxx: aluCtrOut = 4'b0010; //lw or sw
            9'b001xxxxxx: aluCtrOut = 4'b0110; //beq: actually sub
            9'b010xxxxxx: aluCtrOut = 4'b0010; //addi
            9'b011xxxxxx: aluCtrOut = 4'b0000; //andi
            9'b100xxxxxx: aluCtrOut = 4'b0001; //ori
            9'b101000000: aluCtrOut = 4'b0011; //sll
            9'b101000010: aluCtrOut = 4'b0100; //srl
            9'b101001000: aluCtrOut = 4'b0101; //jr: actually not change
            9'b101100000: aluCtrOut = 4'b0010; //add
            9'b101100010: aluCtrOut = 4'b0110; //sub
            9'b101100100: aluCtrOut = 4'b0000; //and
            9'b101100101: aluCtrOut = 4'b0001; //or
            9'b101101010: aluCtrOut = 4'b0111; //slt
            9'b110xxxxxx: aluCtrOut = 4'b0101; //jump/jal: actually not change
            default: aluCtrOut = 4'b1111;
        endcase        
        
        if ({aluOp, funct} == 9'b101000000 || {aluOp, funct} == 9'b101000010)
            shamtSign = 1;
        else 
            shamtSign = 0;
        
        if ({aluOp, funct} == 9'b101001000)
            jrSign = 1;
        else 
            jrSign = 0;
            
    end
endmodule
