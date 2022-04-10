#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include<iostream>

using namespace std;

template <class elemType>
class listt
{
public:
    //create()由子类的构造函数实现。
    virtual int length()const = 0;
    virtual int searchh(const elemType &x)const = 0 ;
    virtual elemType visit(int i)const = 0;
    virtual void insertt(int i, const elemType &x) = 0;
    virtual void removee(int i) = 0;
    virtual void clearr() = 0;
    virtual void reversee() = 0;
    virtual void traverse()const = 0;
    virtual ~listt(){}; //注意观察：有析构函数【防止内存泄漏】，没有构造函数。
};

class OutOfBound{};

template <class elemType>
class linkList: public listt<elemType>
{
private:
    struct node //内嵌类
    {
        elemType data;
        node *next;
        node(const elemType &x, node *p = NULL)
        {
            data = x;
            next = p;
        }
        node( ):next(NULL){} //注意有2个构造函数，前者用于构造链表结点，后者用于构造头结点。
        ~node(){}
    };
    node *head; //注意！
public:
    linkList();
    void clearr();
    ~linkList()
    {
        clearr();
        delete head;
    }
    int length()const;
    int searchh(const elemType &x)const;
    elemType visit(int i)const;
    void insertt(int i, const elemType &x);
    void removee(int i);
    void reversee();
    void traverse()const;
};

template <class elemType>
linkList<elemType>::linkList()
{
    head=new node();
}

template <class elemType>
int linkList<elemType>::length()const
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
int linkList<elemType>::searchh(const elemType &x)const
{
    int pos = -1;
    node *p = head->next; //首结点
    while(p)
    {
        pos++;
        if(p->data == x)
        {
            break;
        }
        p = p->next;
    }
    if(!p)
    {
        return -1;
    }
    return pos;
}

template <class elemType>
void linkList<elemType>::insertt(int i, const elemType &x) //注意5个原则
{
    if(i<0)
    {
        throw OutOfBound{};
    }
    node *tmp;
    node *p=head; //p指向头结点
    for(int j = 0; p && j < i-1; ++j)
    {
        p = p->next;
    }
    if(!p)
    {
        throw OutOfBound{};
    } //第i个位置不存在
    tmp = new node(x, p->next); //new+武装自己：二合一语句
    p->next = tmp; //理解头结点作用：新插入结点前永远都有一个结点
}

template <class elemType>
void linkList<elemType>::removee(int i)
{
    if(i<0)
    {
        throw OutOfBound{};
    }
    node *tmp;
    node *p=head;
    for(int j = 0; p && j < i-1; ++j)
    {
        p = p->next;
    }
    if(!p||!p->next)
    {
        throw OutOfBound{};
    } //第i个位置元素不存在
    tmp = p->next;
    p->next = tmp->next; //此时第i个位置的元素的next仍指向后一个元素，但前一个元素的next已不指向它。
    delete tmp;
}

template <class elemType>
void linkList<elemType>::clearr()
{
    head->next=NULL;
}

template <class elemType>
elemType linkList<elemType>::visit(int i)const
{
    if(i<0)
    {
        throw OutOfBound{};
    }
    node *p=head; //p指向头结点
    for(int j = 0; p && j < i-1; ++j)
    {
        p = p->next;
    }
    if(!p)
    {
        throw OutOfBound{};
    } //第i个位置不存在
    return p->next->data;
}

template <class elemType>
void linkList<elemType>::reversee()
{
    node *p,*q;
    p=head->next;
    head->next=NULL;
    while(p)
    {
        q=p->next;
        p->next=head->next;
        head->next=p;
        p=q;
    }
}

template <class elemType>
void linkList<elemType>::traverse()const
{
    node* p;
    p=head->next;
    while(p)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
}

#endif // LINKLIST_H_INCLUDED
