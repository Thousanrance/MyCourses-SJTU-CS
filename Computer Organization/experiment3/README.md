# Experiment 3

## 8255 operations

+ 根据地址译码电路译码，8255是121H ~ 127H，8253是100H ~ 106H。

+ 显示学号
  +  OUT L8255CS,AL（这个指令有错误为什么?——这是因为在OUT指令中直接用数字寻址，端口号只能是0到FFH，应该先把L8255CS地址存入DX，再OUT）

+ 读入PC0的状态，显示到PC6。

## 8253 operations and timer applications

+ 用 Timer0 产生周期为10ms的方波，用 Mode3，16位写。

+ CLK级联，用 Timer0 和 Timer1 产生周期为1s的方波，Timer0 的 OUT 连 Timer1 的 CLK，Timer1用 Mode3，8位写，上一问已经放大到10ms，再放大100倍即可。

## Interrupt application 1

+ 要在INTR_INIT里面把自己定义的中断处理程序n定位到中断向量里面
+ 这里注意切换PC的I/O状态时，PC7的状态就已经改变了，也就是如果每次都读入、取反再输出的话其实，中断前后状态时一样的。为了达到题目要求的效果，就只读入一次，把初始状态存在一个专门的寄存器，每次中断取反输出。
+ 软件中断就在主程序里写代码，硬件中断就注释掉软件中断的代码，按按钮。

## Interrupt application 2

+ 利用指令LCXZ 和 CX寄存器，中断处理程序把CX置为1，显示下一位后将CX置为0。

## Interrupt application 3

+ Timer0 用 Mode0，Timer1 用 Mode3，Timer2 用 Mode2。

## Interrupt application 4

+ 用一个寄存器存总中断次数，编程把中断次数转化为LED显示，就是用AND和SHR来一位一位显示，但效果可能受电脑性能影响，DELAY的时间也会影响。
