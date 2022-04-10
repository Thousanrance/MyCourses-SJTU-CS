#include <iostream>

using namespace std;

class Rational
{
    private:
    int num;
    int den;
    public:
    Rational()
    {

    }
    Rational(int n,int d)
    {
        num=n;
        den=d;
    }
    void display()const
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
    return num * r1.den > den * r1.num;
}

bool abs(int p,int q)
{
    int lit=(p>q)?q:p;
    for(int i=2;i<=lit;i++)
    {
        if(p%i==0&&q%i==0)
        {
            return false;
        }
    }
    return true;
}

const Rational Min(0,1);

class linkStack
{
private:
    struct node
    {
        Rational data;
        node *next;
        node(const Rational &x, node *N = NULL)
        {
        	data = x;
            next = N;
        }
        node():next(NULL){} //头结点专属，可以不要
        ~node(){}
	};
	node *Top; //T为什么要大写：避免与函数同名
public:
    linkStack();
    ~linkStack();
    bool isEmpty()const;
    Rational top()const;
    Rational pop();
    void push(const Rational &x);
};

linkStack::linkStack()
{
    Top = NULL;
}

linkStack::~linkStack() //释放每个结点
{
    node *tmp;
    while(Top!=NULL)
    {
    	//兄弟协同法
        tmp = Top;
        Top = Top->next;
    	delete tmp;
    }
}

bool linkStack::isEmpty()const
{
    return Top == NULL;
}

Rational linkStack::pop()
{
    if(Top==NULL)
    {
        return Min;
    }
    node *tmp = Top;
    Rational x = Top->data;
    Top = Top->next;
    delete tmp;
    return x;
}

Rational linkStack::top()const
{
    if(Top==NULL)
    {
        return Min;
    }
    return Top->data;
}

void linkStack::push(const Rational &x)
{
    Top = new node(x, Top);
}

class priorityQueue
{
private:
    linkStack *array;
    int maxSize;
    int currentSize;
    void percolateDown(int hole);
public:
    priorityQueue(int capacity = 100)
    {
        array = new linkStack[capacity];
        maxSize = capacity;
        currentSize=0;
    }
    ~priorityQueue()
    {
        delete [] array;
    }
    linkStack & getHead()
    {
        return array[1];
    }
    void enQueue(const linkStack &x);
    linkStack &deQueue();
};

void priorityQueue::enQueue(const linkStack &x)
{
    cout<<"Function:enQueue()"<<endl;
    if(currentSize==0)
    {
        array[1]=x;
        currentSize++;
        return;
    }
    // 向上过滤
    int hole = ++currentSize; //先不放x
    for(;hole > 1 && x.top() > array[ hole / 2 ].top();hole /= 2)
    {
        array[hole] = array[hole/2];
        cout<<"check!"<<endl;
    }
    array[hole] = x; //hole == 1 或者 x > array[ hole / 2 ];
}

void priorityQueue::percolateDown(int hole)
{
    int child;
    linkStack tmp = array[hole];
    for(;hole*2<=currentSize;hole=child)
    {
        child=hole*2; //child为最小孩子下标
        if(child != currentSize && array[child+1].top() > array[child].top() )
        {
            child++;
        }
        if(array[child].top() > tmp.top())
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

linkStack & priorityQueue::deQueue()
{
    cout<<"Function:deQueue()"<<endl;
    linkStack &maxItem=array[1];
    cout<<"max:";maxItem.top().display();
    array[1] = array[currentSize--]; //先保证结构性【先array[1]=array[currentSize],然后currentSize--】
    percolateDown(1);
    return maxItem;
}

int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);

    priorityQueue tree(n);
    cout<<"Tree is created!"<<endl;
    for(int q=n;q>1;q--)
    {
        linkStack s;
        cout<<"Stack"<<q<<" is created!"<<endl;
        for(int p=1;p<=q-1;p++)
        {
            if(abs(p,q))
            {
                Rational x(p,q);
                x.display();
                s.push(x);
                cout<<"x is pushed in Stack"<<q<<endl;
            }
        }
        tree.enQueue(s);
        cout<<"Stack"<<q<<" is enQueue tree!"<<endl;
    }
    cout<<"Now start to find the max k"<<endl;
    for(int i=1;i<k;i++)
    {
        linkStack &tmp=tree.deQueue();
        cout<<"Stack"<<i<<" is deQueue tree!"<<endl;
        cout<<"tmp is determined!"<<endl;
        tmp.pop().display();
        cout<<"the max "<<i<<" is out!"<<endl;
        tree.enQueue(tmp);
        cout<<"the tmp is enQueue again!"<<endl;
    }

    linkStack &res=tree.getHead();
    Rational ans=res.top();
    //cout<<"the max k is:";
    ans.display();
    return 0;
}
