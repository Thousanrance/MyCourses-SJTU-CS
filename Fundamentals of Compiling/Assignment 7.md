# Assignment 7

6.1.1

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651208667831.png" alt="1651208667831" style="zoom:80%;" />

答：

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651211127978.png" alt="1651211127978" style="zoom:80%;" />



6.2.1

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651208706597.png" alt="1651208706597" style="zoom:80%;" />

答：

（1）

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651211146810.png" alt="1651211146810" style="zoom:80%;" />

（2）

|      | op   | arg1 | arg2 | result |
| ---- | ---- | ---- | ---- | ------ |
| 0    | +    | b    | c    | t1     |
| 1    | -    | t1   |      | t2     |
| 2    | +    | a    | t2   | t3     |

（3）

|      | op   | arg1 | arg2 |
| ---- | ---- | ---- | ---- |
| 0    | +    | b    | c    |
| 1    | -    | (0)  |      |
| 2    | +    | a    | (1)  |

（4）

|      | op   | arg1 | arg2 |
| ---- | ---- | ---- | ---- |
| 0    | +    | b    | c    |
| 1    | -    | (0)  |      |
| 2    | +    | a    | (1)  |

|      | instruction |
| ---- | ----------- |
| 0    | (0)         |
| 1    | (1)         |
| 2    | (2)         |



6.2.2

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651208729490.png" alt="1651208729490" style="zoom:80%;" />

(2)

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651208747165.png" alt="1651208747165" style="zoom:80%;" />

答：

抽象语法树

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651211733251.png" alt="1651211733251" style="zoom:80%;" />

四元式序列

|      | op   | arg1 | arg2 | result |
| ---- | ---- | ---- | ---- | ------ |
| 0    | *    | b    | c    | t1     |
| 1    | *    | b    | d    | t2     |
| 2    | -    | t1   | t2   | t3     |
| 3    | []=  | a    | i    | t4     |
| 4    | =    | t3   |      | t4     |

三元式序列

|      | op   | arg1 | arg2 |
| ---- | ---- | ---- | ---- |
| 0    | *    | b    | c    |
| 1    | *    | b    | d    |
| 2    | -    | (0)  | (1)  |
| 3    | []=  | a    | i    |
| 4    | =    | (3)  | (2)  |

间接三元式序列

|      | op   | arg1 | arg2 |
| ---- | ---- | ---- | ---- |
| 0    | *    | b    | c    |
| 1    | *    | b    | d    |
| 2    | -    | (0)  | (1)  |
| 3    | []=  | a    | i    |
| 4    | =    | (3)  | (2)  |

|      | instruction |
| ---- | ----------- |
| 0    | (0)         |
| 1    | (1)         |
| 2    | (2)         |
| 3    | (3)         |
| 4    | (4)         |



6.3.1

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1651208778827.png" alt="1651208778827" style="zoom:80%;" />

答：

| line | 标识符 | 类型     | 相对地址 | Evn  |
| ---- | ------ | -------- | -------- | ---- |
| 1    | x      | float    | 0        | 1    |
| 2    | x      | float    | 0        | 2    |
| 2    | y      | float    | 8        | 2    |
| 2    | p      | record() | 8        | 1    |
| 3    | tag    | int      | 0        | 3    |
| 3    | x      | float    | 4        | 3    |
| 3    | y      | float    | 12       | 3    |
| 3    | q      | record() | 24       | 1    |

