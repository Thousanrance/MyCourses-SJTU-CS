//1、用第一个数组写入所有字符； 
//2、用第二个数组从三位开始存，存的时候除去其他字符 
//3、判断是否回文，不断后移一位再存再判断，三位循环完位数+1；if(art[x]>='a'&&art[x]<='z'||art[x]>='A'&&art[x]<='Z')
 
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
	char art[10125];
	
	int index=0;
	
	cin.getline(art,10125,'\n');
	
	index=strlen(art);
	
	char test[10125]={'\0'},check[10125]={'\0'};
	char temp[2],tmp[2];
	char max[10125]={'\0'};

	int num=index,start=0,begin=0;	
	for(num=2;num<=index;num++)
	{
		start=0;
		
		do
		{
			char test[10125]={'\0'};
			for(begin=start;begin<start+num;begin++)
			{
				temp[0]=art[begin];
				//cout<<"temp="<<temp<<endl;
				strcat(test,temp);
				//cout<<"test="<<test<<endl;	
			}
			cout<<"test="<<test<<endl;
			
			int i=0,j=0;
			
			char check[10125]={'\0'}; 
			for(i=0;i<num;i++)
			{
				if((test[i]>='a'&&test[i]<='z')||(test[i]>='A'&&test[i]<='Z'))
				{
					tmp[0]=test[i];
					cout<<"tmp="<<tmp<<endl;
					strcat(check,tmp);
					cout<<"check="<<check<<endl;
					j++;
				}
			}
			//判断是否回文，忽略大小写	
			int judge;
			
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
					judge=0;
				}
				else
				{
					judge=1;
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
					judge=0;
				}
				else
				{
					judge=1;
				}
			}
			
			if(judge==1)
			{
				strcpy(max,test);	 
			}
			
			start++;
			
		}while(start<=index-num);
	}
	
	cout<<"max="<<max;

	return 0;
} 
