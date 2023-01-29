#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
	char test[100];
	
	char check[100]={'\0'};
	
	char tmp[2];
	
	int m=0;
//输入字符串	
	do
	{
		cin.get(test[m]);
		m++;
	}
	while(test[m-1]!='\n'); 
//去掉符号和空格	
	int i=0,j=0; 
	
	for(i=0;i<m;i++)
	{
		if(test[i]>='a'&&test[i]<='z'||test[i]>='A'&&test[i]<='Z')
		{
			tmp[0]=test[i];
			strcat(check,tmp);
			j++;
		}
	}
//判断是否回文，忽略大小写	
	bool judge;
	
	if(j%2==0)
	{
		int x=0;
		for(x=0;x<j/2;x++)
		{
			if(check[x]!=check[j-1-x]&&check[x]-check[j-1-x]!=32&&check[x]-check[j-1-x]!=-32)
			{
				break;
			}
		}
		if(x<j/2)
		{
			judge=false;
		}
		else
		{
			judge=true;
		}
	}
	else
	{
		int y=0;
		for(y=0;y<j-1/2;y++)
		{
			if(check[y]!=check[j-1-y]&&check[y]-check[j-1-y]!=32&&check[y]-check[j-1-y]!=-32)
			{
				break;
			}
		}
		if(y<j-1/2)
		{
			judge=false;
		}
		else
		{
			judge=true;
		}
	}
	
	if(judge)
	{
		strcat(max,test);	 
	}
	
	return 0;
}
