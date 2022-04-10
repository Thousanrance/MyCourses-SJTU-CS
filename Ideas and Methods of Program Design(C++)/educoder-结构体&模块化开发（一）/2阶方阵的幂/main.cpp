#include<iostream>
using namespace std;

struct Mat
{
    long a;
    long b;
    long c;
    long d;
};

int main()
{
    int mod=1000000007;
    int n;
    cin>>n;

    Mat A;
    cin>>A.a>>A.b>>A.c>>A.d;

    Mat ans={1,0,0,1};
    Mat tmp;

    while(n)
    {
        if(n%2)
        {
            tmp.a=ans.a;
            tmp.b=ans.b;
            tmp.c=ans.c;
            tmp.d=ans.d;
            ans.a=(tmp.a*A.a+tmp.b*A.c+mod)%mod;
            ans.b=(tmp.a*A.b+tmp.b*A.d+mod)%mod;
            ans.c=(tmp.c*A.a+tmp.d*A.c+mod)%mod;
            ans.d=(tmp.c*A.b+tmp.d*A.d+mod)%mod;
        }
        tmp.a=A.a;
        tmp.b=A.b;
        tmp.c=A.c;
        tmp.d=A.d;
        A.a=(tmp.a*tmp.a+tmp.b*tmp.c+mod)%mod;
        A.b=(tmp.a*tmp.b+tmp.b*tmp.d+mod)%mod;
        A.c=(tmp.c*tmp.a+tmp.d*tmp.c+mod)%mod;
        A.d=(tmp.c*tmp.b+tmp.d*tmp.d+mod)%mod;
        n=n/2;
    }

    cout<<ans.a<<' '<<ans.b<<endl;
    cout<<ans.c<<' '<<ans.d<<endl;

    return 0;
}


