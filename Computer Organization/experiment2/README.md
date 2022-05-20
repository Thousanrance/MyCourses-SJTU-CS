# Experiment 2

## Memory extension

+  U10、U11为memory，address从40000h开始
+ 往奇地址写奇数，偶地址写偶数
  + U10为偶地址，U11为奇地址

```
L:     
		MOV BYTE PTR [BX],AL			;将AL中的数据以字节为单位送到DS:BX所指字节单元
		INC AL
		INC BX
		MOV BYTE PTR [BX],AL			
		INC AL
		INC BX
		JNZ L
```

+ 重连电路，使U10、U11的address从80000h开始，还是往奇地址写奇数，偶地址写偶数。
  + 3-8译码器，Addr19取反（加一个非门），右边连Y0

```
		MOV AX,8000H                    ;指定DS开始地址
		MOV DS,AX
		MOV BX,0H
	
		MOV BYTE PTR [BX],0FFH					; 内存中写入0FFh
L:     
		MOV BYTE PTR [BX],AL			
		INC AL
		INC BX
		MOV BYTE PTR [BX],AL			
		INC AL
		INC BX
		JNZ L
```

+ 往两个芯片里写入66BBh（用原来的电路）

```
		MOV AX,4000H                    ;指定DS开始地址
		MOV DS,AX
		MOV BX,0H
		MOV AX,0BBBBH
		MOV DX,6666H
	
		MOV BYTE PTR [BX],0FFH					; 内存中写入0FFh
L:     
		MOV WORD PTR [BX],AX			
		INC BX
		INC BX
		MOV WORD PTR [BX],DX			
		INC BX
		INC BX
		JNZ L
```



## 8255 operations

+ SEGTAB最后一个不对，改成71H（显示F）
+ PC4-PC7的开关状态显示到D1-D4，PC1-PC3的状态转换成16进制数显示到数码管的第一个数。

```
		MOV AL,10001001B
		OUT CtrlPT,AL	

		MOV AL,0FFH
		OUT PortA,AL

L1: 
		 IN AL, PortC
		 MOV BL,AL
		 MOV CL,AL
		 AND BL,00001111B ;PC3-PC0
		 MOV BH,00H
		 MOV SI,BX
		 MOV AL,SEGTAB[SI]
		 OUT PortB,AL
		 
		 AND CL,11110000B ;PC7-PC4
		 OR CL,00001110B ;数码管第1位
		 MOV AL,CL
		 OUT PortA,AL
		 JMP L1
```

+ PC4-PC7的状态转换成16进制数显示到数码管的第一位和第三位，PC0-PC3的状态转换成16进制数显示到数码管的第二位和第四位。PC4-PC7控制D1-D4。

```
		MOV AL,10001001B
		OUT CtrlPT,AL


		MOV AL,0FFH
		OUT PortA,AL

L1: 
		 IN AL, PortC
		 MOV DL,AL
		 
		 AND DL,11110000B ;PC7-PC4
		 OR DL,00001010B ;数码管第1位和第3位
		 MOV AL,DL
		 OUT PortA,AL
		 
		 MOV DH,00H
		 MOV CL,4H
		 SHR DX,CL
		 MOV SI,DX
		 MOV AL,SEGTAB[SI]
		 OUT PortB,AL
		 
		 CALL DELAY
		 
		 IN AL, PortC
		 MOV BL,AL
		 MOV DL,AL
		 
		 AND DL,11110000B ;PC7-PC4
		 OR DL,00000101B ;数码管第2位和第4位
		 MOV AL,DL
		 OUT PortA,AL
		 
		 AND BL,00001111B ;PC3-PC0
		 MOV BH,00H
		 MOV SI,BX
		 MOV AL,SEGTAB[SI]
		 OUT PortB,AL
		 
		 CALL DELAY
		 
		 JMP L1
```