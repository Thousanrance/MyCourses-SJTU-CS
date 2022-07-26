`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/04/26 16:37:19
// Design Name: 
// Module Name: signext_tb
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


module signext_tb(

    );
    
    reg [15:0] Inst;
    wire [31:0] Data;
    
    signext u2(
        .inst(Inst),
        .data(Data)
    );
    
    initial
    begin
        Inst = 0;
        
        Inst = 16'h0000;
        #100;
        
        Inst = 16'h0001;
        #100;
        
        Inst = 16'hffff;
        #100;
        
        Inst = 16'h0002;
        #100;
        
        Inst = 16'hfffe;
        #100;
        
    end
    
endmodule
