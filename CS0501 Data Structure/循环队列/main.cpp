/*
Description
实现一个循环队列，支持 enQueue, deQueue, getHead 操作，
同时要求 enQueue 时可以输出队尾的下标值以及队列内元素个数、
deQueue 时可以输出队头的下标值以及队内元素个数
（要求队列为空时 deQueue 不做任何操作，但仍然输出队头下标值以及队内元素个数）。

Input Format
第 1 行：一个整数 s 与一个整数 n, 其中 s 表示队列初始数组空间大小，表示共有 n 次操作；
第 2 至 n + 1 行：每行一条指令 op，分为以下两种情况：
0 x : enQueue(x)
1 : deQueue()

Output Format
对于每次调用，输出一行表示调用的结果。
对于入队操作，输出入队后队尾的下标值以及队内元素个数；
对于出队操作，输出出队后队首的下标值以及队内元素个数。
*/

#include <cstdio>

class seqQueue
{
private:
    int *elem;
    int num;
    int maxSize;
    int front, rear;
    void doubleSpace();
public:
    seqQueue(int size = 10)
    {
    	elem = new int [size];
    	maxSize = size;
        front = rear = 0;
        num = 0;
    }
    ~seqQueue()
    {
    	delete [] elem;
    }
    bool isEmpty()
    {
    	return front == rear;
    }
    void getHead()
    {
    	printf("%d %d\n",front,num);
    }
    void enQueue(const int &x) ;
    void deQueue();
};

void seqQueue::doubleSpace()
{
    int *tmp =elem;
    elem = new int[2 * maxSize];
    for(int i = 1;i < maxSize;++i)
    {
        elem[i] = tmp[(front + i) % maxSize];
    }
    front = 0;
    rear = maxSize - 1;
    maxSize *= 2;
    delete tmp;
}

void seqQueue::enQueue(const int &x)
{
    if((rear + 1) % maxSize == front)
    {
        doubleSpace();
    }
    rear = (rear + 1) % maxSize;
    elem[rear] = x;
    num++;
    printf("%d %d\n",rear,num);
}

void seqQueue::deQueue()
{
    front = (front + 1) % maxSize;
    num--;
	printf("%d %d\n",front,num);
}

int main()
{
    int s,n;
    scanf("%d",&s);
    scanf("%d",&n);

    seqQueue A(s);

    int op;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&op);
        if(op==0)
        {
            int x;
            scanf("%d",&x);
            A.enQueue(x);
        }
        else
        {
            if(A.isEmpty())
            {
                A.getHead();
            }
            else
            {
                A.deQueue();
            }
        }
    }
}
