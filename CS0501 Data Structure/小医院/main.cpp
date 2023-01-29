/*
��Ŀ����
����Ҫ�Ŷ�����ǵ����˶�֪���ĳ�ʶ��
��������ϸ�ĵ����̵Ĺ۲죬��������ҽԺ���Ŷӻ����н����ġ�
������ȥ��ҽԺ������ҽ��ͬʱ������
���������˲��������أ����Բ��ܸ��ݼ򵥵������ȷ����ԭ��
����ҽԺ��ÿ�ֲ���涨��10�ֲ�ͬ�����ȼ�������Ϊ10������Ȩ��ߣ�����Ϊ1������Ȩ��͡�
ҽ���ڿ���ʱ����������Ķ�������ѡ��һ������Ȩ��ߵ��˽������Ρ�
���������������Ȩһ���Ĳ��˵Ļ�����ѡ���������ŶӵĲ��ˡ�
���ھ��������ҽԺģ������������̡�

�����ʽ
ÿ�����ݵ�һ����һ��������N(0<N<2000)��ʾ�����¼�����Ŀ��
��������N�зֱ��ʾ�������¼���
һ���������¼��� 1:"IN A B",��ʾ��һ��ӵ�����ȼ�B�Ĳ���Ҫ��ҽ��A���Ρ�(0<A<=3,0<B<=10)
2:"OUT A",��ʾҽ��A������һ�����Σ�������Ϻ󣬲��˳�Ժ��(0<A<=3)

�����ʽ
����ÿ��"OUT A"�¼�������һ����������������˵ı��ID��
������¼�ʱ�޲�����Ҫ���Σ������"EMPTY"��
�����˵ı��ID�Ķ���Ϊ����һ������У�"IN A B"�¼�������K��ʱ�������Ĳ���ID��ΪK��
��1��ʼ��š�

��������
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

�������
Sample Output 1
2
EMPTY
3
1

Sample Output 2
1

���ݷ�Χ
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
    // ���Ϲ���
    int hole = ++currentSize; //�Ȳ���x
    for(;hole > 1 && x.prior > array[ hole / 2 ].prior;hole /= 2)
    {
        array[hole] = array[hole/2];
    }
    array[hole] = x; //hole == 1 ���� x > array[ hole / 2 ];
}

void priorityQueue::percolateDown(int hole)
{
    int child;
    int tmp = array[hole].prior;
    for(;hole*2<=currentSize;hole=child)
    {
        child=hole*2; //childΪ��С�����±�
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
    array[1] = array[currentSize--]; //�ȱ�֤�ṹ�ԡ���array[1]=array[currentSize],Ȼ��currentSize--��
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
