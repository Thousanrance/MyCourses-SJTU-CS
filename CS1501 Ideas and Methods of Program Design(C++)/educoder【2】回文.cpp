#include<iostream>

using namespace std;

int main()
{
	int num;
	cin>>num;
	
	int a=num/10000;
	int b=(num%10000)/1000;

	int d=(num%100)/10;
	int f=num%10;
	
	if(a==f&&b==d)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	
	return 0;
}
