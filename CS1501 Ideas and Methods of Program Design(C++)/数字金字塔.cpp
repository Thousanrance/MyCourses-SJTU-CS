#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int R;
	cin>>R;
	
	int x[11][11];
	
	for(int i=0;i<=10;i++)
	{
		for(int j=0;j<=10;j++)
		{
			x[i][j]=0;
		}
    }
	
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>x[i][j];
		}
	}
	
	int f[11][11];
	int li=1,col=1;
	
	for(int i=0;i<=10;i++)
	{
		for(int j=0;j<=10;j++)
		{
			f[i][j]=0;
		}
	}
	
	f[1][1]=x[1][1];
	
	for(li=1;li<=R;li++)
	{
		for(col=1;col<=li;col++)
		{
			f[li][col]=x[li][col]+max(f[li-1][col-1],f[li-1][col]);
		}		
	}
	
	int max=0;
	
	for(int p=1;p<=R;p++)
	{
		if(f[R][p]>max)
		{
			max=f[R][p];
		}
	}
	
	cout<<max;
	
	return 0;	
}
