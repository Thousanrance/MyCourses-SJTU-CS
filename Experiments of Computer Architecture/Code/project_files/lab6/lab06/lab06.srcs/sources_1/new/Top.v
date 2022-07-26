`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/24 13:38:09
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
    
    // Instruction Fetch Stage
    reg [31:0] IF_PC;
    wire [31:0] IF_INST;
     
    InstMemory inst_memory(.address(IF_PC), .inst(IF_INST));
    
    // Segment Registers (IF - ID)
    reg [31:0] IF2ID_INST;
    reg [31:0] IF2ID_PC;
    
    // Instruction Decode Stage
    wire [12:0] ID_CTR_SIGNALS;
    wire [3:0] ID_CTR_SIGNAL_ALUOP;
    Ctr main_controller(.opCode(IF2ID_INST[31:26]), 
                        .funct(IF2ID_INST[5:0]), 
                        .nop(IF2ID_INST == 0),
                        .jump(ID_CTR_SIGNALS[12]), 
                        .jrSign(ID_CTR_SIGNALS[11]), 
                        .extSign(ID_CTR_SIGNALS[10]),
                        .regDst(ID_CTR_SIGNALS[9]), 
                        .jalSign(ID_CTR_SIGNALS[8]), 
                        .aluOp(ID_CTR_SIGNAL_ALUOP), 
                        .aluSrc(ID_CTR_SIGNALS[7]), 
                        .luiSign(ID_CTR_SIGNALS[6]),
                        .beqSign(ID_CTR_SIGNALS[5]), 
                        .bneSign(ID_CTR_SIGNALS[4]), 
                        .memWrite(ID_CTR_SIGNALS[3]), 
                        .memRead(ID_CTR_SIGNALS[2]),
                        .memToReg(ID_CTR_SIGNALS[1]), 
                        .regWrite(ID_CTR_SIGNALS[0]));
    
    wire [31:0] ID_REG_READ_DATA_1;
    wire [31:0] ID_REG_READ_DATA_2;
    wire [4:0] WB_WRITE_REG;
    wire [31:0] WB_REG_WRITE_DATA;
    wire WB_CTR_SIGNAL_REG_WRITE;
    Registers registers(.readReg1(IF2ID_INST[25:21]), 
                        .readReg2(IF2ID_INST[20:16]),
                        .writeReg(WB_WRITE_REG), 
                        .writeData(WB_REG_WRITE_DATA), 
                        .regWrite(WB_CTR_SIGNAL_REG_WRITE), 
                        .clk(clk), 
                        .reset(reset),
                        .jalSign(ID_CTR_SIGNALS[8]), 
                        .jalData(IF2ID_PC + 4),
                        .readData1(ID_REG_READ_DATA_1), 
                        .readData2(ID_REG_READ_DATA_2));
    
    wire [31:0] ID_EXT_RES;
    SignExt signext(.extSign(ID_CTR_SIGNALS[10]), 
                    .inst(IF2ID_INST[15:0]), 
                    .data(ID_EXT_RES));
    
    wire [4:0] ID_REG_DEST;
    Mux5 rt_rd_selector(.selectSignal(ID_CTR_SIGNALS[9]), 
                        .input1(IF2ID_INST[15:11]),
                        .input2(IF2ID_INST[20:16]),
                        .out(ID_REG_DEST));
    
    // Segment Registers (ID - EX)
    reg [3:0] ID2EX_CTR_SIGNAL_ALUOP;
    reg [7:0] ID2EX_CTR_SIGNALS;
    reg [31:0] ID2EX_EXT_RES;
    reg [4:0] ID2EX_INST_RS;
    reg [4:0] ID2EX_INST_RT;
    reg [31:0] ID2EX_REG_READ_DATA_1;
    reg [31:0] ID2EX_REG_READ_DATA_2;
    reg [5:0] ID2EX_INST_FUNCT;
    reg [4:0] ID2EX_INST_SHAMT;
    reg [4:0] ID2EX_REG_DEST;
    reg [31:0] ID2EX_PC;
    
    // Execution
    wire [3:0] EX_ALU_CTR_OUT;
    wire EX_SHAMT_SIGNAL;
    ALUCtr alu_controller(.aluOp(ID2EX_CTR_SIGNAL_ALUOP), 
                          .funct(ID2EX_INST_FUNCT),
                          .aluCtrOut(EX_ALU_CTR_OUT), 
                          .shamtSign(EX_SHAMT_SIGNAL));
    
    // -------- SPECIAL DEFINITIONS: FORWARDING -------- // 
    wire [31:0] EX_ALU_INPUT_A_AFTER_FORWARDING;
    wire [31:0] EX_ALU_INPUT_B_AFTER_FORWARDING;
    // ---------- FORWARDING DEFINITIONS END ---------- //
    
    wire [31:0] EX_ALU_INPUT_B;
    Mux32 rt_ext_selector(.selectSignal(ID2EX_CTR_SIGNALS[7]),
                        .input1(ID2EX_EXT_RES),
                        .input2(EX_ALU_INPUT_B_AFTER_FORWARDING),
                        .out(EX_ALU_INPUT_B));
    
    wire [31:0] EX_ALU_INPUT_A;
    wire [31:0] EX_ALU_INPUT_A_TEMP;             
    Mux32 rs_shamt_selector(.selectSignal(EX_SHAMT_SIGNAL),
                          .input1({27'b00000000000000000000000000, ID2EX_INST_SHAMT}),
                          .input2(EX_ALU_INPUT_A_AFTER_FORWARDING),
                          .out(EX_ALU_INPUT_A_TEMP));
    
    Mux32 lui_selector(.selectSignal(ID2EX_CTR_SIGNALS[6]),
                     .input1(32'h00000010),
                     .input2(EX_ALU_INPUT_A_TEMP),
                     .out(EX_ALU_INPUT_A));          
     
    wire EX_ALU_ZERO;
    wire EX_ALU_OVERFLOW;
    wire [31:0] EX_ALU_RES;
    ALU alu(.inputA(EX_ALU_INPUT_A), 
            .inputB(EX_ALU_INPUT_B), 
            .aluCtrOut(EX_ALU_CTR_OUT), 
            .zero(EX_ALU_ZERO), 
            .overflow(EX_ALU_OVERFLOW), 
            .aluRes(EX_ALU_RES));
    
    wire [31:0] BRANCH_DEST = ID2EX_PC + 4 + (ID2EX_EXT_RES << 2);
    
    // Segment Registers (EX - MA)
    reg [3:0] EX2MA_CTR_SIGNALS;
    reg [31:0] EX2MA_ALU_RES;
    reg [31:0] EX2MA_REG_READ_DATA_2;
    reg [4:0] EX2MA_REG_DEST;
    
    // Memory Access
    wire [31:0] MA_MEM_READ_DATA;
    DataMemory data_memory(.clk(clk), 
                           .address(EX2MA_ALU_RES),
                           .writeData(EX2MA_REG_READ_DATA_2),
                           .memWrite(EX2MA_CTR_SIGNALS[3]), 
                           .memRead(EX2MA_CTR_SIGNALS[2]),
                           .readData(MA_MEM_READ_DATA));
    
    wire [31:0] MA_FINAL_DATA;
    Mux32 reg_mem_selector(.selectSignal(EX2MA_CTR_SIGNALS[1]),
                         .input1(MA_MEM_READ_DATA),
                         .input2(EX2MA_ALU_RES),
                         .out(MA_FINAL_DATA));
    
    // Segment Registers (MA - WB)
    reg MA2WB_CTR_SIGNALS;
    reg [31:0] MA2WB_FINAL_DATA;
    reg [4:0] MA2WB_REG_DEST;
    
    // Write Back
    assign WB_WRITE_REG = MA2WB_REG_DEST;
    assign WB_REG_WRITE_DATA = MA2WB_FINAL_DATA;
    assign WB_CTR_SIGNAL_REG_WRITE = MA2WB_CTR_SIGNALS;
    
    // Update PC
    wire [31 : 0] PC_JUMP_END;
    Mux32 jump_selector(.selectSignal(ID_CTR_SIGNALS[12]), 
                      .input1(((IF2ID_PC + 4) & 32'hf0000000) + (IF2ID_INST [25:0] << 2)), 
                      .input2(IF_PC + 4),
                      .out(PC_JUMP_END));
    
    wire [31:0] PC_JR_END;
    Mux32 jr_selector(.selectSignal(ID_CTR_SIGNALS[11]),
                    .input1(ID_REG_READ_DATA_1),
                    .input2(PC_JUMP_END),
                    .out(PC_JR_END));
    
    wire BEQ_BRANCH = ID2EX_CTR_SIGNALS[5] & EX_ALU_ZERO;
    wire [31:0] PC_BEQ_END;
    Mux32 beq_selector(.selectSignal(BEQ_BRANCH),
                     .input1(BRANCH_DEST),
                     .input2(PC_JR_END),
                     .out(PC_BEQ_END));
    
    wire BNE_BRANCH = ID2EX_CTR_SIGNALS[4] & (~ EX_ALU_ZERO);
    wire [31:0] PC_BNE_END;
    Mux32 bne_selector(.selectSignal(BNE_BRANCH),
                     .input1(BRANCH_DEST),
                     .input2(PC_BEQ_END),
                     .out(PC_BNE_END));
    
    wire BRANCH = BEQ_BRANCH | BNE_BRANCH;
    
    // forwarding
    wire [31:0] EX_ALU_INPUT_A_FORWARDING_TEMP;
    wire [31:0] EX_ALU_INPUT_B_FORWARDING_TEMP;
    Mux32 forward_A_selector1(.selectSignal(MA2WB_CTR_SIGNALS & (MA2WB_REG_DEST == ID2EX_INST_RS)),
                            .input1(MA2WB_FINAL_DATA),
                            .input2(ID2EX_REG_READ_DATA_1),
                            .out(EX_ALU_INPUT_A_FORWARDING_TEMP));
                            
    Mux32 forward_A_selector2(.selectSignal(EX2MA_CTR_SIGNALS[0] & (EX2MA_REG_DEST == ID2EX_INST_RS)),
                            .input1(EX2MA_ALU_RES),
                            .input2(EX_ALU_INPUT_A_FORWARDING_TEMP),
                            .out(EX_ALU_INPUT_A_AFTER_FORWARDING));
    
    Mux32 forward_B_selector1(.selectSignal(MA2WB_CTR_SIGNALS & (MA2WB_REG_DEST == ID2EX_INST_RT)),
                            .input1(MA2WB_FINAL_DATA),
                            .input2(ID2EX_REG_READ_DATA_2),
                            .out(EX_ALU_INPUT_B_FORWARDING_TEMP));
                            
    Mux32 forward_B_selector2(.selectSignal(EX2MA_CTR_SIGNALS[0] & (EX2MA_REG_DEST == ID2EX_INST_RT)),
                            .input1(EX2MA_ALU_RES),
                            .input2(EX_ALU_INPUT_B_FORWARDING_TEMP),
                            .out(EX_ALU_INPUT_B_AFTER_FORWARDING));
                         
    // stall
    wire STALL = ID2EX_CTR_SIGNALS[2] & 
                 ((ID2EX_INST_RT == IF2ID_INST [25:21]) | (ID2EX_INST_RT == IF2ID_INST [20:16]));
    
    initial IF_PC = 0;
    
    always @(reset)
    begin
        if (reset) 
        begin
            IF_PC = 0;
            IF2ID_INST = 0;
            IF2ID_PC = 0;
            ID2EX_CTR_SIGNAL_ALUOP = 0;
            ID2EX_CTR_SIGNALS = 0;
            ID2EX_EXT_RES = 0;
            ID2EX_INST_RS = 0;
            ID2EX_INST_RT = 0;
            ID2EX_REG_READ_DATA_1 = 0;
            ID2EX_REG_READ_DATA_2 = 0;
            ID2EX_INST_FUNCT = 0;
            ID2EX_INST_SHAMT = 0;
            ID2EX_REG_DEST = 0;
            EX2MA_CTR_SIGNALS = 0;
            EX2MA_ALU_RES = 0;
            EX2MA_REG_READ_DATA_2 = 0;
            EX2MA_REG_DEST = 0;
            MA2WB_CTR_SIGNALS = 0;
            MA2WB_FINAL_DATA = 0;
            MA2WB_REG_DEST = 0;
        end
    end
    
    always @(posedge clk) 
    begin
    
        
        $display("*************************************************");
        $display("%d %d", STALL, BRANCH);
        $display("PC = %d", IF_PC);
        
        
        // MA - WB
        MA2WB_CTR_SIGNALS <= EX2MA_CTR_SIGNALS [0];
        MA2WB_FINAL_DATA <= MA_FINAL_DATA;
        MA2WB_REG_DEST <= EX2MA_REG_DEST;
        
        
        $display("====== MA - WB ======");
        $display("REG DEST = %d", EX2MA_REG_DEST);
        $display("FINAL DATA = %d", MA_FINAL_DATA);
        $display("REG WRITE = %d", EX2MA_CTR_SIGNALS[0]);
        
        
        // EX - MA
        EX2MA_CTR_SIGNALS <= ID2EX_CTR_SIGNALS [3:0];
        EX2MA_ALU_RES <= EX_ALU_RES;
        EX2MA_REG_READ_DATA_2 <= EX_ALU_INPUT_B_AFTER_FORWARDING;
        EX2MA_REG_DEST <= ID2EX_REG_DEST;
        
        
        $display("====== EX - MA ======");
        $display("CTR SIGNALS = %b", ID2EX_CTR_SIGNALS);
        $display("ALU RES = %d", EX_ALU_RES);
        $display("READ DATA 2 = %d", ID2EX_REG_READ_DATA_2);
        $display("REG DEST = %d", ID2EX_REG_DEST);
        $display("ALU Input (after forwarding) = %d, %d", EX_ALU_INPUT_A_AFTER_FORWARDING, EX_ALU_INPUT_B_AFTER_FORWARDING);
        $display("ALU Input = %d, %d", EX_ALU_INPUT_A, EX_ALU_INPUT_B);
        $display("EX_SHAMT_SIGNAL = %d", EX_SHAMT_SIGNAL);
        
        
        // ID - EX
        if (STALL || BRANCH) 
        begin
            // clean up
            ID2EX_PC <= IF2ID_PC;
            ID2EX_CTR_SIGNAL_ALUOP <= 4'hf;
            ID2EX_CTR_SIGNALS <= 0;
            ID2EX_EXT_RES <= 0;
            ID2EX_INST_RS <= 0;
            ID2EX_INST_RT <= 0;
            ID2EX_REG_READ_DATA_1 <= 0;
            ID2EX_REG_READ_DATA_2 <= 0;
            ID2EX_INST_FUNCT <= 0;
            ID2EX_INST_SHAMT <= 0;
            ID2EX_REG_DEST <= 0;
        end 
        else 
        begin
            ID2EX_PC <= IF2ID_PC;
            ID2EX_CTR_SIGNAL_ALUOP <= ID_CTR_SIGNAL_ALUOP;
            ID2EX_CTR_SIGNALS <= ID_CTR_SIGNALS [7:0];
            ID2EX_EXT_RES <= ID_EXT_RES;
            ID2EX_INST_RS <= IF2ID_INST [25:21];
            ID2EX_INST_RT <= IF2ID_INST [20:16];
            ID2EX_REG_READ_DATA_1 <= ID_REG_READ_DATA_1;
            ID2EX_REG_READ_DATA_2 <= ID_REG_READ_DATA_2;
            ID2EX_INST_FUNCT <= IF2ID_INST [5:0];
            ID2EX_INST_SHAMT <= IF2ID_INST [10:6];
            ID2EX_REG_DEST <= ID_REG_DEST;
        end
        
        
        $display("====== ID - EX ======");
        $display("CTR SIGNALS = %b", ID_CTR_SIGNALS);
        $display("INST = %b", IF2ID_INST);
        $display("ID_REG_READ_DATA_1 = %d", ID_REG_READ_DATA_1);
        $display("ID_REG_READ_DATA_2 = %d", ID_REG_READ_DATA_2);
        $display("ID2EX inst rs = %d, rt = %d", ID2EX_INST_RS, ID2EX_INST_RT);
        $display("ID2EX_PC = %d", ID2EX_PC);
        $display("ID2EX_EXT_RES = %d", ID2EX_EXT_RES);
        $display("Branch Dest = %d", BRANCH_DEST);
        
        
        // IF - ID
        if (! STALL)
            IF_PC <= PC_BNE_END;
        if (BRANCH || ID_CTR_SIGNALS[12] || ID_CTR_SIGNALS[11]) 
        begin
            IF2ID_INST <= 0;
            IF2ID_PC <= 0;
        end 
        else if (!STALL) 
        begin
            IF2ID_INST <= IF_INST;
            IF2ID_PC <= IF_PC;
        end
        
        
        $display("====== IF - ID ======");
        $display("INST = %b", IF_INST);
        $display("%d %d %d %d", PC_JUMP_END, PC_JR_END, PC_BEQ_END, PC_BNE_END);
        
        
    end
    
endmodule
