# Assignment 1

![1645770838971](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1645770838971.png)

答：编译器可以阅读用源语言编写的程序，并把该程序翻译成为一个等价的、用目标语言编写的程序。

解释器是一种另一种常见的语言处理器。它不通过翻译的方式生成目标程序。从用户的角度看，解释器直接利用用户提供的输入执行源程序中指定的操作。



![1645770804488](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1645770804488.png)

答：在把用户输入映射成为输出的过程中，编译器产生的机器语言目标程序执行得比解释器快很多。但是解释器的错误诊断效果通常比编译器更好，因为它逐个语句地执行源程序。



![1645766998386](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1645766998386.png)

解：

1）S → S S * → S S + S * → a S + S * → a a + S * → a a + a *

2）<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1645768377678.png" alt="1645768377678" style="zoom:50%;" />

3）L = {由数字、加号、乘号组成的后缀表达式}

证明：该文法的终结符号包括 a + *；且加号和乘号均为二元运算符，在文法中写在二元末尾，说明生成的是后缀表达式。



![1645768718566](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1645768718566.png)

解：

语法翻译方案为：

```python
expr → {print('+')} expr + term
      |{print('-')} expr - term
      |term
term → {print('*')} term * factor
      |{print('/')} term / factor
      |factor
factor → {print(digit)} digit
```

注释分析树如下：

9-5+2

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1645770633460.png" alt="1645770633460" style="zoom: 80%;" />



9-5*2

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1645770669507.png" alt="1645770669507" style="zoom: 80%;" />