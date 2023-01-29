#include<iostream>
using namespace std;

static int i=0;

void order1(int price[])
{
   do
   {
       cin>>price[i];
       i++;
   }
   while(price[i-1]!=-1);
   i--;
}
void order2(int price[])
{
    for(int j=0;j<i;j++)
    {
        cout<<price[j]<<' ';
    }
    cout<<endl;
}
void order3(int price[])
{
    int index[]={0,1,2,3,4,5,6,7,8,9,10};
    int tmp;
    for(int x=0;x<i-1;x++)
    {
        for(int y=x+1;y<i;y++)
        {
            if(price[index[y]]<price[index[x]])
            {
                tmp=index[x];
                index[x]=index[y];
                index[y]=tmp;
            }
        }
    }
    for(int k=0;k<i;k++)
    {
        cout<<price[index[k]]<<' ';
    }
    cout<<endl;
}
void order4(int price[])
{
    int maxp=0,minp=100;
    int maxdt,mindt;
    for(int k=0;k<i;k++)
    {
        if(price[k]>maxp)
        {
            maxp=price[k];
            maxdt=k;
        }
        if(price[k]<minp)
        {
            minp=price[k];
            mindt=k;
        }
    }
    cout<<mindt<<' '<<maxdt<<endl;
}

void order5(int price[])
{
    int maxbn=0,tmp;
    for(int x=0;x<i-1;x++)
    {
        for(int y=x+1;y<i;y++)
        {
            if(price[y]>price[x])
            {
                tmp=price[y]-price[x];
                if(tmp>maxbn)
                {
                    maxbn=tmp;
                }
            }
        }
    }
    cout<<maxbn<<endl;
}

void order6(int price[])
{
    int maxbn=0;
    int bn;
    for(int k=0;k<i-1;k++)
    {
        bn=price[k+1]-price[k];
        if(bn>0)
        {
             maxbn=maxbn+bn;
        }
    }
    cout<<maxbn<<endl;
}


int main()
{
    cout<<"欢迎使用股票分析系统："<<endl;
    cout<<"1--输入股票价格序列"<<endl;
    cout<<"2--查询股票价格"<<endl;
    cout<<"3--输出升序的股票价格序列"<<endl;
    cout<<"4--输出最大值和最小值的日期"<<endl;
    cout<<"5--一笔交易的最大利润"<<endl;
    cout<<"6--多笔交易的最大利润"<<endl;
    cout<<"7--退出"<<endl;

    int order;
    int price[10];

    while(1)
    {
        cin>>order;
        cin.clear();
        cin.ignore();
        if(order==1)
        {
            order1(price);
        }
        else if(order==2)
        {
            order2(price);
        }
        else if(order==3)
        {
            order3(price);
        }
        else if(order==4)
        {
            order4(price);
        }
        else if(order==5)
        {
            order5(price);
        }
        else if(order==6)
        {
            order6(price);
        }
        else if(order==7)
        {
            return 0;
        }
    }
}
