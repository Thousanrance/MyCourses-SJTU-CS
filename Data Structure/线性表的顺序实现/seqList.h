#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED

#include<iostream>
using namespace std;

template<class elemType>
class listt
{
public:
    virtual void clearr() = 0;
    virtual int length()const = 0;
    virtual void insertt(int i, const elemType &x) = 0;
    virtual void removee(int i) = 0;
    virtual int searchh(const elemType &x)const = 0;
    virtual elemType visit(int i)const = 0;
    virtual void traverse()const = 0;
    virtual ~listt(){};
};

class OutOfBound{};
class IllegalSize{};

template <class elemType>
class seqList: public listt<elemType>
{
private:
    elemType *data;
    int currentLength;
    int maxSize;
    void doubleSpace();
public:
    seqList(int initSize = 10);
    ~seqList()
    {
        delete [] data;
    }
    int length()const;
    int searchh(const elemType &x)const;
    elemType visit(int i)const;
    void insertt(int i, const elemType &x);
    void removee(int i);
    void clearr();
    void traverse()const;
};

template <class elemType>
seqList<elemType>::seqList(int initSize) //创建
{
    data = new elemType[initSize];
    if(!data)
    {
        throw IllegalSize();
    }
    maxSize = initSize;
    currentLength = 0;
}

template<class elemType>
void seqList<elemType>::doubleSpace() //扩容
{
    elemType *tmp=new elemType[maxSize*2];
    if(!tmp)
    {
        throw IllegalSize();
    }
    for(int j = 0; j < currentLength; ++j)
    {
        tmp[j] = data[j];
    }
    delete []data;
    data = tmp;
    maxSize = maxSize*2;
}

template <class elemType>
int seqList<elemType>::length()const //求长
{
    return currentLength;
}

template <class elemType>
int seqList<elemType>::searchh(const elemType &x)const //查找
{
    int i;

    for(i=0; i<currentLength; i++)
    {
        if (data[i]==x)
        {
            break;
        }
    }
    if(i==currentLength)
    {
        return -1;
    }
    return i;
}

template<class elemType>
elemType seqList<elemType>::visit(int i)const //访问
{
    if(i < 0 || i >= currentLength)
    {
        throw OutOfBound();
    }
    else
    {
        return data[i];
    }
}

template<class elemType>
void seqList<elemType>::insertt(int i, const elemType &x) //插入
{
    if(i < 0 || i > currentLength)
    {
        throw OutOfBound();
    }
    if(currentLength == maxSize)
    {
        doubleSpace();
    }
    for(int j = currentLength; j > i; j--)
    {
        data[j-1] = data[j];
    }
    data[i] = x;
    currentLength++;
}

template<class elemType>
void seqList<elemType>::removee(int i) //删除
{
    if(i < 0 || i >= currentLength)
    {
        throw OutOfBound();
    }
    for(int j = i; j < currentLength-1; j++)
    {
        data[j] = data[j+1];
    }
    currentLength--;
}

template<class elemType>
void seqList<elemType>::clearr() //清空
{
    currentLength = 0;
}

template<class elemType>
void seqList<elemType>::traverse()const
{
    for(int i = 0; i < currentLength; i++)
    {
        cout<<data[i]<<' ';
    }
}

#endif // SEQLIST_H_INCLUDED
