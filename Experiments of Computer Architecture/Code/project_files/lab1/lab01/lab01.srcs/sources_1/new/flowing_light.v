`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/04/24 13:44:21 
// Design Name: 
// Module Name: flowing_light
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


module flowing_light(
    //input clock_p,
    //input clock_n,
    input clock,
    input reset,
    output [7:0] led
    );

    reg [1 : 0] cnt_reg; //24 -> 2
    reg [7 : 0] light_reg;
    
    /*
    IBUFGDS IBUFGDS_inst (
        .O(CLK_i),
        .I(clock_p),
        .IB(clock_n)
    );
    */
    
    always @ (posedge clock) //CLK_i
        begin 
            if (reset) //!reset: The button on the board actually is low when being pushed
                cnt_reg <= 0;
            else
                cnt_reg <= cnt_reg + 1;
        end
    always @ (posedge clock) //CLK_i
        begin 
            if (reset) //!reset: The button on the board actually is low when being pushed
                light_reg <= 8'h01;
            else if (cnt_reg == 2'b11) //24'hffffff -> 2'b11
                begin
                    if (light_reg == 8'h80)
                        light_reg <= 8'h01;
                    else
                        light_reg <= light_reg << 1;
                end
        end
    assign led = light_reg;

endmodule
