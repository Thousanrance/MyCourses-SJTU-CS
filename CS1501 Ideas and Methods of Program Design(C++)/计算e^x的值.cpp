#include<iostream>

using namespace std;

int main()
{
	double ex,x,item;
	int i;
	
	cin>>x;
	
	ex=0;
	item=1;
	i=0;
	
	while(item>1e-6)// 1e-6 ��ʾ10��-6�η� 
	{
		ex=ex+item;
		i++;
		item=item*x/i;
	}
	
	cout<<ex<<endl;
	
	return 0;
}
