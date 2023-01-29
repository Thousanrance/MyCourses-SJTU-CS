# Assignment 2

3.3.2

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1646369969570.png" alt="1646369969570" style="zoom: 80%;" />

答：

1）以a开头，以a结尾，中间是由零个或多个a或b构成的串，所有像这样组成的字符串。

2）由a和b组成的字符串。

3）由a和b组成的字符串，倒数第三个字符固定为a。

4）由a和b组成的字符串，字符串中有且仅有3个b。

5）由a和b组成的字符串，a和b的个数为偶数。



3.3.3

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1646369988823.png" alt="1646369988823" style="zoom:80%;" />

答：

1）n+1

2）n+1

3）n-1

4）
$$
\tbinom{n+1}{2}+1
$$
5）
$$
\sum_{i=1}^n \tbinom{n}{i}
$$


3.3.5

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1646370025285.png" alt="1646370025285" style="zoom:80%;" />

1）

```
other → [bcdfghjklmnpqrstvwxyz]
string → other*a(other|a)*e(other|e)*i(other|i)*o(other|o)*u(other|u)*
```

2）

```
string → a*b*c*……z*
```

3）

```
string → \/\* ( [^*"]* | ".*" | \*+ [^/] ) \*\/
```

8）

```
string → b*(a+b?)*
```

9）

```
string → b* | b*a+ | b*a+ba*
```



3.4.2 

![1646963351702](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1646963351702.png)

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1646976951539.png" alt="1646976951539" style="zoom: 80%;" />