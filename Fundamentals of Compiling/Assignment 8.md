# Assignment 8

6.4.3(2)

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651814310411.png" alt="1651814310411" style="zoom:80%;" />

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651814341659.png" alt="1651814341659" style="zoom:80%;" />

答：

语法分析树：

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651817382700.png" alt="1651817382700" style="zoom:80%;" />

三地址代码：

```
 t_1 = i * ai.width
 t_2 = j * aj.width
 t_3 = t_1 + t_2
 t_4 = a[t_3]
 t_5 = i * bi.width
 t_6 = j * bj.width
 t_7 = t_5 + t_6
 t_8 = b[t_7]
 t_9 = t_4 + t_8
 x = t_9
```



6.4.6(2)

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651814379402.png" alt="1651814379402" style="zoom:80%;" />

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651814396136.png" alt="1651814396136" style="zoom:80%;" />

答：

((10 - 1) * 20 + (8 - 1)) * 4 = 748



6.4.8(2)

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651814429328.png" alt="1651814429328" style="zoom:80%;" />

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651814459600.png" alt="1651814459600" style="zoom:80%;" />

答：

((1 - 1) * 5 * 6 + (2 - 0) * 6 + (7 - 5)) * 8 = 112



6.5.2

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651814511042.png" alt="1651814511042" style="zoom:80%;" />

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651814684932.png" alt="1651814684932" style="zoom:80%;" />

答：

```
S -> id = E			gen(top.get(id.lexeme) '=' E.addr);

E -> E1 + E2		E.type = max(E1.type, E2.type);
					a1 = widen(E1.addr, E1.type, E.type);
					a2 = widen(E2.addr, E2.type, E.type);
					E.addr = new Temp();
					gen(E.addr '=' a1 '+' a2);
					
	| -E1			E.addr = new Temp();
					gen(E.addr '=' 'minus' E1.addr);
					
	| (E1)			E.addr = E1.addr;
	
	| id			E.addr = top.get(id.lexeme);
	
	| E1(E2)		E.type = {t|对E2.type中的某个s，s→t在E1.type中}
					E.addr = new Temp();
					gen(E.addr '=' E1.addr '(' E2.addr ')');
```



6.6.1

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651814800234.png" alt="1651814800234" style="zoom:80%;" />

答：

1）

```
S -> repeat S1 while B      S1.next = newlabel()
                            B.true = newlabel()
                            B.false = S.next
                            S.code = label(B.true) || S1.code
                                || label(S1.next) || B.code
```

2）

```
S -> for (S1; B; S2) S3     S1.next = newlabel()
                            B.true = newlabel()
                            B.false = S.next
                            S2.next = S1.next
                            S3.next = newlabel()
                            S.code = S1.code
                                || lable(S1.next) || B.code
                                || lable(B.true) || S3.code
                                || label(S3.next) || S2.code
                                || gen('goto', S1.next)
```

