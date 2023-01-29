#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED

#include <cstddef>

template <class elemType>
class queue
{
public:
    virtual bool isEmpty() = 0; //�ж϶ӿ�
    virtual elemType getHead() = 0; //����ͷԪ��
    virtual elemType getTail() = 0; //����βԪ��
    virtual void enQueue(const elemType &x) = 0; //����
    virtual elemType deQueue() = 0; //����
    virtual ~queue() {} //����������
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
linkQueue<elemType>::~linkQueue() //�ֵ���Эͬ������
{
    node *tmp;
    while (front != NULL)
    {
        tmp = front;
        front = front->next;
        delete tmp;
    }
} //ʱ�临�Ӷ�O(n)

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
} //ʱ�临�Ӷ�O(1)

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
} //ʱ�临�Ӷ�O(1)



#endif // LINKQUEUE_H_INCLUDED
