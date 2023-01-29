#include <iostream>

using namespace std;

template <class Type>
class priorityQueue
{
private:
    int currentSize;
    Type *array;
    int maxSize;
    void percolateDown(int hole);
public:
    priorityQueue(int capacity = 100)
    {
        array = new Type[capacity+1];
        maxSize = capacity;
        currentSize = 0;
    }
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
void priorityQueue<Type>::enQueue(const Type &x)
{
    if(currentSize==0)
    {
        array[1]=x;
        currentSize++;
        return;
    }
    // 向上过滤
    int hole = ++currentSize; //先不放x
    for(;hole > 1 && x > array[ hole / 2 ];hole /= 2)
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
        if(child != currentSize && array[child + 1] > array[child] )
        {
            child++;
        }
        if(array[child] > tmp)
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
    percolateDown(1);
    return minItem;
}

class Rational
{
    public:
    int num;
    int den;
    Rational()
    {

    }
    Rational(int n,int d)
    {
        num=n;
        den=d;
    }
    void display()
    {
        printf("%d",num);
        printf("/");
        printf("%d",den);
        cout<<endl;
    }
    bool operator>(const Rational &r1) const;
};

bool Rational::operator>(const Rational &r1) const
{
    return (double)num * r1.den > (double)den * r1.num;
}

int abs(int p,int q)
{
    if(q==0)
    {
        return p;
    }
    return abs(q,p%q);
}

int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    priorityQueue<Rational> res(n);
    for(int i=n;i>=2;i--)
    {
        Rational x(i-1,i);
        res.enQueue(x);
        //x.display();
    }
    for(int j=1;j<k;j++)
    {
        Rational tmp;
        tmp=res.deQueue();
        int p=tmp.num-1;
        int q=tmp.den;
        for(;p>0;p--)
        {
           if(abs(p,q)==1)
           {
                Rational x(p,q);
                //x.display();
                res.enQueue(x);
                break;
           }
        }
    }
    Rational ans=res.getHead();
    ans.display();
    return 0;
}
