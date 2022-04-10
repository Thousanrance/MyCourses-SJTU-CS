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
    void pop();
    char top()const;
    bool isEmpty()const;
    void pushh(const char &x);
    void poph(const char &x);
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

void BracketsStack::pop()
{
    if(Top==NULL)
    {
        return;
    }
    node *tmp;
    tmp=Top;
    char x=Top->data;
    Top=Top->next;
    delete tmp;
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

void BracketsStack::pushh(const char& x)
{
    if(!isEmpty()&&top()=='@')
    {
        push('@');
        return;
    }
    if(isLeft(x))
    {
        push(x);
        return;
    }
    if(isEmpty())
    {
        push('@');
        return;
    }
    char tmp=top();
    if(isPair(tmp,x))
    {
        pop();
    }
    else
    {
        push('@');
    }
}

void BracketsStack::poph(const char& x)
{
    if(!isEmpty()&&top()=='@')
    {
        pop();
        return;
    }
    switch(x)
    {
        case '(':
        case '[':
        case '{':pop();break;
        case ')':push('(');break;
        case ']':push('[');break;
        case '}':push('{');break;
    }
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
                    A.push(data);
                    C.pushh(data);
                    break;
            case 2:
                    char tmp;
                    //printf("21I'm here\n");
                    if(!A.isEmpty())
                    {
                        tmp=A.top();
                        A.pop();
                        C.poph(tmp);
                    }
                    break;
            case 3:
                    if(!A.isEmpty())
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
