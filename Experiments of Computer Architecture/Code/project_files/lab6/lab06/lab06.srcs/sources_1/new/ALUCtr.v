`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/24 13:31:56
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
        input [3 : 0] aluOp,
        input [5 : 0] funct,
        output reg [3 : 0] aluCtrOut,
        output reg shamtSign
    );
    
    always @ (aluOp or funct)
    begin
        if (aluOp == 4'b1101 || aluOp == 4'b1110) 
        begin
            case (funct)
                6'b100000: aluCtrOut = 4'b0000; // add
                6'b100001: aluCtrOut = 4'b0001; // addu
                6'b100010: aluCtrOut = 4'b0010; // sub
                6'b100011: aluCtrOut = 4'b0011; // subu
                6'b100100: aluCtrOut = 4'b0100; // and
                6'b100101: aluCtrOut = 4'b0101; // or
                6'b100110: aluCtrOut = 4'b0110; // xor
                6'b100111: aluCtrOut = 4'b0111; // nor
                6'b101010: aluCtrOut = 4'b1000; // slt
                6'b101011: aluCtrOut = 4'b1001; // sltu
                6'b000000: aluCtrOut = 4'b1010; // sll
                6'b000010: aluCtrOut = 4'b1011; // srl
                6'b000011: aluCtrOut = 4'b1100; // sra
                6'b000100: aluCtrOut = 4'b1010; // sllv
                6'b000110: aluCtrOut = 4'b1011; // srlv
                6'b000111: aluCtrOut = 4'b1100; // srav
                6'b001000: aluCtrOut = 4'b1111; // jr
                default: aluCtrOut = 4'b1111;
            endcase
            
            if (funct == 6'b000000 || funct == 6'b000010 || funct == 6'b000011)
                shamtSign = 1;
            else
                shamtSign = 0;
        end 
        else 
        begin
            aluCtrOut = aluOp;
            shamtSign = 0;
        end
    end
endmodule
