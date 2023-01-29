/*
Description
输入两个大于0的正整数a、b，且a<b。
满足以下三个条件的数，称之为完美数：
1. 是偶数；2. 位数是偶数；3. 是回文数。
输出区间内[a，b]所有的完美数。
若没有则输出0.

Input Format
输入 第一行：a b

Output Format
输出 第一行：第一个完美数 第二行：第二个完美数 ...

Sample Input
10 100

Sample Output
22 44 66 88

Sample Input
100 200

Sample Output
0

Limits
b不超过INT_MAX
*/

#include <iostream>
#include <cmath>

using namespace std;

template <class elemType>
class linkList
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *p = NULL)
        {
            data = x;
            next = p;
        }
        node( ):next(NULL){}
        ~node(){}
    };
    node *head;
public:
    linkList();
    void clearr();
    ~linkList()
    {
        clearr();
        delete head;
    }
    int length()const;
    void insertt(int i, const elemType &x);
    void traverse()const;
};

class OutOfBound{};

template <class elemType>
linkList<elemType>::linkList()
{
    head=new node();
}

template <class elemType>
int linkList<elemType>::length()const
{
    int count=0;
    node *p=head->next;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

template <class elemType>
void linkList<elemType>::insertt(int i, const elemType &x)
{
    //cout<<"Enter the function:insertt"<<endl;
    node *tmp;
    node *p=head;
    for(int j = 0; p && j < i-1; ++j)
    {
        p = p->next;
    }
    if(!p)
    {
        throw OutOfBound{};
    }
    tmp = new node(x, p->next);
    p->next = tmp;
}

template <class elemType>
void linkList<elemType>::traverse()const
{
    //cout<<"Enter the function:traverse"<<endl;
    node* p;
    p=head->next;
    while(p)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

template <class elemType>
void linkList<elemType>::clearr()
{
    head->next=NULL;
}

bool isEven(int x)
{
    if(x%2)
    {
        return false;
    }
    return true;
}

bool isEvenBit(int x,int &bit)
{
    while(x)
    {
        x=x/10;
        bit++;
    }
    if(isEven(bit))
    {
        return true;
    }
    return false;
}

bool isPali(int x,int bit)
{
    if(x%11!=0)
    {
        return false;
    }
    //cout<<"the bit of "<<x<<" is "<<bit<<endl;
    int *bitNum;
    bitNum=new int [bit];
    for(int i=0;i<bit;i++)
    {
        bitNum[i]=x%10;
        x=x/10;
    }

    int j;

    for(j=0;j<bit/2;j++)
    {
        if(bitNum[j]!=bitNum[bit-1-j])
        {
            break;
        }
    }
    if(j<bit/2)
    {
        delete bitNum;
        return false;
    }
    delete bitNum;
    return true;
}

int main()
{
    int a,b;

    cin>>a>>b;

    linkList<int> Perfect;
    int abit=0,bbit=0;

    if(isEvenBit(a,abit))
    {
        if(!isEven(a))
        {
            a++;
        }
    }
    else
    {
        a=pow(10,abit);
        abit++;
    }//将a处理成不小于a的最小偶数位偶数

    if(!isEvenBit(b,bbit))
    {
        b=pow(10,bbit-1)-1;
    }//将b处理成不大于b的最小偶数位数

    int start=a;
    int startbit=abit;
    int endd=pow(10,abit)-1;

    do
    {
        if(endd>=b)
        {
            endd=b;
        }
        for(int x=start;x<=endd;x=x+2)
        {
           if(!isPali(x,startbit))
           {
               continue;
           }

           Perfect.insertt(Perfect.length()+1,x);
        }
        start=(endd+1)*10;//跳过a、b间奇数位的数
        if(start>b)
        {
            break;
        }
        startbit+=2;
        endd=start*10-1;

    }while(b>=endd);

    if(Perfect.length()==0)
    {
        cout<<0;
    }
    else
    {
        Perfect.traverse();
    }

    return 0;
}
