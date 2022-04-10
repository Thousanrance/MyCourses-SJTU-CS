#include <iostream>

using namespace std;

int divide(double a[], int low, int high)
{
    int k = a[low];
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

void quickSort(double a[], int low, int high)
{
    int mid;
    if(low >= high)
    {
        return;
    }
    mid = divide(a, low, high);
    quickSort(a, low, mid-1);
    quickSort(a, mid+1, high);
}

void quickSort(double a[], int size)
{
    quickSort(a, 1, size);
}


int binarySearch(double data[], int size, int x)
{
    int low = 1, high = size, mid;
    while(low <= high )
    {
        mid = (low + high) / 2;
        if(x == data[mid])
        {
            return mid;
        }
        if(x < data[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    double* A=new double[n+1];

    int k=0; //有多少个元素被前置

    for(int i=1;i<n+1;i++)
    {
        double tmp;
        cin>>tmp;
        A[i]=tmp;
        if(A[i]<A[i-1])
        {
            k=i-1;
            //cout<<"k="<<k<<endl;
        }
    }
    quickSort(A,n);
    int x;
    for(int j=0;j<m;j++) //二分查找，返回在A中的下标
    {
        int target;
        cin>>target;
        x=binarySearch(A,n,target); //二分查找，返回在A中的下标
        if(x!=-1)
        {
            cout<<x+k-1<<' '; //在B中的下标
        }
        else
        {
            cout<<x<<endl;
        }
    }
    return 0;
}
