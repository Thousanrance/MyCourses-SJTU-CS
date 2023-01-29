

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
    void pushi(const char &x);
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

void BracketsStack::pushi(const char &x)
{
    //printf("1pushi\n");
    //printf("top=%c\n",top());
    //printf("x=%c\n",x);
    if(x==')'&&top()=='(')
    {
        pop();
        //printf("C:()->out\n");
    }
    else if(x==']'&&top()=='[')
    {
        pop();
        //printf("C:[]->out\n");
    }
    else if(x=='}'&&top()=='{')
    {
        pop();
        //printf("C:{}->out\n");
    }
    else
    {
        push(x);
        //printf("C:%c->in\n",x);
    }
    //printf("2pushi\n");
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
                    C.pushi(data);
                    break;
            case 2:
                    char tmp;
                    tmp=A.pop();
                    //printf("21I'm here\n");
                    if(tmp!='#')
                    {
                        if(C.top()=='#')
                        {
                            switch(tmp)
                            {
                                case ')':C.push('(');break;
                                case ']':C.push('[');break;
                                case '}':C.push('{');break;
                            }
                        }
                        else
                        {
                            if(tmp=='('||tmp=='['||tmp=='{')
                            {
                                C.pop();
                            }
                            else
                            {
                                if(C.top()==')'||C.top()==']'||C.top()=='}')
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
                                    }
                                }
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
