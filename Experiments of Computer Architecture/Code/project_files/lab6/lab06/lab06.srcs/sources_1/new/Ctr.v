`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/24 13:30:37
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
        input [5:0] opCode,
        input [5:0] funct,
        input nop,
        output reg regDst,
        output reg aluSrc,
        output reg regWrite,
        output reg memToReg,
        output reg memRead,
        output reg memWrite,
        output reg beqSign,
        output reg bneSign,
        output reg luiSign,
        output reg extSign,
        output reg jalSign,
        output reg jrSign,
        output reg [3:0] aluOp,
        output reg jump
    );
    
    always @(opCode or funct or nop)
    begin
        if (nop) 
        begin
            regDst = 0;
            aluSrc = 0;
            regWrite = 0;
            memToReg = 0;
            memRead = 0;
            memWrite = 0;
            beqSign = 0;
            bneSign = 0;
            luiSign = 0;
            extSign = 0;
            jalSign = 0;
            jrSign = 0;
            aluOp = 4'b1111;
            jump = 0;
        end 
        else 
        begin
            case(opCode)
                6'b000000:      // R-Type
                begin
                    if (funct == 6'b001000) 
                    begin    // jr
                        regDst = 0;
                        regWrite = 0;
                        jrSign = 1;
                        aluOp = 4'b1111;
                    end 
                    else 
                    begin
                        regDst = 1;
                        regWrite = 1;
                        jrSign = 0;
                        aluOp = 4'b1101;
                    end
                    aluSrc = 0;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 0;
                    jalSign = 0;
                    jump = 0;
                end
                
                6'b001000:      // addi
                begin
                    regDst = 0;
                    aluSrc = 1;
                    regWrite = 1;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 1;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b0000;
                    jump = 0;
                end
                
                6'b001001:      // addiu
                begin                
                    regDst = 0;
                    aluSrc = 1;
                    regWrite = 1;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 0;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b0001;
                    jump = 0;
                end
                
                6'b001100:      // andi
                begin                
                    regDst = 0;
                    aluSrc = 1;
                    regWrite = 1;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 0;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b0100;
                    jump = 0;
                end
                
                6'b001101:      // ori
                begin                
                    regDst = 0;
                    aluSrc = 1;
                    regWrite = 1;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 0;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b0101;
                    jump = 0;
                end
                
                6'b001110:      // xori
                begin                
                    regDst = 0;
                    aluSrc = 1;
                    regWrite = 1;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 0;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b0110;
                    jump = 0;
                end
                
                6'b001111:      // lui
                begin                
                    regDst = 0;
                    aluSrc = 1;
                    regWrite = 1;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 1;
                    extSign = 0;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b1010;
                    jump = 0;
                end
                
                6'b100011:      // lw
                begin                
                    regDst = 0;
                    aluSrc = 1;
                    regWrite = 1;
                    memToReg = 1;
                    memRead = 1;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 1;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b0001;
                    jump = 0;
                end
                
                6'b101011:      // sw
                begin                
                    regDst = 0;
                    aluSrc = 1;
                    regWrite = 0;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 1;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 1;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b0001;
                    jump = 0;
                end
                
                6'b000100:      // beq
                begin                
                    regDst = 0;
                    aluSrc = 0;
                    regWrite = 0;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 1;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 1;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b0011;
                    jump = 0;
                end
                
                6'b000101:      // bne
                begin                
                    regDst = 0;
                    aluSrc = 0;
                    regWrite = 0;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 1;
                    luiSign = 0;
                    extSign = 1;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b0011;
                    jump = 0;
                end
                
                6'b001010:      // slti
                begin                
                    regDst = 0;
                    aluSrc = 1;
                    regWrite = 1;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 1;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b1000;
                    jump = 0;
                end
                
                6'b001011:      // sltiu
                begin                
                    regDst = 0;
                    aluSrc = 1;
                    regWrite = 1;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 0;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b1001;
                    jump = 0;
                end
                
                6'b000010:      // jump
                begin                
                    regDst = 0;
                    aluSrc = 0;
                    regWrite = 0;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 0;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b1111;
                    jump = 1;
                end
                
                6'b000011:      // jal
                begin                
                    regDst = 0;
                    aluSrc = 0;
                    regWrite = 0;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 0;
                    jalSign = 1;
                    jrSign = 0;
                    aluOp = 4'b1111;
                    jump = 1;
                end
                
                default:
                begin                
                    regDst = 0;
                    aluSrc = 0;
                    regWrite = 0;
                    memToReg = 0;
                    memRead = 0;
                    memWrite = 0;
                    beqSign = 0;
                    bneSign = 0;
                    luiSign = 0;
                    extSign = 0;
                    jalSign = 0;
                    jrSign = 0;
                    aluOp = 4'b1111;
                    jump = 0;
                end
            endcase
        end
    end
endmodule
