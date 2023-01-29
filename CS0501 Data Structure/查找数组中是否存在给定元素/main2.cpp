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
    quickSort(a, 0, size-1);
}


int binarySearch(double data[], int size, int x)
{
    int low = 0, high = size-1, mid;
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
    double* A=new double[n];

    int k=0; //有多少个元素被前置

    for(int i=0;i<n;i++)
    {
        double tmp;
        cin>>tmp;
        A[i]=tmp;
        if(A[i]<A[i-1])
        {
            k=n-i;
            //cout<<"k="<<k<<endl;
        }
    }
    quickSort(A,n);
    int x;
    for(int j=0;j<m;j++)
    {
        int target;
        cin>>target;
        x=binarySearch(A,n,target);
        if(x==-1)
        {
            cout<<x<<' ';
        }
        else if(x<k)
        {
            cout<<x+n-k<<' ';
        }
        else
        {
            cout<<x-k<<' ';
        }
    }
    return 0;
}
