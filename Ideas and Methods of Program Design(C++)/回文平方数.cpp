#include<iostream>

using namespace std;

int main()
{
	int B,p,y,j,x,num1=0,num2=0;
	cin>>B;
	
	int m[100],n[1000];
	
	for(int i=1;i<=200;i++)
	{
		p=i;
		y=0;
		do
		{
			m[y]=p%B;
			p=p/B;
			y++;
		}
		while(p>0);
		
		
		j=i*i;
		x=0;
		
		do
		{
			n[x]=j%B;
			j=j/B;
			x++;
		}
		while(j>0);
		
		int q[1000],tmp=1;
		
		for(int a=0;a<x;a++)
		{
			q[a]=n[x-1-a];
			
			if(q[a]==n[a])
			{
				continue;
			}
			else
			{
				tmp=0;
				break;
			}
		}
		
		
		if(tmp==1)
		{
			for(int z=y-1;z>=0;z--)
			{
				if(m[z]<10)
				{
					cout<<m[z];
				}
				else
				{
					char c='A'-10+m[z];
					cout<<c;
				}
			}
			
			cout<<' ';
			
			for(int z=x-1;z>=0;z--)
			{
				if(n[z]<10)
				{
					cout<<n[z];
				}
				else
				{
					char d='A'-10+n[z];
					cout<<d;
				}
			}
			
			cout<<endl;
		}	
	}
	
	return 0;
}
