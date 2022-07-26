`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/04/26 13:53:49
// Design Name: 
// Module Name: ALU_tb
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


module ALU_tb(

    );
    
    reg [31:0] Input1;
    reg [31:0] Input2;
    reg [3:0] ALUCtrOut;
    wire ZERO;
    wire [31:0] ALURes;
    
    ALU u2(
        .input1(Input1), 
        .input2(Input2),
        .aluCtrOut(ALUCtrOut), 
        .zero(ZERO),
        .aluRes(ALURes)
    );
    
    initial
    begin
        #100;  //AND
        Input1 = 32'b001;
        Input2 = 32'b011;
        ALUCtrOut = 4'b0000;
        
        #100;  //OR
        Input1 = 32'b001;
        Input2 = 32'b011;
        ALUCtrOut = 4'b0001;
        
        #100;  //add
        Input1 = 32'b001;
        Input2 = 32'b011;
        ALUCtrOut = 4'b0010;
        
        #100;  //sub
        Input1 = 32'b0;
        Input2 = 32'b0;
        ALUCtrOut = 4'b0110;
        
        #100;  //set on less than
        Input1 = 32'b001;
        Input2 = 32'b011;
        ALUCtrOut = 4'b0111;
        
        #100;  //NOR
        Input1 = 32'b001;
        Input2 = 32'b011;
        ALUCtrOut = 4'b1100;
        
        #100;  //default
        Input1 = 32'b0;
        Input2 = 32'b0;
        ALUCtrOut = 4'b1111;
    end
    
endmodule
