#include <iostream>

using namespace std;

template <class Type>
class priorityQueue
{
private:
    int currentSize;
    Type *array;
    int maxSize;
    void doubleSpace();
    void buildHeap( );
    void percolateDown(int hole);
public:
    priorityQueue(int capacity = 100)
    {
        array = new Type[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    priorityQueue(const Type data[], int size);
    ~priorityQueue()
    {
        delete [] array;
    }
    bool isEmpty()const
    {
        return currentSize == 0;
    }
    Type getHead()
    {
        return array[1];
    }
    void enQueue(const Type &x);
    Type deQueue();
};

template <class Type>
void priorityQueue<Type>::doubleSpace()
{
    Type *tmp =array;
    array = new Type[2 * maxSize];
    for(int i = 1;i <= maxSize;++i)
    {
        array[i] = tmp[i];
    }
    maxSize *= 2;
    delete tmp;
}

template <class Type>
void priorityQueue<Type>::enQueue(const Type &x)
{
    if(currentSize == maxSize - 1)
    {
        doubleSpace();
    }
    // 向上过滤
    int hole = ++currentSize; //先不放x
    for(;hole > 1 && x < array[ hole / 2 ];hole /= 2)
    {
        array[hole] = array[hole/2];
    }
    array[hole] = x; //hole == 1 或者 x > array[ hole / 2 ];
}

template <class Type>
void priorityQueue<Type>::percolateDown(int hole)
{
    int child;
    Type tmp = array[hole];
    for(;hole*2<=currentSize;hole=child)
    {
        child=hole*2; //child为最小孩子下标
        if(child != currentSize && array[child + 1] < array[child] )
        {
            child++;
        }
        if(array[child] < tmp)
        {
            array[hole] = array[child];
        }
        else
        {
            break;
        }
    }
    array[hole] = tmp;
}

template <class Type>
Type priorityQueue<Type>::deQueue()
{
    Type minItem;
    minItem = array[1];
    array[1] = array[currentSize--]; //先保证结构性【先array[1]=array[currentSize],然后currentSize--】
    percolateDown( 1 );
    return minItem;
}

template <class Type>
void priorityQueue<Type>::buildHeap()
{
    for(int i = currentSize / 2; i > 0; i--)
    {
        percolateDown(i);
    }
}

template <class Type>
priorityQueue<Type>::priorityQueue(const Type *items, int size):maxSize(size + 10), currentSize(size)
{
    array = new Type[maxSize];
    for(int i = 0; i < size; i++ )
    {
        array[i + 1] = items[i];
    }
    buildHeap();
}

int main()
{
    return 0;
}

