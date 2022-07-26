`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/24 14:12:20
// Design Name: 
// Module Name: Top_tb
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


module Top_tb(
    );
    reg clk;
    reg reset;
        
    Top processor(.clk(clk), .reset(reset));
    
    initial 
    begin
        $readmemb("C:/ArchLabs/lab06/mem_inst.dat", processor.inst_memory.instFile);
        $readmemh("C:/ArchLabs/lab06/mem_data.dat", processor.data_memory.memFile);         
        reset = 1;
        clk = 0;
    end
    
    always #20 clk = ~clk;
    
    initial begin
        #40 reset = 0;
        #1500;
        $finish;
    end
endmodule
