#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED

#include <cstddef>

template <class elemType>
class queue
{
public:
    virtual bool isEmpty() = 0; //判断队空
    virtual elemType getHead() = 0; //读队头元素
    virtual elemType getTail() = 0; //读队尾元素
    virtual void enQueue(const elemType &x) = 0; //进队
    virtual elemType deQueue() = 0; //出队
    virtual ~queue() {} //虚析构函数
};

template <class elemType>
class linkQueue: public queue<elemType>
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL)
        {
        	data = x;
            next = N;
        }
        node():next(NULL){}
        ~node(){}
    };
    node *front, *rear;
public:
    linkQueue()
    {
    	front = rear = NULL;
    }
    ~linkQueue();
    bool isEmpty()
    {
    	return front == NULL;
    }
    elemType getHead()
    {
    	return front->data;
    }
    elemType getTail()
    {
    	return rear->data;
    }
    void enQueue(const elemType &x);
    elemType deQueue();
};

template <class elemType>
linkQueue<elemType>::~linkQueue() //兄弟俩协同工作法
{
    node *tmp;
    while (front != NULL)
    {
        tmp = front;
        front = front->next;
        delete tmp;
    }
} //时间复杂度O(n)

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
    if(rear == NULL)
    {
        front = rear = new node(x);
    }
    else
    {
    	rear->next = new node(x);
    	rear = rear->next;
    }
} //时间复杂度O(1)

template <class elemType>
elemType linkQueue<elemType>::deQueue()
{
    node *tmp = front;
    elemType value = front->data;
    front = front->next;
    if(front == NULL)
    {
        rear = NULL;
    }
    delete tmp;
    return value;
} //时间复杂度O(1)



#endif // LINKQUEUE_H_INCLUDED
