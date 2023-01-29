//cin.get()能够读入空格，而cin>>不能。 

#include<iostream>

using namespace std;

int main()
{
	char ch,last_ch;
	int num_words=1;
	
	cout<<"Please input a sentence:";
	
	cin.get(ch);
	
	while(ch==' ')
	{
		cin.get(ch);
	}
	
	last_ch=ch;
	
	while(ch!='.')
	{
		if((ch==' ')&&(last_ch!=' '))
		{
			num_words++;
		}
		
		last_ch=ch;
		cin.get(ch);
	}
	
	if(last_ch==' ')
	{
		num_words--;
	}
	
	cout<<"Number of the words:"<<num_words;
	
	return 0;
}
