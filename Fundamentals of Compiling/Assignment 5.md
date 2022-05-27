# Assignment 5

4.6.2

![1649995110671](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1649995110671.png)

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1649995330271.png" alt="1649995330271" style="zoom: 67%;" />

答：

1、增广文法

```
(0) S' -> S
(1) S -> SS+
(2) S -> SS*
(3) S -> a
```

2、LR(0)项集族

```
I0
S' -> ·S
S -> ·SS+
S -> ·SS*
S -> ·a

I1
S' -> S·
S -> S·S+
S -> S·S*
S -> ·SS+
S -> ·SS*
S -> ·a

I2
S -> a·

I3
S -> SS·+
S -> SS·*
S -> S·S+
S -> S·S*
S -> ·SS+
S -> ·SS*
S -> ·a

I4
S -> SS+·

I5
S -> SS*·
```

3、GOTO函数

```
GOTO(I0, S) = I1	GOTO(I0, a) = I2
GOTO(I1, S) = I3	GOTO(I1, a) = I2	GOTO(I1, $) = acc
GOTO(I3, S) = I3	GOTO(I3, a) = I2	GOTO(I3, +) = I4	GOTO(I3, *) = I5
```

4、语法分析表

FOLLOW(S') = FOLLOW(S) = {+, *, a, $}

| 状态 | ACTION | ACTION | ACTION | ACTION | GOTO |      |      |      |
| ---- | ------ | ------ | ------ | ------ | ---- | ---- | ---- | ---- |
|      | +      | *      | a      | $      | S    | a    | +    | *    |
| 0    |        |        | s2     |        | 1    | 2    |      |      |
| 1    |        |        | s2     | acc    | 3    | 2    |      |      |
| 2    | r3     | r3     | r3     | r3     |      |      |      |      |
| 3    | s4     | s5     | s2     |        | 3    | 2    | 4    | 5    |
| 4    | r1     | r1     | r1     | r1     |      |      |      |      |
| 5    | r2     | r2     | r2     | r2     |      |      |      |      |

这个文法是SLR文法，因为语法分析表中没有重复的条目。



4.6.3

![1649995176272](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1649995176272.png)

答：

|      | 栈     | 符号 | 输入   | 动作 |
| ---- | ------ | ---- | ------ | ---- |
| (1)  | 0      | $    | aa*a+$ | s2   |
| (2)  | 02     | $a   | a*a+$  | r3   |
| (3)  | 01     | $S   | a*a+$  | s2   |
| (4)  | 012    | $Sa  | *a+$   | r3   |
| (5)  | 013    | $SS  | *a+$   | s5   |
| (6)  | 0135   | $SS* | a+$    | r2   |
| (7)  | 0133   | $S   | a+$    | s2   |
| (8)  | 01332  | $Sa  | +$     | r3   |
| (9)  | 01333  | $SS  | +$     | s4   |
| (10) | 013334 | $SS+ | $      | r1   |
| (11) | 01     | $S   | $      | acc  |



4.6.6

![1649995194745](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1649995194745.png)

答：

1、LL(1)

FIRST(SA) = FIRST(A) = {a}，所以该文法不是LL(1)的。

2、SLR(1)

①增广文法

```
(0) S' -> S
(1) S -> SA
(2) S -> A
(3) A -> a
```

②LR(0)项集族

```
I0
S' -> ·S
S -> ·SA
S -> ·A
A -> ·a

I1
S' -> S·
S -> S·A
A -> ·a

I2
S -> A·

I3
A -> a·

I4
S -> SA·
```

③GOTO函数

```
GOTO(I0, S) = I1	GOTO(I0, A) = I2	GOTO(I0, a) = I3
GOTO(I1, A) = I4	GOTO(I1, a) = I3	GOTO(I1, $) = acc
```

④语法分析表

FOLLOW(A) = FOLLOW(S) = {a, $}

| 状态 | ACTION | ACTION | GOTO | GOTO |      |      |
| ---- | ------ | ------ | ---- | ---- | ---- | ---- |
|      | a      | $      | S    | A    | a    | $    |
| 0    | s2     |        | 1    | 2    | 3    |      |
| 1    | s3     | acc    |      | 4    | 3    | acc  |
| 2    | r2     | r2     |      |      |      |      |
| 3    | r3     | r3     |      |      |      |      |
| 4    | r1     | r1     |      |      |      |      |

该文法是SLR(1)，因为语法分析表中没有重复的条目。



4.7.1

![1649995211606](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1649995211606.png)

答：

（1）

```
I0
S' -> ·S,$
S -> ·SS+,$/a
S -> ·SS*,$/a
S -> ·a,$/a

I1
S' -> S·,$
S -> S·S+,$/a
S -> S·S*,$/a
S -> ·SS+,+/*/a
S -> ·SS*,+/*/a
S -> ·a,+/*/a

I2
S -> a·,$/a

I3
S -> SS·+,$/a
S -> SS·*,$/a
S -> S·S+,+/*/a
S -> S·S*,+/*/a
S -> ·SS+,+/*/a
S -> ·SS*,+/*/a
S -> ·a,+/*/a

I4
S -> a·,+/*/a

I5
S -> SS+·,$/a

I6
S -> SS*·,$/a

I7
S -> SS·+,+/*/a
S -> SS·*,+/*/a
S -> S·S+,+/*/a
S -> S·S*,+/*/a
S -> ·SS+,+/*/a
S -> ·SS*,+/*/a
S -> ·a,+/*/a

I8
S -> SS+·,+/*/a

I9
S -> SS*·,+/*/a
```

（2）

```
I0
S' -> ·S,$
S -> ·SS+,$/a
S -> ·SS*,$/a
S -> ·a,$/a

I1
S' -> S·,$
S -> S·S+,$/a
S -> S·S*,$/a
S -> ·SS+,+/*/a
S -> ·SS*,+/*/a
S -> ·a,+/*/a

I24
S -> a·,$/a/+/*

I37
S -> SS·+,$/a/+/*
S -> SS·*,$/a/+/*
S -> S·S+,+/*/a
S -> S·S*,+/*/a
S -> ·SS+,+/*/a
S -> ·SS*,+/*/a
S -> ·a,+/*/a

I58
S -> SS+·,$/a/+/*

I69
S -> SS*·,$/a/+/*
```



4.7.5

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1650010038218.png" alt="1650010038218" style="zoom:67%;" />

答：

1、LR(1)

①增广文法

```
(0) S' -> S
(1) S -> Aa
(2) S -> bAc
(3) S -> Bc
(4) S -> bBa
(5) A -> d
(6) B -> d
```

②LR(1)项集族

```
I0
S' -> ·S,$
S -> ·Aa,$
S -> ·bAc,$
S -> ·Bc,$
S -> ·bBa,$
A -> ·d,a
B -> ·d,c

I1
S' -> S·,$

I2
S -> A·a,$

I3
S -> b·Ac,$
S -> b·Ba,$
A -> ·d,c
B -> ·d,a

I4
S -> B·c,$

I5
A -> d·,a
B -> d·,c

I6
S -> Aa·,$

I7
S -> bA·c,$

I8
S -> bB·a,$

I9
A -> d.,c
B -> d.,a

I10
S -> Bc·,$

I11
S -> bAc·,$

I12
S -> bBa·,$
```

③GOTO函数

```
GOTO(I0, S) = I1  GOTO(I0, A) = I2  GOTO(I0, b) = I3  GOTO(I0, B) = I4  GOTO(I0, d) = I5
GOTO(I2, a) = I6
GOTO(I3, A) = I7  GOTO(I3, B) = I8  GOTO(I3, d) = I9
GOTO(I4, c) = I10
GOTO(I7, c) = I11
GOTO(I8, a) = I12
```

④语法分析表

| 状态 | ACTION | ACTION | ACTION | ACTION | ACTION | GOTO | GOTO | GOTO |
| ---- | ------ | ------ | ------ | ------ | ------ | ---- | ---- | ---- |
|      | a      | b      | c      | d      | $      | S    | A    | B    |
| 0    |        | s3     |        | s5     |        | 1    | 2    | 4    |
| 1    |        |        |        |        | acc    |      |      |      |
| 2    | s6     |        |        |        |        |      |      |      |
| 3    |        |        |        | s9     |        |      | 7    | 8    |
| 4    |        |        | s10    |        |        |      |      |      |
| 5    | r5     |        | r6     |        |        |      |      |      |
| 6    |        |        |        |        | r1     |      |      |      |
| 7    |        |        | s11    |        |        |      |      |      |
| 8    | s12    |        |        |        |        |      |      |      |
| 9    | r6     |        | r5     |        |        |      |      |      |
| 10   |        |        |        |        | r3     |      |      |      |
| 11   |        |        |        |        | r2     |      |      |      |
| 12   |        |        |        |        | r4     |      |      |      |

该文法是LR(1)文法，因为语法分析表中没有重复的条目。

2、LALR(1)

①合并同心集

```
I0
S' -> ·S,$
S -> ·Aa,$
S -> ·bAc,$
S -> ·Bc,$
S -> ·bBa,$
A -> ·d,a
B -> ·d,c

I1
S' -> S·,$

I2
S -> A·a,$

I3
S -> b·Ac,$
S -> b·Ba,$
A -> ·d,c
B -> ·d,a

I4
S -> B·c,$

I59
A -> d·,a/c
B -> d·,c/a

I6
S -> Aa·,$

I7
S -> bA·c,$

I8
S -> bB·a,$

I10
S -> Bc·,$

I11
S -> bAc·,$

I12
S -> bBa·,$
```

②GOTO函数

```
GOTO(I0, S) = I1  GOTO(I0, A) = I2  GOTO(I0, b) = I3  GOTO(I0, B) = I4  GOTO(I0, d) = I59
GOTO(I2, a) = I6
GOTO(I3, A) = I7  GOTO(I3, B) = I8  GOTO(I3, d) = I59
GOTO(I4, c) = I10
GOTO(I7, c) = I11
GOTO(I8, a) = I12
```

③语法分析表

| 状态 | ACTION | ACTION | ACTION | ACTION | ACTION | GOTO | GOTO | GOTO |
| ---- | ------ | ------ | ------ | ------ | ------ | ---- | ---- | ---- |
|      | a      | b      | c      | d      | $      | S    | A    | B    |
| 0    |        | s3     |        | s59    |        | 1    | 2    | 4    |
| 1    |        |        |        |        | acc    |      |      |      |
| 2    | s6     |        |        |        |        |      | 7    | 8    |
| 3    |        |        |        | s59    |        |      |      |      |
| 4    |        |        | s59    |        |        |      |      |      |
| 59   | r5\|r6 |        | r6\|r5 | r3     |        |      |      |      |
| 6    |        |        |        |        | r1     |      |      |      |
| 7    |        |        | s10    |        |        |      |      |      |
| 8    | s11    |        |        |        |        |      |      |      |
| 10   |        |        |        | r2     |        |      |      |      |
| 11   |        |        |        | r4     |        |      |      |      |

该文法不是LALR(1)文法，因为语法分析表中有重复的条目。