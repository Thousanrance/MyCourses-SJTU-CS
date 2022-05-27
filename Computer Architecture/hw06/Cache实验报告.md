# Cache实验

## Exercise 1: Cache Visualization

### 场景1

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652689196077.png" alt="1652689196077" style="zoom:80%;" />

+ Cache 命中率是多少？
  + 0%
+ 为什么会出现这个 cache 命中率？
  + array大小为128 byte，可存 32 个int。数据块大小为 8 bytes，cache 一共有 4 个数据块，即cache的大小为 32 byte，一个block里面可存2个int，最多可存8个int。访问步长为 8，即下一次访问的int不在cache内。由于使用直接映射，每次访问都会映射到cache中的同一个block，因此每一次访问都会替换掉上一次访问的block，所以每次访问都会miss。
+ 增加 Rep Count 参数的值，可以提高命中率吗? 为什么?
  + 不可以。因为相邻两次访问的地址相差 32 byte = cache的大小，由于使用直接映射，每次访问都会映射到cache中的同一个block，因此每一次访问都会替换掉上一次访问的cache，所以命中率一直为0。
  + rep count = 8 时：

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652689430053.png" alt="1652689430053" style="zoom:80%;" />

+ 为了最大化 hit rate， 在不修改 cache 参数的情况下，如何修改程序中的参数（program parameters ）？
  + 修改 array size 为 32 byte，此时cache中的block不会因为后续访问被替换，只有第一次访问时会miss，后续访问均会命中。所以只要增大重复次数，当重复次数足够大时，命中率趋于100%。

  <img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652693073344.png" alt="1652693073344" style="zoom:80%;" />

  ![1652693021810](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652693021810.png)

### 场景2

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652693386504.png" alt="1652693386504" style="zoom:80%;" />

+ Cache 命中率是多少？
  + 75%
+ 为什么会出现这个 cache 命中率？
  + array大小为 256 byte，可存 64 个 int。数据块大小为 16 bytes，cache 一共有 16 个数据块，即cache的大小为 256 byte，一个block里面可存 4 个int，最多可存个 64 int。由于使用 4 路组相联映射，步长为2，故cache中每个block对应的内存空间被连续访问4次，只有第一次访问会miss，后续访问全部hit。
+ 增加 Rep Count 参数的值，例如重复无限次，命中率是多少? 为什么?
  + 命中率趋于100%。因为cache的空间可以容纳整个数组，第一次miss后不会再发生cache替换，所以后续的访问全部hit。

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652693993828.png" alt="1652693993828" style="zoom:80%;" />

### 场景3

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652694321408.png" alt="1652694321408" style="zoom:80%;" />

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652694348363.png" alt="1652694348363" style="zoom:80%;" />

+ L1 cache 和 L2 cache 的命中率分别为多少？

  + 50%
  + 0%

+ 总共访问了 L1 cache 几次？ L1 Miss 次数为多少？

  + 32次
  + 16次

+ 总共访问了 L2 cache 几次？

  + 16次

+ 哪一个程序参数（寄存器 a0 ~ a3）可以增加 L2 hit rate, 并且保持 L1 hit rate 不变？

  + a2：rep count

  <img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652694581923.png" alt="1652694581923" style="zoom:80%;" />

+ 如果将 L1 cache 中的块数增加， L1 、 L2 hit rate 有什么变化 ？

  + 没有变化

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652694985410.png" alt="1652694985410" style="zoom:80%;" />

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652695007979.png" alt="1652695007979" style="zoom:80%;" />



<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652695033260.png" alt="1652695033260" style="zoom:80%;" />

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652695055896.png" alt="1652695055896" style="zoom:80%;" />

+ 如果将 L1 cache 中的块大小增加，L1 、 L2 hit rate 有什么变化 ？
  + L1变大，L2没有变化

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652694788301.png" alt="1652694788301" style="zoom:80%;" />

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652694846262.png" alt="1652694846262" style="zoom:80%;" />



<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652694880815.png" alt="1652694880815" style="zoom:80%;" />

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652694903249.png" alt="1652694903249" style="zoom:80%;" />

## Exercise 2: Loop Ordering and Matrix Multiplication

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652695855649.png" alt="1652695855649" style="zoom:80%;" />

+ 1000-1000 的矩阵相乘，哪种嵌套顺序性能最好？哪种嵌套顺序性能最差？
  + ikj最好，kji最差。
+ 教材《深入理解计算机系统》（CSAPP 3e 中文版 P449） 分析了 6 个版本的矩阵乘法最内层循环中的 cache miss 次数， 如下图所示。和你观察到的结果一致吗？最内层循环中数据访问的步长是怎么影响性能的？
  + 一致。
  + 最内层循环中数据访问的步长越短，性能越高。

+ 参考如下代码（CSAPP 3e 中文版 P448），修改 matrixMultiply.c，再次观察程序的性能是否有改善（浮点运算吞吐率 Gflops/s），从中你得到哪些经验？
  + 有改善，但很少。
  + 将某层循环之前将在该层循环中要使用但是不变的量保存在寄存器中，可以在一定程度上提高程序性能。

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652697003482.png" alt="1652697003482" style="zoom:80%;" />

+ 教材《深入理解计算机系统》（CSAPP 3e 中文版 P449）在 Intel core i7 处理器上分析了 6 个版本的矩阵乘法的性能，可以发现：当矩阵大小为 700*700时，最块的版本比最慢的版本快超过 30 倍，在图 6-45 中的分析可以看出：这两种算法的 cache 失效率相差的倍数仅为 4 倍，为什么实际运算性能会差距如此大？
  + 预取硬件可以识别出步长为1的访问模式，提前将内存中的内容缓存，进一步提高命中率。

## Exercise 3: Cache Blocking and Matrix Transposition

```c
void transpose_blocking(int n, int blocksize, int *dst, int *src)
{
    // YOUR CODE HERE
    int block_n = (n-1)/blocksize + 1;
    for(int bx = 0; bx < block_n; bx++)
    {
        for(int by = 0; by < block_n; by++)
        {
            for(int y = by * blocksize; y < (by + 1) * blocksize && y < n; y++)
            {
                for(int x = bx * blocksize; x < (bx + 1) * blocksize && x < n; x++)
                {
                    dst[y + x * n] = src[x + y * n];
                }
            }
        }
    }
}
```

### Part 1: 改变矩阵的大小

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652698329890.png" alt="1652698329890" style="zoom:80%;" />

| n             | 100   | 500   | 1000  | 2000   | 5000    | 10000   |
| ------------- | ----- | ----- | ----- | ------ | ------- | ------- |
| naive         | 0.003 | 0.193 | 1.399 | 31.769 | 317.136 | 25711.8 |
| with blocking | 0.006 | 0.227 | 1.508 | 7.645  | 46.062  | 2946.5  |

+ 将 blocksize 固定为 20，n 分别设置为 100，500，1000，2000，5000 和 10000。矩阵分块实现矩阵转置是否比不用矩阵分块的方法快? 为什么矩阵大小要达到一定程度，矩阵分块算法才有效果？
  + n较小时，分块转置并没有明显比不分块更快，只有当矩阵大小增大到一定大时，分块才明显比不分块快。
  + n较小时，原始矩阵可以完整或大部分放入缓存之中，因此分块的性能提升不大。

### Part 2: 改变分块大小（Blocksize）

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652699385743.png" alt="1652699385743" style="zoom:80%;" />

| Blocksize     | 50      | 100     | 200     | 500    | 1000   | 5000    |
| ------------- | ------- | ------- | ------- | ------ | ------ | ------- |
| naive         | 311.194 | 312.432 | 306.902 | 310.0  | 320.67 | 313.74  |
| with blocking | 53.288  | 49.975  | 50.613  | 46.543 | 60.799 | 303.716 |

+ 将 n 的值固定为 5000, 将 blocksize 设置为 50，100，200，500，1000，5000 分别多次运行 transpose 程序. 当blocksize 增加时性能呈现什么变化趋势? 为什么?
  + 因虚拟机自身性能问题，n固定为10000时运行结果误差较大，故将n置为5000。
  + 性能先提高后降低。blocksize过小时，缓存块中的数据不能被充分利用；blocksize过大时，单个块无法被完整缓存，就需要进行缓存替换。

## Exercise 4: Memory Mountain

+ 请罗列出运行结果。

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652699813747.png" alt="1652699813747" style="zoom:80%;" />

+ 程序运行所在的系统，一级高速缓存、二级高速缓存的大小分别为多大？ 有三级高速缓存吗？ 如果有，容量为多少？
  + 一级高速缓存为32KB，二级高速缓存为256KB，三级高速缓存为4MB。

![1652700619119](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652700619119.png)

+ 查看系统中高速缓存的配置，并截图。对比一下你的判断是否和系统配置一致。
  + 一级指令高速缓存为32768B = 32KB，一级数据缓存为32KB；二级高速缓存为262144B = 256KB；三级高速缓存为8388608B = 8MB。

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652700182440.png" alt="1652700182440" style="zoom:80%;" />

+ 继续观察程序运行结果，固定工作集大小，模仿下图，例如数组长度为 4MB，观察步长从 1 变化到 15 的情况下读数据的吞吐率。回答问题：高速缓存的块大小（block size）是多少？ 为什么？ 
  + 块大小为 64 byte。
  + 从图中可以看出，当步长达到8之后，继续增大步长，吞吐率变化率小。

<img src="C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1652701340842.png" alt="1652701340842" style="zoom:80%;" />