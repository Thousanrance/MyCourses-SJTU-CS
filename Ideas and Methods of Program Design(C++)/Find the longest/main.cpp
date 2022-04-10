/*
本关任务：编写一个程序，寻找一篇英文文章中最长的回文字符串。
输入文件不会超过10000字符。这个文件可能一行或多行，但是每行都不超过80个字符（不包括最后的换行符）。
在寻找回文时只考虑字母‘A’-‘Z’和‘a’-‘z’，忽略其他字符（例如：标点符号，空格等）。
输出的第一行应该包括找到的最长的回文的长度。下一行或几行应该包括这个回文的原文（没有除去标点符号，空格等），把这个回文输出到一行或多行（如果回文中包括换行符）。
如果有多个回文长度都等于最大值，输出最前面出现的那一个。注意，输出时需要去除回文两端的其他字符。
eg：
测试输入：
Confucius say: Madam, I'm Adam.
预期输出：
11
Madam, I'm Adam
*/

#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
	char art[10125];

	int index=0;//art总字符数

	cin.getline(art,10125,'\t');

	index=strlen(art);

	char temp[2],tmp[2];
	int m;//max最后一位下标
	char max[10125]={'\0'};
	int judge=0;//是否回文
	int i=0,j=0;

	int num=index,start=0,begin=0;
	for(num=index;num>=2;num--)//从位数最大的字符串开始判断，每次循环减少一个
	{
		start=0;//从最前面开始

		do//开始处每次循环后移一个
		{
			char test[10125]={'\0'};
			for(begin=start;begin<start+num;begin++)//从开始处读入相应位数的字符串得到test
			{
				temp[0]=art[begin];
				//cout<<"temp="<<temp<<endl;
				strcat(test,temp);
				//cout<<"test="<<test<<endl;
			}

			char check[10125]={'\0'};
            i=0;j=0;
			for(i=0;i<num;i++)//去掉test中除字母以外的字符得到check
			{
				if((test[i]>='a'&&test[i]<='z')||(test[i]>='A'&&test[i]<='Z'))
				{
					tmp[0]=test[i];
					//cout<<"tmp="<<tmp<<endl;
					strcat(check,tmp);
					//cout<<"check="<<check<<endl;
					j++;
				}
			}

			if(j%2==0)//判断check是否回文，分奇偶讨论
			{
				int x=0;
				for(x=0;x<j/2;x++)
				{
					if(check[x]!=check[j-1-x]&&check[x]-check[j-1-x]!=32&&check[x]-check[j-1-x]!=-32)//忽略大小写
					{
						break;//一位不回文就break，减少循环次数
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
				strcpy(max,test);//若check回文，则将test赋给max；
				m=strlen(max)-1;
                break;//得到即break，因为要找位数最大的，减少循环次数
				//cout<<"max="<<max<<endl;
			}

			start++;

		}while(start<=index-num);

        if(judge==1)
        {
            break;
        }
	}

    for(int n=m;n>=0;n--)//去掉后面所有字母以外的符号
    {
        if((max[n]>='a'&&max[n]<='z')||(max[n]>='A'&&max[n]<='Z'))
        {
            break;
        }
        else
        {
            max[n]='\0';
        }
    }

    int fro=0;

    do
    {
        if((max[fro]>='a'&&max[fro]<='z')||(max[fro]>='A'&&max[fro]<='Z'))
        {
            break;
        }
        else
        {
            fro++;
        }

    }while(1);//忽略前面所有字母以外的符号

    cout<<j<<endl;

    for(int final=fro;max[final]!='\0';final++)
    {
        cout<<max[final];
    }

	return 0;
}
