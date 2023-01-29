/*
Description
Find the k-th largest element in an unsorted array.
The average time complexity of your program is required as O(n).

Input Format
The program takes as input two lines.

The first line is an unsorted array of integers in the range of [0,255].

The second line is an integer k that 1¡Ük¡Üarray length.

Output Format
The k-th largest element of the given array.

Note
DO NOT use any built-in sorting algorithms, priority queue or heap queue.
There could be repeated elements in the array.
Examples
Input:
3 2 1 5 6 4
2
Output:
5
Input:
3 2 3 1 2 4 5 5 6
4
Output:
4
*/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int divide(vector<int>& a, int low, int high) //»®·Öº¯Êý
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

int quickSort(vector<int>& a, int low, int high,int index)
{
    int now=divide(a,low,high);
    if(index<now)
    {
        return quickSort(a,low,high-1,index);
    }
    else if(index>now)
    {
        return quickSort(a,now+1,high,index);
    }
    else
    {
        return a[now];
    }
}

class Solution
{
public:
    int kthLargestElement(vector<int>& arr, int k)
    {
    	// Find the k-th largest element in the array
        int n=arr.size();
        int index=n-k;
        int res=quickSort(arr,0,n-1,index);
        return res;
    }
};


int main()
{
    // Input processing
    string str;
    getline(cin,str);
    stringstream input(str);

    int k;
    cin>>k;

    int a;
    vector<int> arr;
    while(input>>a)
    {
        arr.push_back(a);
    }

    // Return the result
    Solution s;

    int res=s.kthLargestElement(arr,k);

    cout<<res;

    return 0;
}
