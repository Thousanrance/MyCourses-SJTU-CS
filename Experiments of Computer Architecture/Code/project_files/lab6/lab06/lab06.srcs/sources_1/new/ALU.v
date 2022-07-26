`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/24 13:32:23
// Design Name: 
// Module Name: ALU
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


module ALU(
        input [31:0] inputA,
        input [31:0] inputB,
        input [3:0] aluCtrOut,
        output reg zero,
        output reg overflow,
        output reg [31:0] aluRes
    );
    
    always @ (inputA or inputB or aluCtrOut)
    begin
        case (aluCtrOut)
            4'b0000:        // add with overflow check
            begin
                aluRes = inputA + inputB;
                if ((inputA >> 31) == (inputB >> 31) && (inputA >> 31) != (aluRes >> 31))
                    overflow = 1;
                else
                    overflow = 0;
            end
            4'b0001:        // add
                aluRes = inputA + inputB;
            4'b0010:        // sub with overflow check
            begin
                aluRes = inputA - inputB;
            end
            4'b0011:        // sub
                aluRes = inputA - inputB;
            4'b0100:        // and
                aluRes = inputA & inputB;
            4'b0101:        // or
                aluRes = inputA | inputB;
            4'b0110:        // xor
                aluRes = inputA ^ inputB;
            4'b0111:        // nor
                aluRes = ~(inputA | inputB);
            4'b1000:        // slt
                aluRes = ($signed(inputA) < $signed(inputB));
            4'b1001:        // slt (unsigned)
                aluRes = (inputA < inputB);
            4'b1010:        // left-shift
                aluRes = (inputB << inputA);
            4'b1011:        // right-shift
                aluRes = (inputB >> inputA);
            4'b1100:        // right-shift (arithmetic)
                aluRes = ($signed(inputB) >>> inputA);
            default:        // default
                aluRes = 0;
        endcase
        
        if (aluRes == 0)
            zero = 1;
        else 
            zero = 0;
    end
endmodule
