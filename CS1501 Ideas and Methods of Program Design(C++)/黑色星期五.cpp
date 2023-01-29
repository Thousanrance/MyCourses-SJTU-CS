#include<iostream>

using namespace std;

int main()
{
	int n,day=13,tmp=0,feb;
	cin>>n;
	
	int times[7]={0,0,0,0,0,0,0};
	
	times[5]=1;
	
	for(int i=1900;i<=1900+n-1;i++)
	{
		if(i%400==0||(i%100!=0&&i%4==0))
		{
			feb=29;
		}
		else
		{
			feb=28;
		}
		
		for(int j=1;j<=12;j++)
		{
			
			if(j==2)
			{
				day=day+feb;
			}
			else if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)
			{
				day=day+31;
			}
			else
			{
				day=day+30;
			}
			
			if(i==1900+n-1&&j==12)
			{
				break;
			}
			
			tmp=day%7;
			
			switch(tmp)
			{
				case 0:times[6]++;break;
				case 1:times[0]++;break;
				case 2:times[1]++;break;
				case 3:times[2]++;break;
				case 4:times[3]++;break;
				case 5:times[4]++;break;
				case 6:times[5]++;break;
			}
		}
	}
	
	for(int x=0;x<=6;x++)
	{
		cout<<times[x]<<' ';
	}
	
	return 0;
} 
