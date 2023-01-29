#include <iostream>

using namespace std;

class priorityQueue
{
private:
    long long currentSize;
    long long maxSize;
    void doubleSpace();
    void buildHeap();
    void percolateDown(long long hole);
public:
    long long *array;
    priorityQueue(long long capacity = 100)
    {
        array = new long long[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    priorityQueue(const long long data[], long long size);
    ~priorityQueue()
    {
        delete [] array;
    }
    bool isEmpty()const
    {
        return currentSize == 0;
    }
    long long getHead()
    {
        return array[1];
    }
    void enQueue(const long long &x);
    long long deQueue();
};

void priorityQueue::doubleSpace()
{
    long long *tmp =array;
    array = new long long[2 * maxSize];
    for(long long i = 1;i <= maxSize;++i)
    {
        array[i] = tmp[i];
    }
    maxSize *= 2;
    delete tmp;
}

void priorityQueue::enQueue(const long long &x)
{
    if(currentSize == maxSize - 1)
    {
        doubleSpace();
    }
    // 向上过滤
    long long hole = ++currentSize; //先不放x
    for(;hole > 1 && x < array[ hole / 2 ];hole /= 2)
    {
        array[hole] = array[hole/2];
    }
    array[hole] = x; //hole == 1 或者 x > array[ hole / 2 ];
}

void priorityQueue::percolateDown(long long hole)
{
    long long child;
    long long tmp = array[hole];
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

long long priorityQueue::deQueue()
{
    long long minItem;
    minItem = array[1];
    array[1] = array[currentSize--]; //先保证结构性【先array[1]=array[currentSize],然后currentSize--】
    percolateDown(1);
    return minItem;
}

void priorityQueue::buildHeap()
{
    for(long long i = currentSize / 2; i > 0; i--)
    {
        percolateDown(i);
    }
}

priorityQueue::priorityQueue(const long long *items, long long size):maxSize(size + 10), currentSize(size)
{
    array = new long long[maxSize];
    for(long long i = 0; i < size; i++ )
    {
        array[i + 1] = items[i];
    }
    buildHeap();
}

long long calmax(long long a[],long long b[],long long n)
{
    long long res=0;
    for(long long i=1;i<=n;i++)
    {
        //cout<<a[i]<<' '<<b[i]<<endl;
        res+=a[i]*b[i];
    }
    return res;
}

long long calmin(long long a[],long long b[],long long n)
{
    long long res=0;
    for(long long i=1;i<=n;i++)
    {
        //cout<<a[i]<<' '<<b[n-i+1]<<endl;
        res+=a[i]*b[n-i+1];
    }
    return res;
}

int main()
{
    long long n;
    scanf("%lld",&n);
    priorityQueue a(n+1);
    priorityQueue b(n+1);
    for(long long i=1;i<=n;i++)
    {
        long long ai;
        scanf("%lld",&ai);
        a.enQueue(ai);
    }
    for(long long j=1;j<=n;j++)
    {
        long long bi;
        scanf("%lld",&bi);
        b.enQueue(bi);
    }
    long long xmax,xmin;
    xmax=calmax(a.array,b.array,n);
    xmin=calmin(a.array,b.array,n);
    cout<<xmax<<' '<<xmin<<endl;
    return 0;
}

