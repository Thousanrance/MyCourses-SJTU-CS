/*
题目描述
看病要排队这个是地球人都知道的常识。
不过经过细心的助教的观察，他发现了医院里排队还是有讲究的。
助教所去的医院有三个医生同时看病。
而看病的人病情有轻重，所以不能根据简单的先来先服务的原则。
所以医院对每种病情规定了10种不同的优先级。级别为10的优先权最高，级别为1的优先权最低。
医生在看病时，则会在他的队伍里面选择一个优先权最高的人进行诊治。
如果遇到两个优先权一样的病人的话，则选择最早来排队的病人。
现在就请你帮助医院模拟这个看病过程。

输入格式
每组数据第一行有一个正整数N(0<N<2000)表示发生事件的数目。
接下来有N行分别表示发生的事件。
一共有两种事件： 1:"IN A B",表示有一个拥有优先级B的病人要求医生A诊治。(0<A<=3,0<B<=10)
2:"OUT A",表示医生A进行了一次诊治，诊治完毕后，病人出院。(0<A<=3)

输出格式
对于每个"OUT A"事件，请在一行里面输出被诊治人的编号ID。
如果该事件时无病人需要诊治，则输出"EMPTY"。
诊治人的编号ID的定义为：在一组测试中，"IN A B"事件发生第K次时，进来的病人ID即为K。
从1开始编号。

样例输入
Sample Input 1
7
IN 1 1
IN 1 2
OUT 1
OUT 2
IN 2 1
OUT 2
OUT 1

Sample Input 2
2
IN 1 1
OUT 1

样例输出
Sample Output 1
2
EMPTY
3
1

Sample Output 2
1

数据范围
0<N<2000
*/

#include <iostream>

using namespace std;

class peo
{
public:
    int id;
    int prior;
    peo(int x=0,int y=0)
    {
        id=x;
        prior=y;
    }
};

class priorityQueue
{
private:
    int currentSize;
    peo *array;
    int maxSize;
    void doubleSpace();
    void buildHeap( );
    void percolateDown(int hole);
public:
    priorityQueue(int capacity = 100)
    {
        array = new peo[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    priorityQueue(const peo data[], int size);
    ~priorityQueue()
    {
        delete [] array;
    }
    bool isEmpty()const
    {
        return currentSize == 0;
    }
    peo getHead()
    {
        return array[1];
    }
    void enQueue(const peo &x);
    peo deQueue();
};

void priorityQueue::doubleSpace()
{
    peo *tmp =array;
    array = new peo[2 * maxSize];
    for(int i = 1;i <= maxSize;++i)
    {
        array[i] = tmp[i];
    }
    maxSize *= 2;
    delete tmp;
}

void priorityQueue::enQueue(const peo &x)
{
    if(currentSize == maxSize - 1)
    {
        doubleSpace();
    }
    // 向上过滤
    int hole = ++currentSize; //先不放x
    for(;hole > 1 && x.prior > array[ hole / 2 ].prior;hole /= 2)
    {
        array[hole] = array[hole/2];
    }
    array[hole] = x; //hole == 1 或者 x > array[ hole / 2 ];
}

void priorityQueue::percolateDown(int hole)
{
    int child;
    int tmp = array[hole].prior;
    for(;hole*2<=currentSize;hole=child)
    {
        child=hole*2; //child为最小孩子下标
        if(child != currentSize && array[child + 1].prior > array[child].prior)
        {
            child++;
        }
        if(array[child].prior > tmp)
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

peo priorityQueue::deQueue()
{
    peo maxItem;
    maxItem = array[1];
    array[1] = array[currentSize--]; //先保证结构性【先array[1]=array[currentSize],然后currentSize--】
    percolateDown( 1 );
    return maxItem;
}

void priorityQueue::buildHeap()
{
    for(int i = currentSize / 2; i > 0; i--)
    {
        percolateDown(i);
    }
}

int main()
{
    priorityQueue doc1,doc2,doc3;
    int times;
    scanf("%d",&times);
    //cout<<"times="<<times<<endl;
    int i=times;
    int intimes=0;
    while(i!=0)
    {
        cin.clear();
        if(i==times)
        {
            cin.ignore();
        }
        //cout<<"i="<<i<<endl;
        char* input;
        input=new char[7];
        cin.getline(input,7,'\n');
        //cout<<input<<endl;

        if(input[0]=='I')
        {
            intimes++;
            int x,y;
            x=(int)(input[3]-'0');
            if(input[6]=='0')
            {
                y=10;
            }
            else
            {
                y=(int)(input[5]-'0');
            }
            //cout<<"x="<<x<<" y="<<y<<endl;
            //cout<<"id="<<intimes<<endl;
            peo patient(intimes,y);
            switch(x)
            {
                case 1:doc1.enQueue(patient);break;
                case 2:doc2.enQueue(patient);break;
                case 3:doc3.enQueue(patient);break;
            }
        }
        else if(input[0]=='O')
        {
            int z;
            z=(int)(input[4]-'0');
            peo tmp;
            switch(z)
            {
                case 1:
                        if(doc1.isEmpty())
                        {
                            printf("EMPTY\n");
                        }
                        else
                        {
                            tmp=doc1.deQueue();
                            printf("%d\n",tmp.id);
                        }
                        break;
                case 2:
                        if(doc2.isEmpty())
                        {
                            printf("EMPTY\n");
                        }
                        else
                        {
                            tmp=doc2.deQueue();
                            printf("%d\n",tmp.id);
                        }
                        break;
                case 3:
                        if(doc3.isEmpty())
                        {
                            printf("EMPTY\n");
                        }
                        else
                        {
                            tmp=doc3.deQueue();
                            printf("%d\n",tmp.id);
                        }
                        break;
            }

        }
        i--;
    }
    return 0;
}
