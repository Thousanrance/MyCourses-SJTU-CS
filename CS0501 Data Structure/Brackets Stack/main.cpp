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
    void pusho(const char &x);
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

    if(x==')'&&top()=='(')
    {
        pop();
    }
    else if(x==']'&&top()=='[')
    {
        pop();
    }
    else if(x=='}'&&top()=='{')
    {
        pop();
    }
    else
    {
        push(x);
    }
    //printf("2pushi\n");
}

void BracketsStack::pusho(const char &x)
{
    //printf("1pusho\n");

    if(x=='('&&top()==')')
    {
        pop();
    }
    else if(x=='['&&top()==']')
    {
        pop();
    }
    else if(x=='{'&&top()=='}')
    {
        pop();
    }
    else
    {
        push(x);
    }
    //printf("2pusho\n");
}



int main()
{
    int times;
    scanf("%d",&times);

    BracketsStack A,I,O;

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
                    I.pushi(data);
                    if(I.top()!='#'&&O.top()!='#'&&I.top()==O.top())
                    {
                        //printf("11I'm here\n");
                        I.pop();
                        //printf("12I'm here\n");
                        O.pop();
                        //printf("13I'm here\n");
                    }
                    break;
            case 2:
                    char tmp;
                    tmp=A.pop();
                    //printf("21I'm here\n");
                    O.pusho(tmp);
                    //printf("22I'm here\n");
                    if(I.top()!='#'&&O.top()!='#'&&I.top()==O.top())
                    {
                        //printf("23I'm here\n");
                        I.pop();
                        O.pop();
                        //printf("24I'm here\n");
                    }
                    break;
            case 3:
                    tmp=A.top();
                    if(tmp!='#')
                    {
                        printf("%c\n",A.top());
                    }
                    break;
            case 4:
                    if(I.isEmpty()&&O.isEmpty())
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
        }
    }
    return 0;
}
