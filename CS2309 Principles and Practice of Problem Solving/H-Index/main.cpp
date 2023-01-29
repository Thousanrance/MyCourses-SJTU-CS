#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int divide(vector<int>& a, int low, int high) //划分函数
{
    int  k = a[low];
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

void quickSort(vector<int>& a, int low, int high)
{
    int mid;
    if(low >= high)
    {
        return;
    }
    mid = divide(a, low, high);
    quickSort(a, low, mid-1); //排序左一半
    quickSort(a, mid+1, high); //排序右一半
}

void quickSort(vector<int>& a, int size) //包裹函数
{
    quickSort(a, 0, size-1);
}

class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
    	// Compute h-index
        int sz=citations.size();
        quickSort(citations,sz);

        int h=0;
        int tmp=0;
        for(int i=0;i<sz;i++)
        {
            tmp=min(citations[i],sz-i);
            if(tmp>h)
            {
                h=tmp;
            }
        }
        return h;
    }
};

int main()
{
    // Process input line
    string str;
    getline(cin, str);
    stringstream input(str);

    vector<int> citations;
    double a;

    while(input >> a)
    {
        citations.push_back(a);
    }
    // Return the result

    Solution s;

    int h;

    h=s.hIndex(citations);

    cout<<h;

    return 0;
}
