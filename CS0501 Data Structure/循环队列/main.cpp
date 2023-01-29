/*
Description
ʵ��һ��ѭ�����У�֧�� enQueue, deQueue, getHead ������
ͬʱҪ�� enQueue ʱ���������β���±�ֵ�Լ�������Ԫ�ظ�����
deQueue ʱ���������ͷ���±�ֵ�Լ�����Ԫ�ظ���
��Ҫ�����Ϊ��ʱ deQueue �����κβ���������Ȼ�����ͷ�±�ֵ�Լ�����Ԫ�ظ�������

Input Format
�� 1 �У�һ������ s ��һ������ n, ���� s ��ʾ���г�ʼ����ռ��С����ʾ���� n �β�����
�� 2 �� n + 1 �У�ÿ��һ��ָ�� op����Ϊ�������������
0 x : enQueue(x)
1 : deQueue()

Output Format
����ÿ�ε��ã����һ�б�ʾ���õĽ����
������Ӳ����������Ӻ��β���±�ֵ�Լ�����Ԫ�ظ�����
���ڳ��Ӳ�����������Ӻ���׵��±�ֵ�Լ�����Ԫ�ظ�����
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
