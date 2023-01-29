#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include<iostream>

using namespace std;

template <class elemType>
class listt
{
public:
    //create()������Ĺ��캯��ʵ�֡�
    virtual int length()const = 0;
    virtual int searchh(const elemType &x)const = 0 ;
    virtual elemType visit(int i)const = 0;
    virtual void insertt(int i, const elemType &x) = 0;
    virtual void removee(int i) = 0;
    virtual void clearr() = 0;
    virtual void reversee() = 0;
    virtual void traverse()const = 0;
    virtual ~listt(){}; //ע��۲죺��������������ֹ�ڴ�й©����û�й��캯����
};

class OutOfBound{};

template <class elemType>
class linkList: public listt<elemType>
{
private:
    struct node //��Ƕ��
    {
        elemType data;
        node *next;
        node(const elemType &x, node *p = NULL)
        {
            data = x;
            next = p;
        }
        node( ):next(NULL){} //ע����2�����캯����ǰ�����ڹ��������㣬�������ڹ���ͷ��㡣
        ~node(){}
    };
    node *head; //ע�⣡
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
    node *p=head->next; //ָ���׽��
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
    node *p = head->next; //�׽��
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
void linkList<elemType>::insertt(int i, const elemType &x) //ע��5��ԭ��
{
    if(i<0)
    {
        throw OutOfBound{};
    }
    node *tmp;
    node *p=head; //pָ��ͷ���
    for(int j = 0; p && j < i-1; ++j)
    {
        p = p->next;
    }
    if(!p)
    {
        throw OutOfBound{};
    } //��i��λ�ò�����
    tmp = new node(x, p->next); //new+��װ�Լ�������һ���
    p->next = tmp; //���ͷ������ã��²�����ǰ��Զ����һ�����
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
    } //��i��λ��Ԫ�ز�����
    tmp = p->next;
    p->next = tmp->next; //��ʱ��i��λ�õ�Ԫ�ص�next��ָ���һ��Ԫ�أ���ǰһ��Ԫ�ص�next�Ѳ�ָ������
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
    node *p=head; //pָ��ͷ���
    for(int j = 0; p && j < i-1; ++j)
    {
        p = p->next;
    }
    if(!p)
    {
        throw OutOfBound{};
    } //��i��λ�ò�����
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
