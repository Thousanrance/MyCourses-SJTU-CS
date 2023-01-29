/*
Description
��Ʋ�ʵ��һ���µ�ջ�֧࣬��O(1)ʱ�临�Ӷȵ�push��pop��top��getMin������
push(x)����x ��ջ��
pop()�����Ѷ�Ԫ�س�ջ��
top()��������ջ��Ԫ��
getMin()������ջ����Сֵ

Input Format
��1�У�һ������n��ʾ��n��ָ�
��2��n+1�У�ÿ��һ��ָ��op����Ϊ����4�������
0 x : push(x)
1 : pop()
2 : top()
3 : getMin()
Output Format
����opΪ2��3�������ÿ������������ص�������
��opΪ1��2��3ʱջ�գ������Empty�����������ţ�

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
    if(Top==NULL||x<=Top->data) //��ջѹ���ǿ�ջ���ݱ�ջ��Сʱѹ��
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

    MinStack A,M; //A�Ǵ���ջ��M����Сֵջ

    for(int i=0;i<times;i++)
    {
        int op;
        scanf("%d",&op);
        long tmp;

        switch(op)
        {
            case 0://Aֱ��ѹ��M����ֱ��ѹ�������գ��ж������Ƿ��ջ��С��С��ѹ��
                    long x;
                    scanf("%ld\n",&x);
                    A.push(x);
                    M.pushh(x);
                    break;
            case 1://��A��ջ������գ������գ��жϵ�����Ԫ���Ƿ����M��ջ����������M��ջ��
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
            case 3://����M��ջ������ջ������ա�
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
