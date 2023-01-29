#include <iostream>

const long mod=1e9+7;

int main()
{
    int n;
    scanf("%d",&n);
    long long *res=new long long[n+1];
    res[0]=1;
    res[1]=1;
    for(int i=2;i<=n;i++)
    {
        res[i]=0;
        for(int j=0;j<i;j++)
        {
            res[i]=(res[i]+(res[j]*res[i-j-1])%mod)%mod;
        }
    }
    printf("%d",res[n]);
    return 0;
}
