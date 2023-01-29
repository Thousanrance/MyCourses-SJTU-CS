/*
Description
设计并实现一个新的栈类，支持O(1)时间复杂度的push，pop，top，getMin操作：
push(x)——x 入栈；
pop()——堆顶元素出栈；
top()——返回栈顶元素
getMin()——求栈内最小值

Input Format
第1行：一个整数n表示共n条指令；
第2至n+1行：每行一条指令op，分为以下4中情况：
0 x : push(x)
1 : pop()
2 : top()
3 : getMin()
Output Format
对于op为2或3的情况，每行输出操作返回的整数；
若op为1、2或3时栈空，输出“Empty”（不带引号）

Sample Input
10
0 1
0 2
2
3
1
3
1
1
2
3

Sample Output
2
1
1
Empty
Empty
Empty

Limits:
0 < n <= 10^6
0 <= x < 3 * 10^9
*/

#include<cstdio>

class MinStack
{
private:
    struct node
    {
        long data;
        node *next;
        node(const long &x, node *p = NULL)
        {
            data = x;
            next = p;
        }
        ~node(){}
    };
    node *Top;
public:
    MinStack();
    ~MinStack();
    void push(const long &x);
    void pushh(const long &x);
    long pop();
    long top()const;
};

MinStack::MinStack()
{
    Top = NULL;
}

MinStack::~MinStack()
{
    node *tmp;
    while(Top!=NULL)
    {
        tmp=Top;
        Top=Top->next;
        delete tmp;
    }
}

void MinStack::push(const long &x)
{
    Top=new node(x,Top);
}

void MinStack::pushh(const long &x)
{
    if(Top==NULL||x<=Top->data) //空栈压，非空栈数据比栈顶小时压。
    {
       push(x);
    }
}

long MinStack::pop()
{
    if(Top!=NULL)
    {
        node *tmp=Top;
        long x=Top->data;
        Top=Top->next;
        delete tmp;
        return x;
    }
    return -1;
}

long MinStack::top()const
{
    if(Top==NULL)
    {
        return -1;
    }
    return Top->data;
}

int main()
{
    int times;
    scanf("%d",&times);

    MinStack A,M; //A是储存栈，M是最小值栈

    for(int i=0;i<times;i++)
    {
        int op;
        scanf("%d",&op);
        long tmp;

        switch(op)
        {
            case 0://A直接压，M若空直接压，若不空，判断数据是否比栈顶小，小则压。
                    long x;
                    scanf("%ld\n",&x);
                    A.push(x);
                    M.pushh(x);
                    break;
            case 1://若A空栈，输出空，若不空，判断弹出的元素是否等于M的栈顶，等于则M弹栈。
                    tmp=A.pop();
                    if(tmp==-1)
                    {
                        printf("Empty\n");
                    }
                    else if(tmp==M.top())
                    {
                        M.pop();
                    }
                    break;
            case 2:
                    tmp=A.top();
                    if(tmp==-1)
                    {
                        printf("Empty\n");
                    }
                    else
                    {
                        printf("%ld\n",tmp);
                    }
                    break;
            case 3://返回M的栈顶，空栈则输出空。
                    tmp=M.top();
                    if(tmp==-1)
                    {
                        printf("Empty\n");
                    }
                    else
                    {
                        printf("%ld\n",tmp);
                    }
        }
    }
    return 0;
}
