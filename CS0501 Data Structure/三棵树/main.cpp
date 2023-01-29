#include <iostream>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

stack<char> prt;

void post(queue<char> pr,queue<char> in,int l)
{
    if(l==0)
    {
        return;
    }
    char tmp=pr.front();
    pr.pop();
    prt.push(tmp);

    int ll=0,rl=0;

    queue<char> lpr;
    queue<char> rpr;
    queue<char> lin;
    queue<char> rin;

    while(1)
    {
        char tmp1=in.front();
        in.pop();
        if(tmp1==tmp)
        {
            break;
        }
        lin.push(tmp1);
        ll++;
    }
    while(1)
    {
        if(in.empty())
        {
            break;
        }
        char tmp2=in.front();
        in.pop();
        rin.push(tmp2);
        rl++;
    }
    int i=ll;
    while(i--)
    {
        char tmp3=pr.front();
        pr.pop();
        lpr.push(tmp3);
    }
    while(1)
    {
        if(rpr.empty())
        {
            break;
        }
        char tmp4=pr.front();
        pr.pop();
        rpr.push(tmp4);
    }

    post(rpr,rin,rl);
    post(lpr,lin,ll);
}

int main()
{
    char* pre=new char [10001];
    cin.getline(pre,10001,'\n');
    int l=strlen(pre);
    char* ino=new char [10001];
    cin.getline(ino,10001,'\n');

    queue<char> pr;
    queue<char> in;

    for(int i=0;i<l;i++)
    {
        pr.push(pre[i]);
        in.push(ino[i]);
    }

    post(pr,in,l);

    while(1)
    {
        if(prt.empty())
        {
            break;
        }
        char p=prt.top();
        cout<<p;
        prt.pop();
    }
    return 0;
}
