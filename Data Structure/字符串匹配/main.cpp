#include <cstdio>
#include <cstring>
#include <iostream>

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
    if(Top==NULL)
    {
        return '#';
    }
    node *tmp;
    tmp=Top;
    char x=Top->data;
    Top=Top->next;
    delete tmp;
    return x;
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

void BracketsStack::pushh(const char& x)
{
    char tmp=top();
    if(isPair(tmp,x))
    {
        pop();
    }
    else
    {
        push(x);
    }
}

int main()
{
    char *s=new char [10000];
    std::cin.getline(s,10000,'\n');
    BracketsStack Check;
    int i=0;
    do
    {
        Check.pushh(s[i]);
        i++;
    }while(s[i]!='\0');

    if(Check.isEmpty())
    {

        printf("1");
    }
    else
    {
        printf("0");
    }
    return 0;
}

