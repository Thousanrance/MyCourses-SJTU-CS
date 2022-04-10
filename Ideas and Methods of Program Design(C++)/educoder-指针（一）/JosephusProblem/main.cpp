#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int live[10000];
    for(int i=0;i<n;i++)
    {
        live[i]=1;
    }

    int j=0,len=n,k=0;

    do
    {
        if(j>=n)
        {
            j=j-n;
        }
        if(live[j]==1)
        {
            k++;
        }
        if(k==3)
        {
            live[j]=0;
            len--;
            k=0;
        }
        j++;

    }while(len!=1);

    for(int m=0;m<n;m++)
    {
        if(live[m]==1)
        {
            cout<<m+1;
            break;
        }
    }

    return 0;
}
