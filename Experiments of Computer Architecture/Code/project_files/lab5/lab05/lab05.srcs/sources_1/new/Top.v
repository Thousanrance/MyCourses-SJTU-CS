`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/10 20:08:12
// Design Name: 
// Module Name: Top
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


module Top(
        input clk,
        input reset
    );
    
    wire [31:0] INST_ADDR;          // Instruction address
    wire [31:0] INST;               // Instruction
    wire REG_DST;                   // RegDst
    wire ALU_SRC;                   // ALUSrc
    wire MEM_TO_REG;                // MemToReg
    wire REG_WRITE;                 // RegWrite
    wire MEM_READ;                  // MemRead
    wire MEM_WRITE;                 // MemWrite
    wire BRANCH;                    // Branch
    wire EXT_SIGN;                  // ExtSign
    wire JAL_SIGN;                  // JalSign
    wire [2:0] ALU_OP;              // ALUOp
    wire JUMP;                      // Jump
    wire [3:0] ALU_CTR_OUT;         // ALUCtrOut
    wire SHAMT_SIGN;                // ShamtSign
    wire JR_SIGN;                   // JrSign
    wire [31:0] REG_OUT1;           // Reg output1 (rs)
    wire [31:0] REG_OUT2;           // Reg output2 (rt)
    wire [31:0] ALU_INPUT1;        // ALU input1
    wire [31:0] ALU_INPUT2;        // ALU input2
    wire [31:0] EXT_RES;            // signext RESULT
    wire ALU_OUT_ZERO;              // ALU RESULT zero
    wire [31:0] ALU_RES;            // ALU RESULT  
    wire [4:0] READ_REG1;           // readReg1
    wire [4:0] READ_REG2;           // readReg2
    wire [4:0] WRITE_REG;           // writeReg
    wire [31:0] REG_WRITE_DATA;     // RegWriteData
    wire [31:0] REG_WRITE_DATA_T;   // RegWriteData TEMP
    wire [4:0] WRITE_REG_TEMP;      // WriteRegTEMP
    wire [31:0] PC_IN;              // PC INPUT
    wire [31:0] PC_OUT;             // PC OUTPUT
    wire [31:0] MEM_READ_DATA;      // MemRead Data
    wire [31:0] PC_TEMP1;           // PC TEMP1
    wire [31:0] PC_TEMP2;           // PC TEMP2
    
    // main controller
    Ctr main_controller (
        .opCode(INST[31:26]),
        .regDst(REG_DST),
        .aluSrc(ALU_SRC),
        .memToReg(MEM_TO_REG),
        .regWrite(REG_WRITE),
        .memRead(MEM_READ),
        .memWrite(MEM_WRITE),
        .branch(BRANCH),
        .extSign(EXT_SIGN),
        .jalSign(JAL_SIGN),
        .aluOp(ALU_OP),
        .jump(JUMP)
    );
    
    // ALU controller
    ALUCtr alu_controller (
        .aluOp(ALU_OP),
        .funct(INST[5:0]),
        .aluCtrOut(ALU_CTR_OUT),
        .shamtSign(SHAMT_SIGN),
        .jrSign(JR_SIGN)
    );
    
    // SHAMT_SIGN ? INST[10:6] : REG_OUT1 (rs)
    Mux32 rs_shamt_selector (
        .selectSignal(SHAMT_SIGN),
        .input1({27'b00000000000000000000000000, INST[10:6]}),
        .input2(REG_OUT1),
        .out(ALU_INPUT1)
    );
    
    // EXT_SIGN ? signext(INST[15:0]) : zeroext(INST[15:0])
    signext signExt (
        .extSign(EXT_SIGN),
        .inst(INST[15:0]),
        .data(EXT_RES)
    );
    
    // ALU_SRC ? EXT_RES : REG_OUT2 (rt)
    Mux32 rt_ext_selector (
        .selectSignal(ALU_SRC),
        .input1(EXT_RES),
        .input2(REG_OUT2),
        .out(ALU_INPUT2)
    );
    
    // ALU module
    ALU alu (
        .input1(ALU_INPUT1),
        .input2(ALU_INPUT2),
        .aluCtrOut(ALU_CTR_OUT),
        .zero(ALU_OUT_ZERO),
        .aluRes(ALU_RES)
    );
    
    // REG_DST ? rd : rt
    Mux5 rt_rd_selector (
        .selectSignal(REG_DST),
        .input1(INST[15:11]),
        .input2(INST[20:16]),
        .out(WRITE_REG_TEMP)
    );
    
    // JAL_SIGN ? 31 : (rt or rd)
    Mux5 rtrd_31_selector (
        .selectSignal(JAL_SIGN),
        .input1(5'b11111),
        .input2(WRITE_REG_TEMP),
        .out(WRITE_REG)
    );
    
    // register module
    Registers registers (
        .readReg1(INST[25:21]),
        .readReg2(INST[20:16]),
        .writeReg(WRITE_REG),
        .writeData(REG_WRITE_DATA),
        .regWrite(REG_WRITE & (~JR_SIGN)),
        .clk(clk),
        .reset(reset),
        .readData1(REG_OUT1),
        .readData2(REG_OUT2)
    );
    
    // PC controller module
    PC pc_controller (
        .pcIn(PC_IN),
        .clk(clk),
        .reset(reset),
        .pcOut(PC_OUT)
    );
    
    // instruction memory module
    InstMemory inst_memory (
        .address(PC_OUT),
        .inst(INST)
    );
    
    // data memory module
    DataMemory data_memory (
        .clk(clk),
        .address(ALU_RES),
        .writeData(REG_OUT2),
        .memWrite(MEM_WRITE),
        .memRead(MEM_READ),
        .readData(MEM_READ_DATA)
    );
    
    // MEM_TO_REG ? MEM_READ_DATA : ALU_RES
    Mux32 mem_alu_selector (
        .selectSignal(MEM_TO_REG),
        .input1(MEM_READ_DATA),
        .input2(ALU_RES),
        .out(REG_WRITE_DATA_T)
    );
    
    // JAL_SIGN ? PC_OUT + 4 : REG_WRITE_DATA_T
    Mux32 jal_selector (
        .selectSignal(JAL_SIGN),
        .input1(PC_OUT + 4),
        .input2(REG_WRITE_DATA_T),
        .out(REG_WRITE_DATA)
    );
    
    // BRANCH AND ALU_OUT_ZERO ? BRANCH JUMP : BRANCH NOT JUMP
    Mux32 branch_selector (
        .selectSignal(BRANCH & ALU_OUT_ZERO),
        .input1(PC_OUT + 4 + (EXT_RES << 2)),
        .input2(PC_OUT + 4),
        .out(PC_TEMP1)
    );
    
    // JUMP ? JUMP : ORIGIN PC
    Mux32 jump_selector (
        .selectSignal(JUMP),
        .input1(((PC_OUT + 4) & 32'hf0000000) + (INST[25:0] << 2)),
        .input2(PC_TEMP1),
        .out(PC_TEMP2)
    );
    
    // JR ? JR : ORIGIN PC
    Mux32 jr_selector (
        .selectSignal(JR_SIGN),
        .input1(REG_OUT1),
        .input2(PC_TEMP2),
        .out(PC_IN)
    );
    
endmodule
