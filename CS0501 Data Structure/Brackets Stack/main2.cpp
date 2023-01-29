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
    void pushh(const char &x);
    bool isPair();
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
        //printf("pop:%c\n",x);
        Top=Top->next;
        delete tmp;
        return x;
    }
    //printf("pop:empty\n");
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

void BracketsStack::pushh(const char &x)
{
    //printf("1pushh\n");
    //printf("x=%c\n",x);
    //printf("top=%c\n",top());

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
    //printf("2pushh\n");
}

bool BracketsStack::isPair()
{
    BracketsStack C;
    //printf("C is created\n");
    node *tmp=Top;
    while(tmp!=NULL)
    {
        //printf("checking:%c\n",tmp->data);
        C.pushh(tmp->data);
        tmp=tmp->next;
    }
    //printf("checking over\n");
    if(C.isEmpty())
    {
        //printf("checking:pair\n");
        return true;
    }
    //printf("checking:no pair\n");
    return false;
}

int main()
{
    //printf("main2\n");
    int times;
    scanf("%d",&times);

    BracketsStack A;

    int i;
    for(i=0;i<times;i++)
    {
        int op;
        scanf("%d",&op);
        int num=0;

        switch(op)
        {
            case 1:
                    char ws;
                    scanf("%c",&ws);
                    char data;
                    scanf("%c",&data);
                    A.push(data);
                    num++;
                    break;
            case 2:
                    A.pop();
                    num--;
                    break;
            case 3:
                    char tmp;
                    tmp=A.top();
                    if(tmp!='#')
                    {
                        printf("%c\n",A.top());
                    }
                    break;
            case 4:
                    if(num%2==0&&A.isPair())
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
