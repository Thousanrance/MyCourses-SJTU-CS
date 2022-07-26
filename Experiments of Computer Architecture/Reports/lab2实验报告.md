# Lab2 FPGA基础实验：4-bit Adder

[TOC]

## 实验目的

+ 掌握 Xilinx 逻辑设计工具 Vivado的基本操作
+ 掌握 VerilogHDL进行简单的逻辑设计
+ 使用功能仿真
+ 约束文件的使用和直接写法
+ 生成 Bitstream 文件

## 实验原理

+ 一位全加器

真值表：

| a    | b    | ci   | s    | co   |
| ---- | ---- | ---- | ---- | ---- |
| 0    | 0    | 0    | 0    | 0    |
| 1    | 0    | 0    | 1    | 0    |
| 0    | 1    | 0    | 1    | 0    |
| 1    | 1    | 0    | 0    | 1    |
| 0    | 0    | 1    | 1    | 0    |
| 1    | 0    | 1    | 0    | 1    |
| 0    | 1    | 1    | 0    | 1    |
| 1    | 1    | 1    | 1    | 1    |

输入端与输出端之间的逻辑关系为：
$$
s = a \oplus b \oplus ci \\
co = (a \and b)\or(a\and ci)\or(b\and ci) 
$$


+ 四位全加器

四位全加器由四个一位全加器串联而成：四位全加器的4位的a和b，每1位对应作为一个一位全加器的a和b；四位全加器的ci作为第一个一位全加器的ci，接着，前一个一位全加器的co作为后一个一位全加器的ci，最后一个一位全加器的co作为四位全加器的co；四个一位全加器的s合并为四位全加器的s。

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1650780344901.png" alt="1650780344901" style="zoom:80%;" />

## 实现细节

### 基本设计

+ adder_1bit.v
  + 用Verilog自带的逻辑运算单元xor、and实现输入端到输出端的逻辑转化。
+ adder_4bit.v
  + 实例化4个一位全加器对象，将其各自的输入输出端按照逻辑连接。
+ adder_4bits_tb.v
  + 用4组不同的输入数据测试，通过波形图像检查输出结果是否正确。

### 工程实现

+ 编写顶层激励文件Top.v
+ 添加display IP核
+ 添加约束文件

## 实验结果

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1650777468870.png" alt="1650777468870" style="zoom:80%;" />



## 总结与反思

+ 学到了通过真值表推理输入与输出之间的逻辑关系。
+ 学到了一些Verilog自带的逻辑运算单元的用法。
+ 学到了从”子元件“到组合元件的设计思想。

