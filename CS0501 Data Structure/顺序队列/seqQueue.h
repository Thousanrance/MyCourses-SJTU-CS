#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED

template <class elemType>
class queue
{
public:
    virtual bool isEmpty() = 0; //判断队空
    virtual elemType getHead() = 0; //读队头元素
    virtual void enQueue(const elemType &x) = 0; //进队
    virtual elemType deQueue() = 0; //出队
    virtual ~queue() {} //虚析构函数
};

template <class elemType>
class seqQueue: public queue<elemType>
{
private:
    elemType *elem;
    int maxSize;
    int front, rear;
    void doubleSpace();
public:
    seqQueue(int size = 10)
    {
    	elem = new elemType[size];
    	maxSize = size;
        front = rear = 0;
    }
    ~seqQueue()
    {
    	delete [] elem;
    }
    bool isEmpty()
    {
    	return front == rear;
    }
    elemType getHead()
    {
    	return elem[(front + 1) % maxSize];
    }
    void enQueue(const elemType &x) ;
    elemType deQueue();
};

template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType *tmp =elem;
    elem = new elemType[2 * maxSize];
    for(int i = 1;i < maxSize;++i)
    {
        elem[i] = tmp[(front + i) % maxSize];
    }
    front = 0;
    rear = maxSize - 1;
    maxSize *= 2;
    delete tmp;
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
    if((rear + 1) % maxSize == front)
    {
        doubleSpace();
    }
    rear = (rear + 1) % maxSize;
    elem[rear] = x;
}

template <class elemType>
elemType seqQueue<elemType>::deQueue()
{
    front = (front + 1) % maxSize;
	return elem[front];
} //注意无队空的判断

#endif // SEQQUEUE_H_INCLUDED
