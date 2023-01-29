#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED

#include <iostream>

using namespace std;

template <class elemType>
class stackk
{
public:
    virtual bool isEmpty()const = 0;
    virtual elemType top()const = 0;
    virtual void push(const elemType &x) = 0;
    virtual elemType pop() = 0;
    virtual ~stackk(){}
};

class illegalSize{};
class outOfBound{};

template <class elemType>
class seqStack: public stackk<elemType>
{
private:
    elemType *elem;
    int Top;
    int maxSize;
    void doubleSpace();
public:
    seqStack(int initSize = 10);
    ~seqStack();
    bool isEmpty()const;
    elemType top()const;
    elemType pop();
    void push(const elemType &x);
};

template <class elemType>
seqStack<elemType>::seqStack(int initSize)
{
    elem = new elemType[initSize];
    if(!elem)
    {
        throw illegalSize();
    }
    maxSize = initSize ;
    Top = -1;
}

template <class elemType>
seqStack<elemType>::~seqStack()
{
    delete [] elem;
}

template <class elemType>
bool seqStack<elemType>::isEmpty()const
{
    return (Top == -1);
}

template <class elemType>
elemType seqStack<elemType>::top()const
{
    if(Top==-1)
    {
        throw outOfBound();
    }
    return elem[Top];
}

template <class elemType>
elemType seqStack<elemType>::pop()
{
    if(Top==-1)
    {
        throw outOfBound();
    }
    return elem[Top--];
}

template <class elemType>
void seqStack<elemType>::push(const elemType &x)
{
    if(top == maxSize - 1)
    {
        doubleSpace();
    }
	elem[++Top] = x;
}

template <class elemType>
void seqStack<elemType>::doubleSpace()
{
    elemType *tmp = elem;
    elem = new elemType[2 * maxSize];
    for(int i = 0; i < maxSize; ++i)
    {
        elem[i] = tmp[i];
    }
    maxSize *= 2;
    delete [] tmp;
}

#endif // SEQSTACK_H_INCLUDED
