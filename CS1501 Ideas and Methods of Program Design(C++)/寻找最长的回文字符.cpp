//1���õ�һ������д�������ַ��� 
//2���õڶ����������λ��ʼ�棬���ʱ���ȥ�����ַ� 
//3���ж��Ƿ���ģ����Ϻ���һλ�ٴ����жϣ���λѭ����λ��+1��if(art[x]>='a'&&art[x]<='z'||art[x]>='A'&&art[x]<='Z')
 
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
			//�ж��Ƿ���ģ����Դ�Сд	
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
