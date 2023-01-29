#include <iostream>
#include <cmath>

int calcus(int start,int end)
{
    if(start>=end)
    {
        return 1;
    }
    int num=0;
    int left;
    int right;
    for(int i=start;i<=end;i++)
    {
        left=calcus(start,i-1);
        right=calcus(i+1,end);
        num=num+left*right;
    }
    return num%((int)pow(10,9)+7);
}

int calcu(int n)
{
    return calcus(1,n);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",calcu(n));
    return 0;
}
