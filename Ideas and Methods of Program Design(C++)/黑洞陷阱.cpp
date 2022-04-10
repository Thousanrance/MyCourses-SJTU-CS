#include<iostream>

using namespace std;

int main()
{
	int num;
	
	cin>>num;
	
	int a,b,c,i=1,max,mid,min,maxfig,minfig;
	
	do
	{
		a=num/100;
		b=num%100/10;
		c=num%10;
		
		if(a>=b)
		{
			if(a>=c)
			{
				max=a;
				if(b>=c)
				{
					mid=b;
					min=c;
				}
				else
				{
					mid=c;
					min=b;
				}
			}
			else
			{
				max=c;
				min=b;
				mid=a;
			}
		}
		else
		{
			if(b>=c)
			{
				max=b;
				if(a>=c)
				{
					mid=a;
					min=c;
				}
				else
				{
					mid=c;
					min=a;
				}
			}
			else
			{
				max=c;
				mid=b;
				min=a;
			}
		}
		
		maxfig=max*100+mid*10+min;
		minfig=min*100+mid*10+max;
		num=maxfig-minfig;
		
		cout<<i<<':'<<maxfig<<'-'<<minfig<<'='<<num<<endl; 
		
		i++;
		
	}while(num!=495); 
	
	return 0;
} 
