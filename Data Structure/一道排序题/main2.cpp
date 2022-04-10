#include <iostream>

using namespace std;

class priorityQueue
{
private:
    long long currentSize;
public:
    long long *array;
    priorityQueue(long long capacity = 100)
    {
        array = new long long[capacity];
        currentSize = 0;
    }
    ~priorityQueue()
    {
        delete [] array;
    }
    void enQueue(const long long &x);
};

void priorityQueue::enQueue(const long long &x)
{
    // 向上过滤
    long long hole = ++currentSize; //先不放x
    for(;hole > 1 && x < array[ hole / 2 ];hole /= 2)
    {
        array[hole] = array[hole/2];
    }
    array[hole] = x; //hole == 1 或者 x > array[ hole / 2 ];
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

