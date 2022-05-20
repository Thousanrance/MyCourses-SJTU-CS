# Experiment 1

## Requirement(2)

>  读取74LS244的状态，取反后，写到74LS273。

+ 74LS244（Device1）带有8位拨位开关，地址为80H or 82H or 84H or 86H
+ 74LS273（Device2）带有8个发光二极管，地址为88H or 8AH or 8CH or 8EH
+ Device1接3-8译码器Y0，Device2接3-8译码器Y1。

```visual basic
   .MODEL SMALL
   
   .DATA
   
   .STACK 64
   
   .CODE
   
PortIn	EQU	80h	;定义输入端口号
PortOut	EQU	88h	;定义输出端口号

main proc far
Again:IN  AL,PortIn		;读取开关量状态
      NOT AL			;取反
      OUT PortOut,AL	;送显示
      JMP Again			;循环跳转执行      
main endp

END				;指示汇编程序结束编译
```



## Requirement(3)

> 用74LS273模拟十字路口的红绿灯。

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651215669798.png" alt="1651215669798" style="zoom:80%;" />

+ 编程序控制LED灯的输出

| state | 意义                   | D7~D0                                       |
| ----- | ---------------------- | ------------------------------------------- |
| 0     | 两个方向都亮红灯       | xx110110B = 36H                             |
| 1     | 南北绿灯亮，东西红灯亮 | xx110011B = 33H                             |
| 2     | 南北绿灯闪，东西红灯亮 | xx110011B = 33H (on)   xx110111B = 37H(off) |
| 2     | 南北黄灯亮，东西红灯亮 | xx110101B = 35H                             |
| 3     | 东西绿灯亮，南北红灯亮 | xx011110B = 1EH                             |
| 4     | 东西绿灯闪，南北红灯亮 | xx011110B = 1EH(on)   xx111110B = 3EH(off)  |
| 4     | 东西黄灯亮，南北红灯亮 | xx101110B = 2EH                             |

```visual basic
   .MODEL SMALL
   
   .DATA
   
   .STACK 64
   
   .CODE
   
PortIn	EQU	80h	;定义输入端口号
PortOut	EQU	88h	;定义输出端口号

main proc far
state0:
      MOV AL,36H
      OUT PortOut,AL
      CALL DELAYLONG
      
state1:
      MOV AL,33H
      OUT PortOut,AL
      CALL DELAYLONG
      
      MOV CX,3
state2:
      ;blink
      MOV AL,33H
      OUT PortOut,AL
      CALL DELAYSHORT
      MOV AL,37H
      OUT PortOut,AL
      CALL DELAYSHORT
      LOOP state2
      
      ;yellow
      MOV AL,35H
      OUT PortOut,AL
      CALL DELAYLONG
      
state3:      
      MOV AL,1EH
      OUT PortOut,AL
      CALL DELAYLONG
      
      MOV CX,3
state4:
      ;blink
      MOV AL,1EH
      OUT PortOut,AL
      CALL DELAYSHORT
      MOV AL,3EH
      OUT PortOut,AL
      CALL DELAYSHORT
      LOOP state4
      
      ;yellow
      MOV AL,2EH
      OUT PortOut,AL
      CALL DELAYLONG
      
      JMP state1			;跳转循环执行           
main endp

DELAYLONG PROC
      PUSH CX
      MOV CX,100000
D0:   LOOP D0
      POP CX
      RET
DELAYLONG ENDP

DELAYSHORT PROC
      PUSH CX
      MOV CX,5000
D1:   LOOP D1
      POP CX
      RET
DELAYSHORT ENDP
      
END				;指示汇编程序结束编译
```



## Requirement(4)

> 如果74LS244的地址是90H~97H，74LS273的地址是0A0H~0A7H，重做Requirement(2)。

+ Device1接3-8译码器Y2，Device2接3-8译码器Y4。

```basic
   .MODEL SMALL
   
   .DATA
   
   .STACK 64
   
   .CODE
   
PortIn	EQU	90h		;定义输入端口号
PortOut	EQU	0A0h	;定义输出端口号

main proc far
Again:IN  AL,PortIn		;读取开关量状态
      NOT AL			;取反
      OUT PortOut,AL	;送显示
      JMP Again			;循环跳转执行      
main endp

END				;指示汇编程序结束编译
```

