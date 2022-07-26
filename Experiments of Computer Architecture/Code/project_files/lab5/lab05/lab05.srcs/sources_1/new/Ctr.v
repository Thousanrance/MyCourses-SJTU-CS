`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/10 14:25:40
// Design Name: 
// Module Name: Ctr
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


module Ctr(
        input [5 : 0] opCode,
        output reg regDst,
        output reg aluSrc,
        output reg memToReg,
        output reg regWrite,
        output reg memRead,
        output reg memWrite,
        output reg branch,
        output reg extSign,
        output reg jalSign,
        output reg [2:0] aluOp,
        output reg jump
    );
    
    always @(opCode)
    begin
        case(opCode)
            6'b000000: //R-Type
            begin
                regDst = 1;
                aluSrc = 0;
                memToReg = 0;
                regWrite = 1;
                memRead = 0;
                memWrite = 0;
                branch = 0;
                extSign = 0;
                jalSign = 0;
                aluOp = 3'b101;
                jump = 0;
            end
            
            6'b100011: //lw
            begin
                regDst = 0;
                aluSrc = 1;
                memToReg = 1;
                regWrite = 1;
                memRead = 1;
                memWrite = 0;
                branch = 0;
                extSign = 1;
                jalSign = 0;
                aluOp = 3'b000;
                jump = 0;
            end
            
            6'b101011: //sw
            begin
                regDst = 0;
                aluSrc = 1;
                memToReg = 0;
                regWrite = 0;
                memRead = 0;
                memWrite = 1;
                branch = 0;
                extSign = 1;
                jalSign = 0;
                aluOp = 3'b000;
                jump = 0;
            end
            
            6'b000100: //beq
            begin
                regDst = 0;
                aluSrc = 0;
                memToReg = 0;
                regWrite = 0;
                memRead = 0;
                memWrite = 0;
                branch = 1;
                extSign = 1;
                jalSign = 0;
                aluOp = 3'b001;
                jump = 0;
            end
            
            6'b001000: //addi
            begin
                regDst = 0;
                aluSrc = 1;
                memToReg = 0;
                regWrite = 1;
                memRead = 0;
                memWrite = 0;
                branch = 0;
                extSign = 1;
                jalSign = 0;
                aluOp = 3'b010;
                jump = 0;
            end
            
            6'b001100: //andi
            begin
                regDst = 0;
                aluSrc = 1;
                memToReg = 0;
                regWrite = 1;
                memRead = 0;
                memWrite = 0;
                branch = 0;
                extSign = 0;
                jalSign = 0;
                aluOp = 3'b011;
                jump = 0;
            end
            
            6'b001101: //ori
            begin
                regDst = 0;
                aluSrc = 1;
                memToReg = 0;
                regWrite = 1;
                memRead = 0;
                memWrite = 0;
                branch = 0;
                extSign = 0;
                jalSign = 0;
                aluOp = 3'b100;
                jump = 0;
            end
            
            6'b000010: //jump
            begin
                regDst = 0;
                aluSrc = 0;
                memToReg = 0;
                regWrite = 0;
                memRead = 0;
                memWrite = 0;
                branch = 0;
                extSign = 0;
                jalSign = 0;
                aluOp = 3'b110;
                jump = 1;
            end
            
            6'b000011: //jal
            begin
                regDst = 0;
                aluSrc = 0;
                memToReg = 0;
                regWrite = 1;
                memRead = 0;
                memWrite = 0;
                branch = 0;
                extSign = 0;
                jalSign = 1;
                aluOp = 3'b110;
                jump = 1;                
            end
            
            default:
            begin
                regDst = 0;
                aluSrc = 0;
                memToReg = 0;
                regWrite = 0;
                memRead = 0;
                memWrite = 0;
                branch = 0;
                extSign = 0;
                jalSign = 0;
                aluOp = 3'b111;
                jump = 0;
            end
        endcase
    end
endmodule
