# Assignment Three

Chapter 1

Problems

12. 

![1648118719087](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1648118719087.png)

答：

（a）√

（b）×：AL是 8 位寄存器，97F有12位。

（c）×：立即数不能转移到段寄存器。

（d）√

（e）√

（f）×：立即数不能转移到段寄存器且CS的值不可以随意更改。

（g）√

（h）√

（i）×：CH是8位寄存器，AX是16位寄存器。

（j）×：AX是16位寄存器，23FB9有20位。

（k）×：CS的值不可以随意更改。

（l）×：AX是16位寄存器，DL是8位寄存器。



14. 

![1648118785737](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1648118785737.png)

答：

（a）The logical address is 3499H: 2500H. 

（b）The physical address is (34990 + 2500)H = 36E90H. 

（c）The lower range is 34990H. The upper range is (34990 + FFFF)H = 4498FH. 



19. 

![1648118817054](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1648118817054.png)

答：

If CS = 2700, the lower range is 27000 and the upper range is (27000 + FFFF) = 36FFF. 

The code segment range doesn't include 389F2. 

If the IP must be 1282, the CS must be (389F2 - 1282) >> 1 = 3777. 



31. 

![1648118844450](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1648118844450.png)

答：

（a）SS

（b）DS

（c）CS

（d）DS

（e）SS

（f）ES



33. 

![1648118877285](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1648118877285.png)

答：

（a）CF = 1，PF = 1，AF = 1，ZF = 1，SF = 1

（b）CF = 0，PF = 0，AF = 0，ZF = 0，SF = 1

（c）CF = 0，PF = 1，AF = 1，ZF = 0，SF = 1



34. 

![1648118920483](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1648118920483.png)

![1648118949551](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1648118949551.png)

答：

（a）PA = DS(shifted left) + SI = 24000；FF

（b）PA = DS(shifted left) + SI + BX + 8 = 2A088；25

（c）PA = DS(shifted left) + BX = 26080；FF

（d）PA = DS(shifted left) + DI + 6 = 25006；80

（e）PA = DS(shifted left) + DI + BX + 28 = 2B0A8；91

（f）PA = SS(shifted left) + BP + SI + 10 = 3B010；99

（g）PA = DS(shifted left) + 3600 = 23600；FF

（h）PA = DS(shifted left) + BX + 30 = 260B0；99

（i）PA = SS(shifted left) + BP + 200 = 37200；FF

（j）PA = SS(shifted left) + BP + SI + 10 = 3B010；80

（k）PA = DS(shifted left) + SI + 50 = 24050；25

（l）PA = DS(shifted left) + DI + BP + 100 = 2C100；FF



36. 

![1648118975985](C:\Users\Xiao-PC\AppData\Roaming\Typora\typora-user-images\1648118975985.png)

答：

（a）

DS: 1450	9F

DS: 1451	12

（b）

DS: 2348	63

DS: 2349	8C