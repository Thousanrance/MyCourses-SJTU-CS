   .MODEL SMALL
   
   .DATA
   
   .STACK 64
   
   .CODE
   
PortIn	EQU	80h	;定义输入端口号 (2)80h (4)90h
PortOut	EQU	88h	;定义输出端口号 (2)88h (4)0A0H

main proc far
      ;JMP state0 		;测试(3)时取消注释
;(2)(4)
Again:IN  AL,PortIn		;读取开关量状态
      NOT AL			;取反
      OUT PortOut,AL		;送显示
      JMP Again
 
 
;(3)
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
ctrl:        
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
