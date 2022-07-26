`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/04/26 15:35:32
// Design Name: 
// Module Name: dataMemory_tb
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


module dataMemory_tb(

    );
    
    reg Clk;
    reg [31:0] Address;
    reg [31:0] WriteData;
    reg MemWrite;
    reg MemRead;
    wire [31:0] ReadData;
    
    dataMemory u1(
        .clk(Clk),
        .address(Address), 
        .writeData(WriteData),
        .memWrite(MemWrite), 
        .memRead(MemRead), 
        .readData(ReadData)
    );
    
    always #100 Clk = ~Clk;
    
    initial 
    begin
        // Initialize Inputs
        Clk = 0;
        Address = 0;
        WriteData = 0;
        MemWrite = 0;
        MemRead = 0;
        
        // Current Time: 185 ns
        #185;
        MemWrite = 1'b1;
        Address = 32'b00000000000000000000000000000111;
        WriteData = 32'b11100000000000000000000000000000;
        
        // Current Time: 285 ns
        #100;
        MemWrite = 1'b1;
        WriteData = 32'hffffffff;
        Address = 32'b00000000000000000000000000000110;
        
        // Current Time: 470 ns
        #185;
        MemRead = 1'b1;
        MemWrite = 1'b0;
        Address = 32'b00000000000000000000000000000111;
        
        // Current Time: 550 ns
        #80;
        MemWrite = 1;
        Address = 8;
        WriteData = 32'haaaaaaaa;
        
        // Current Time: 630 ns
        #80;
        MemWrite = 0;
        MemRead = 1;
        Address = 32'b00000000000000000000000000000110;
        
    end
    
endmodule
