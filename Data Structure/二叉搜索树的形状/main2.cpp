#include <iostream>
#include <cmath>

long long calcu(int n)
{
    int* res=new int[n+1];
    res[0]=1;
    int left,right;
    long long num=0;

    for(int i=1;i<=n;i++)
    {
        num=0;
        for(int j=0;j<i;j++)
        {
            left=j;
            right=i-1-j;
            num=num+res[left]*res[right];
        }
        res[i]=num;
    }
    return res[n];
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld",calcu(n)%((int)pow(10,9)+7));
    return 0;
}
