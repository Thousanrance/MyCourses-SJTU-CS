//4383. Max Fraction
//求n阶法雷序列(不含０，１）中，第k大的数
//用优先级队列的思想来做
//n,k < 1e6

#include <iostream>
using namespace std;


template <class Type>
class priorityQueue{
private:
    int currentSize;
    int maxSize;
    Type *array;
    void doubleSpace();
    void buildHeap();
    void percolateDown( int hole );

public:
    explicit priorityQueue( int capacity = 100 )
    {
        array = new Type[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    priorityQueue( const Type data[], int size );
    ~priorityQueue() { delete [] array; }
    [[nodiscard]] bool isEmpty() const { return currentSize == 0; }
    Type getHead() { return array[1]; }
    void enQueue( const Type & x );
    Type deQueue();
};


template <class Type>
void priorityQueue<Type>::doubleSpace() {
    Type *tmp = array;
    array = new Type[maxSize * 2];
    for (int i = 1; i <= currentSize; ++i)
        array[i] = tmp[i];
    delete [] tmp;
    maxSize *= 2;
}


template <class Type>
void priorityQueue<Type>::enQueue( const Type & x )
{
    if( currentSize == maxSize - 1 )  doubleSpace();
    int hole = ++currentSize;
    for( ; hole > 1 && x > array[ hole / 2 ]; hole /= 2 )
        array[ hole ] = array[ hole / 2 ];
    array[ hole ] = x; // hole == 1 或者 x > array[ hole / 2 ];
}

template <class Type>
Type priorityQueue<Type>::deQueue()
{
    Type minItem;
    minItem = array[1];
    array[ 1 ] = array[ currentSize-- ];  //先保证结构性
    percolateDown( 1 );
    return minItem;
}

template <class Type>
void priorityQueue<Type>::percolateDown( int hole )
{  int child;
    Type tmp = array[ hole ];

    for( ; hole * 2 <= currentSize; hole = child )
    {  child = hole * 2;  //child为最小孩子下标
        if( child != currentSize && array[ child + 1 ] > array[ child ] )
            child++;
        if( array[ child ] > tmp )   array[ hole ] = array[ child ];
        else    break;
    }
    array[ hole ] = tmp;
}

template <class Type>
void priorityQueue<Type>::buildHeap( )
{
    for ( int i = currentSize / 2; i > 0; i-- )
        percolateDown( i );
}

template <class Type>
priorityQueue<Type>::priorityQueue( const Type *items, int size )
        : maxSize(size + 10 ),  currentSize(size)
{  array = new Type[maxSize];
    for( int i = 0; i < size; i++ )
        array[ i + 1 ] = items[ i ];
    buildHeap();
}

struct fraction{
    int p;  //nominator
    int q;  //denominator

    explicit fraction(int n = 0, int d = 0):p(n),q(d){};
    bool operator>(const fraction & other) const {return double(p)/q > double(other.p)/other.q;}
};


int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a%b);
}


int main(){
    int N, K;
    fraction f;
    cin >> N >> K;
    priorityQueue<fraction> prior;
    for (int i = 1; i < N; ++i){
        prior.enQueue(fraction(i, i + 1));
    }
    while(--K){
        f = prior.deQueue();
        f.p -= 1;
        if (f.p == 0) continue;
        while(gcd(f.q, f.p) != 1) f.p -= 1;
        prior.enQueue(fraction(f.p, f.q));
    }
    f = prior.deQueue();
    cout << f.p << '/' << f.q;
}
