`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/24 13:34:17
// Design Name: 
// Module Name: Registers
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


module Registers(
        input [4:0] readReg1,
        input [4:0] readReg2,
        input [4:0] writeReg,
        input [31:0] writeData,
        input regWrite,
        input jalSign,
        input [31:0] jalData,
        input clk,
        input reset,
        output [31:0] readData1,
        output [31:0] readData2
    );
    
    reg [31:0] regFile [31:0];
    integer i;
    
    assign readData1 = regFile[readReg1];
    assign readData2 = regFile[readReg2];
    
    always @ (readReg1 or readReg2)
    begin
       $display("Register Reading:\n    Reg[%d] = %d\n    Reg[%d] = %d\n", readReg1, readData1, readReg2, readData2);        
    end
    
    always @ (negedge clk)
    begin
        if (regWrite) 
        begin
            regFile[writeReg] = writeData;
            $display("Register Writing:\n    Reg[%d] = %d\n", writeReg, writeData);
        end
        if (jalSign) 
        begin
            regFile[31] = jalData;
            $display("Register Writing:\n    Reg[%d] = %d\n", 31, jalData);
        end
    end
    
    always @ (reset)
    begin
        for (i = 0; i <= 31; i = i + 1) regFile[i] = 0;
    end
endmodule
