#include <iostream>

using namespace std;

int m,n;
int mat[10][10];

int maxcheck(int i,int j)
{
    int judge=1;

    for(int p=0;p<n;p++)
    {
        if(mat[i][p]>mat[i][j])
        {
            judge=0;
            break;
        }
    }

    return judge;
}

int mincheck(int i,int j)
{
    int judge=1;

    for(int q=0;q<m;q++)
    {
        if(mat[q][j]<mat[i][j])
        {
            judge=0;
            break;
        }
    }

    return judge;
}

int main()
{
    cin>>m>>n;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }

    int num=0,x=0,y=0;

    for(x=0;x<m;x++)
    {
        for(y=0;y<n;y++)
        {
            if(maxcheck(x,y)==1)
            {
                if(mincheck(x,y)==1)
                {
                    cout<<"mat["<<x<<"]"<<"["<<y<<"]"<<"="<<mat[x][y]<<endl;
                    num++;
                }
            }
        }
    }

    if(num==0)
    {
        cout<<"Not Found";
    }

    return 0;
}
