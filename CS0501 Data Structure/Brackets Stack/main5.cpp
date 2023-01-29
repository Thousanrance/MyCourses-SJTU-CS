/*
Description
ģ��һ������ջ����Ԫ������������()��[]��{}��
������Ϊn�Ĳ������У�������Ҫ��������¼��ֲ�����
push
pop��ջ������Դ˲�����
���ջ��Ԫ�أ�ջ������Դ˲�����
ѯ�ʵ�ǰ�����Ƿ�ƥ�䣨ջ������Ϊƥ�䣩
Input Format
��1��һ������n�������ܹ���n�β�����
��2~n+1�У�ÿ��1����������һ��������������࣬���ڲ���1����ͬ�и���һ����ջԪ�ء�

Output Format
����ÿ��ѯ�ʲ��������һ�д���𰸡�
����3�����ջ��Ԫ��
����4��ƥ�������YES��,���������NO��
e.g.
{[()]} ƥ��
{[}] ��ƥ��

Sample Input
6
1 (
1 )
3
4
2
4
Sample Output
)
YES
NO

*/

#include <cstdio>

class BracketsStack
{
private:
    struct node
    {
        char data;
        node *next;
        node(const char &x,node *p=NULL)
        {
            data=x;
            next=p;
        }
        ~node(){};
    };
    node *Top;

public:
    BracketsStack();
    ~BracketsStack();
    void push(const char &x);
    char pop();
    char top()const;
    bool isEmpty()const;
};

BracketsStack::BracketsStack()
{
    Top=NULL;
}

BracketsStack::~BracketsStack()
{
    node *tmp;
    while(Top!=NULL)
    {
        tmp=Top;
        Top=Top->next;
        delete tmp;
    }
}

void BracketsStack::push(const char &x)
{
    Top=new node(x,Top);
}

char BracketsStack::pop()
{
    if(Top!=NULL)
    {
        node *tmp;
        tmp=Top;
        char x=Top->data;
        Top=Top->next;
        delete tmp;
        return x;
    }
    return '#';
}

char BracketsStack::top()const
{
    if(Top!=NULL)
    {
        return Top->data;
    }
    return '#';
}

bool BracketsStack::isEmpty()const
{
    return Top==NULL;
}

bool isPair(char a,char b)
{
    if((a=='('&&b==')')||(a=='['&&b==']')||(a=='{'&&b=='}'))
    {
        return true;
    }
    return false;
}

bool isLeft(char x)
{
    return (x=='('||x=='['||x=='{');
}

bool isRight(char x)
{
    return (x==')'||x==']'||x=='}');
}

int main()
{
    int times;
    scanf("%d",&times);

    BracketsStack A,C;

    int i;
    for(i=0;i<times;i++)
    {
        int op;
        scanf("%d",&op);


        switch(op)
        {
            case 1:
                    char ws;
                    scanf("%c",&ws);
                    char data;
                    scanf("%c",&data);
                    if(A.top()=='#')
                    {
                        if(isLeft(data))
                        {
                            C.push(data);
                        }
                        else
                        {
                            C.push('@');
                        }
                    }
                    else
                    {
                        if(C.top()=='#')
                        {
                            if(isLeft(data))
                            {
                                C.push(data);
                            }
                            else
                            {
                                C.push('@');
                            }
                        }
                        else if(C.top()=='@')
                        {
                            C.push('@');
                        }
                        else
                        {
                            if(isLeft(C.top()))
                            {
                                if(isLeft(data))
                                {
                                    C.push(data);
                                }
                                else
                                {
                                    if(isPair(C.top(),data))
                                    {
                                        C.pop();
                                    }
                                    else
                                    {
                                        C.push('@');
                                    }
                                }
                            }
                        }
                    }
                    A.push(data);
                    break;
            case 2:
                    char tmp;
                    tmp=A.pop();
                    //printf("21I'm here\n");
                    if(tmp!='#')
                    {
                        if(C.top()=='@')
                        {
                            C.pop();
                        }
                        else
                        {
                            switch(tmp)
                            {
                                case ')':C.push('(');break;
                                case ']':C.push('[');break;
                                case '}':C.push('{');break;
                                case '(':C.pop();break;
                                case '[':C.pop();break;
                                case '{':C.pop();break;
                            }
                        }
                    }
                    //printf("22I'm here\n");
                    break;
            case 3:
                    tmp=A.top();
                    if(tmp!='#')
                    {
                        printf("%c\n",A.top());
                    }
                    break;
            case 4:
                    if(C.isEmpty())
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
                    break;
        }
    }
    return 0;
}
