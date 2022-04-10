#include <iostream>

using namespace std;

long times=0;

int divide(int a[], int low, int high) //»®·Öº¯Êý
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

void quickSort(int a[], int low, int high)
{
    int mid;
    if(low >= high)
    {
        return;
    }
    times+=high-low;
    mid = divide(a, low, high);
    quickSort(a, low, mid-1);
    quickSort(a, mid+1, high);
}

void quickSort(int a[], int size)
{
    quickSort(a, 0, size-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    int* a=new int [n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(a,n);
    printf("%ld",times);
    return 0;
}
