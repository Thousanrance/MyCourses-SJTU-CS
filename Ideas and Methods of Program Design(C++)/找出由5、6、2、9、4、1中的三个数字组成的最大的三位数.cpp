#include<iostream>

using namespace std;

int main()
{
	int num=0,max=10,current;
	int n[6]={5,6,2,4,9,11};
	
	for(int digit=100;digit>0;digit=digit/10)
	{
		current=0;
		
		for(int i=0;i<=5;i++)
		{
			if(n[i]>current&&n[i]<max)
			{
				current=n[i];
			}	
		}
		
		num=num+digit*current;
		max=current;
	}
	
	cout<<num<<"\t";
	
	return 0;
}
