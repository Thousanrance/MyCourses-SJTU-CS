#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int time1(int peo[],int x)
{
    int tx;
    tx=2*peo[1]+peo[0]+peo[x-1];
    return tx;
}

int time2(int peo[],int y)
{
    int ty;
    ty=2*peo[0]+peo[y-1];
    return ty;
}

int end(int peo[],int z)
{
    int tz;
    if(z==3)
    {
        tz=peo[0]+peo[1]+peo[2];
    }
    else
    {
        tz=peo[1];
    }

    return tz;
}

int main()
{
   	int n,t1=0,t2=0;
    cin>>n;

    int peo[1000];

    int p=n,q=n;

    for(int i=0;i<n;i++)
    {
        cin>>peo[i];
    }
    sort(peo,peo+n);

    for(p=n;p>3;p=p-2)
    {
        t1=t1+time1(peo,p);
    }
    for(q=n;q>3;q=q-1)
    {
        t2=t2+time2(peo,q);
    }

    t1=t1+end(peo,p);
    t2=t2+end(peo,q);

    if(t1<=t2)
    {
        cout<<t1;
    }
    else
    {
        cout<<t2;
    }

    return 0;
}
