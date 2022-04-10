#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int a[]={2,4,7,8,10,12,13,15,16,19,20};
    vector<int> v;
    vector<int>::iterator itr;
    for(int i=0;i<11;i++)
    {
        v.push_back(a[i]);
    }
    if(binary_search(v.begin(),v.end(),13))
    {
        cout<<"13 exists."<<endl;
    }
    else
    {
        cout<<"13 doesn't exist."<<endl;
    }
    itr=find(v.begin(),v.end(),13);
    cout<<*itr<<endl;
    return 0;
}
