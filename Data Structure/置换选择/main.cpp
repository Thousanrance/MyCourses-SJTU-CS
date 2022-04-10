#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n==0)
    {
        cout<<0;
        return 0;
    }
    int file=0;
    int maxinfiles[500000];
    priority_queue<int,vector<int>,greater<int>> aheap;
    int ainheap=0;
    vector<int> alist;
    int ainlist=0;
    while(n--)
    {
        if(ainlist==m)
        {
            //cout<<"Now m is full by list."<<endl;
            file++;
            //cout<<"Now file="<<file<<endl;
            for(int i=0;i<m;i++)
            {
                int tmp2=alist.back();
                alist.pop_back();
                ainlist--;
                //cout<<"Now alist.pop="<<tmp2<<endl;
                //cout<<"Now ainlist="<<ainlist<<endl;
                aheap.push(tmp2);
                ainheap++;
                //cout<<"Now aheap.push="<<tmp2<<endl;
                //cout<<"Now ainheap="<<ainheap<<endl;
            }
        }
        if(ainheap==m-ainlist)
        {
            //cout<<"Now heap is full."<<endl;
            int tmp=aheap.top();
            aheap.pop();
            ainheap--;
            //cout<<"Now aheap.pop="<<tmp<<endl;
            //cout<<"Now ainheap="<<ainheap<<endl;
            //cout<<"Now maxinfiles["<<file<<"] is from "<<maxinfiles[file];
            if(tmp>maxinfiles[file])
            {
                maxinfiles[file]=tmp;
            }
            //cout<<" to "<<maxinfiles[file]<<endl;
        }
        int a;
        cin>>a;
        //cout<<"Now read a="<<a<<endl;
        //cout<<"Because now maxinfiles["<<file<<"] is "<<maxinfiles[file]<<endl;
        if(ainheap<m-ainlist&&a>maxinfiles[file])
        {
            aheap.push(a);
            ainheap++;
            //cout<<"Now aheap.push="<<a<<endl;
            //cout<<"Now ainheap="<<ainheap<<endl;
        }
        if(ainheap<m-ainlist&&a<maxinfiles[file])
        {
            alist.push_back(a);
            ainlist++;
            //cout<<"Now alist.push="<<a<<endl;
            //cout<<"Now ainlist="<<ainlist<<endl;
        }
    }
    if(ainlist!=0)
    {
        cout<<file+2;
    }
    else
    {
        cout<<file+1;
    }
    return 0;
}
