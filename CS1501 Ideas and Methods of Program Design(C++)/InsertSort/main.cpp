#include<iostream>
using namespace std;

void Insert(int arr[],int n)
{
    int tmp;

    if(n==1)
    {
        if(arr[1]<arr[0])
        {
            tmp=arr[0];
            arr[0]=arr[1];
            arr[0]=tmp;
        }
    }
    else
    {
        if(arr[n-1]<=arr[0])
        {
            tmp=arr[n-1];
            for(int l=n-1;l>0;l--)
            {
                arr[l]=arr[l-1];
            }
            arr[0]=tmp;

        }
        else
        {
             for(int k=0;k<n-1;k++)
            {
                if(arr[n-1]>=arr[k]&&arr[n-1]<=arr[k+1])
                {
                    tmp=arr[n-1];
                    for(int l=n-1;l>k+1;l--)
                    {
                        arr[l]=arr[l-1];
                    }
                    arr[k+1]=tmp;
                    break;
                }
            }
        }
    }
}

void Insert_Sort(int arr[],int n)
{
    if(n>0)
    {
        Insert_Sort(arr,n-1);
        Insert(arr,n);
    }
    else

    return;
}

int main()
{
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Insert_Sort(arr,n);

    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<' ';
    }

	return 0;
}
