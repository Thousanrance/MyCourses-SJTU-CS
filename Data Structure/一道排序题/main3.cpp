/*
题目描述
给你2个数组a[]和b[]，他们有相同的长度n，你可以任意交换一个数组中的元素，我们定义函数
x=∑a[i]∗b[i]
现在，问x最大可以取到多少，最小可以取到多少？

输入格式
第一行一个整数n，代表数组的长度；
第二行数组a，最后一行数组b；

输出格式
输出两个整数代表答案；

样例输入
2
10 3
10 9

样例输出
127 120

数据范围
对于40%的数据，n≤10；
对于100%的数据，n≤100000 ，1≤a[i],b[i]≤100000；
*/

#include <iostream>

using namespace std;

long long divide(long long a[], long long low, long long high) //划分函数
{
    long long  k = a[low];
    do
    {
        while(low < high && a[high] >= k)
        {
            --high;
        }
        if(low < high)
        {
            a[low] = a[high];
            ++low;
        }
        while(low < high && a[low] <= k)
        {
            ++low;
        }
        if(low < high)
        {
            a[high] = a[low];
            --high;
        }
    }while(low != high);
    a[low] = k;
    return low;
}

void quickSort(long long a[], long long low, long long high)
{
    long long mid;
    if(low >= high)
    {
        return;
    }
    mid = divide(a, low, high);
    quickSort(a, low, mid-1); //排序左一半
    quickSort(a, mid+1, high); //排序右一半
}


void quickSort(long long a[], long long size) //包裹函数
{
    quickSort(a, 0, size-1);
}


long long calmax(long long a[],long long b[],long long n)
{
    long long res=0;
    for(long long i=0;i<n;i++)
    {
        //cout<<a[i]<<' '<<b[i]<<endl;
        res+=a[i]*b[i];
    }
    return res;
}

long long calmin(long long a[],long long b[],long long n)
{
    long long res=0;
    for(long long i=0;i<n;i++)
    {
        //cout<<a[i]<<' '<<b[n-i+1]<<endl;
        res+=a[i]*b[n-1-i];
    }
    return res;
}

int main()
{
    long long n;
    scanf("%lld",&n);
    long long* a=new long long [n];
    long long* b=new long long [n];
    for(long long i=0;i<n;i++)
    {
        long long ai;
        scanf("%lld",&ai);
        a[i]=ai;
    }
    for(long long j=0;j<n;j++)
    {
        long long bj;
        scanf("%lld",&bj);
        b[j]=bj;
    }
    quickSort(a,n);
    quickSort(b,n);
    long long xmax,xmin;
    xmax=calmax(a,b,n);
    xmin=calmin(a,b,n);
    cout<<xmax<<' '<<xmin<<endl;
    return 0;
}

