#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    int key;
    char *str;
};

bool operator<(const node &s1,const node &s2)
{
    return s1.key<s2.key;
}

bool operator>(const node &s1,const node &s2)
{
    return s1.key>s2.key;
}

ostream &operator<<(ostream &os,const node &obj)
{
    os<<"("<<obj.key<<","<<obj.str<<")";
    return os;
}

int main()
{
    int a[11]={0,3,1,11,7,5,9,34,54,89,66};
    vector<int> va(a,a+11);

    sort(va.begin(),va.end());
    for(int i=0;i<va.size();i++)
    {
        cout<<va[i]<<' ';
    }
    cout<<endl;

    sort(va.begin(),va.end(),greater<int>());
    for(int i=0;i<va.size();i++)
    {
        cout<<va[i]<<' ';
    }
    cout<<endl;

    node b[12]={{5,"aaa"},{2,"bbb"},{33,"ccc"},{5,"ddd"},{33,"eee"},{6,"fff"},
                {5,"ggg"},{33,"hhh"},{5,"jjj"},{33,"kkk"},{6,"lll"},{5,"ppp"}};
    vector<node> vb(b,b+12);

    sort(vb.begin(),vb.end());
    for(int i=0;i<vb.size();i++)
    {
        cout<<vb[i]<<' ';
    }
    cout<<endl;

    stable_sort(vb.begin(),vb.end(),greater<node>());
    for(int i=0;i<vb.size();i++)
    {
        cout<<vb[i]<<' ';
    }
    cout<<endl;

    return 0;
}
