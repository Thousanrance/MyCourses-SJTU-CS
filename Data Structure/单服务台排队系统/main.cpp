/*
实现一个单服务台排队系统，顾客的到达时间和为每个顾客服务的时间不确定，
按照先到先服务的原则，每个顾客到达系统时需要排队等待至前一位顾客服务完毕，
要求计算每个顾客的平均等待时间。

Input Format
第 1 行：一个整数 n, 表示共有 n 个顾客；

第 2 至 n + 1 行：每行一个整数 t 与一个整数 s，其中 t 表示顾客的到达时刻，s 表示顾客服务所需的时间

Output Format
输出一个浮点数，表示所有顾客在队列中的平均等待时间

*/

#include <cstdio>

int main()
{
    int num;
    scanf("%d",&num);
    int current=0;
    double wait=0;
    int event;

    for(int i=0;i<num;i++)
    {
        int a,s;
        scanf("%d",&a);
        scanf("%d",&s);

        event=a;
        if(event<current)
        {
            wait+=current-event;
        }
        else
        {
            current=event;
        }
        current+=s;
    }
    printf("%.2lf",wait/num);

    return 0;
}
