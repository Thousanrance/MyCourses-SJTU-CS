#ifndef DLINKLIST_H_INCLUDED
#define DLINKLIST_H_INCLUDED

#include<iostream>

using namespace std;

template <class elemType>
class dLinkList
{
private:
    struct node //内嵌类
    {
        elemType data;
        node *prev,*next;
        node(const elemType &x, node *p = NULL, node *n = NULL)
        {
            data = x;
            prev = p;
            next = n;
        }
        node( ):next(NULL),prev(NULL){} //注意有2个构造函数，前者用于构造链表结点，后者用于构造头结点。
        ~node(){}
    };
    node *head,*tail; //注意！
    int currentLength;
    node *movee(int i)const;
public:
    dLinkList();
    void clearr();
    ~dLinkList()
    {
        clearr();
        delete head;
    }
    int length()const;
    int searchh(const elemType &x)const;
    elemType visit(int i)const;
    void insertt(int i, const elemType &x);
    void removee(int i);
    void traverse()const;
};

class OutOfBound{};

template <class elemType>
dLinkList<elemType>::dLinkList()
{
    head=new node();
    head->next=tail=new node();
    tail->prev=head;
    currentLength=0;
}

template <class elemType>
dLinkList<elemType>::node *dLinkList<elemType>::movee(int i)const //因为node是内嵌类，所以node类型名前要加dLinkList类型声明
{
    if(i<0)
    {
        throw OutOfBound{};
    }
    node *p=head;
    while(i-->=0)
    {
        p=p->next;
    }
    return p;
}

template <class elemType>
int dLinkList<elemType>::length()const
{
    int count=0;
    node *p=head->next; //指向首结点
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

template <class elemType>
int dLinkList<elemType>::searchh(const elemType &x)const
{
    node *p=head->next;
    int i;
    for(i=0;p!=tail&&p->data!=x;i++)
    {
        p=p->next;
    }
    if(p==tail)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

template <class elemType>
void dLinkList<elemType>::insertt(int i, const elemType &x) //注意5个原则
{
    if(i<0)
    {
        throw OutOfBound{};
    }
    node *tmp,*pos;
    pos=movee(i);
    if(!pos)
    {
        throw OutOfBound{};
    } //第i个位置不存在
    tmp=new node(x,pos->prev,pos);
    pos->prev->next=tmp;
    pos->prev=tmp;
    currentLength++;
}

template <class elemType>
void dLinkList<elemType>::removee(int i)
{
    if(i<0)
    {
        throw OutOfBound{};
    }
    node *pos;
    pos=movee(i);
    if(!p||!p->next)
    {
        throw OutOfBound{};
    } //第i个位置元素不存在
    pos->prev->next=pos->next;
    pos->next->prev=pos->prev;
    delete pos;
    currentLength--;
}

template <class elemType>
void dLinkList<elemType>::clearr()
{
    node *p=head->next,*q;
    head->next=tail;
    tail->prev=head;
    while(p!=tail)
    {
        q=p->next;
        delete p;
        p=q;
    }
    currentLength=0;
}

template <class elemType>
elemType dLinkList<elemType>::visit(int i)const
{
    if(i<0)
    {
        throw OutOfBound{};
    }
    node *p=movee(i);
    if(!p)
    {
        throw OutOfBound{};
    } //第i个位置不存在
    return p->data;
}

template <class elemType>
void dLinkList<elemType>::traverse()const
{
    node* p;
    p=head->next;
    cout<<endl;
    while(p!=tail)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}

#endif // DLINKLIST_H_INCLUDED
