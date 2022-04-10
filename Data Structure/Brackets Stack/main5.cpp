/*
Description
模拟一个括号栈，其元素是三种括号()、[]、{}。
给出长为n的操作序列，按序列要求完成以下几种操作：
push
pop（栈空则忽略此操作）
输出栈顶元素（栈空则忽略此操作）
询问当前括号是否匹配（栈空则认为匹配）
Input Format
第1行一个整数n，代表总共有n次操作。
第2~n+1行，每行1个整数，第一个数代表操作种类，对于操作1，在同行给定一个入栈元素。

Output Format
对于每次询问操作，输出一行代表答案。
操作3：输出栈顶元素
操作4：匹配输出“YES”,否则输出“NO”
e.g.
{[()]} 匹配
{[}] 不匹配

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
