#include<iostream>

using namespace std;

int main()
{
	char ch1,ch2,ch3;

	for(ch1='A';ch1<='C';ch1++)
	{
		for(ch2='A';ch2<='C';ch2++)
		{
			if(ch1==ch2)
			{
				continue;
			}
			else
			{
				for(ch3='A';ch3<='C';ch3++)
				{
					if(ch3==ch1||ch3==ch2)
					{
						continue;
					}
					else
					{
						cout<<ch1<<ch2<<ch3<<endl;
					}
				}
			}
		}
	}
	
	return 0;
}
