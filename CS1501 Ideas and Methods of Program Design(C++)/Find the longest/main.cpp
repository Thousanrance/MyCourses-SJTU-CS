/*
�������񣺱�дһ������Ѱ��һƪӢ����������Ļ����ַ�����
�����ļ����ᳬ��10000�ַ�������ļ�����һ�л���У�����ÿ�ж�������80���ַ������������Ļ��з�����
��Ѱ�һ���ʱֻ������ĸ��A��-��Z���͡�a��-��z�������������ַ������磺�����ţ��ո�ȣ���
����ĵ�һ��Ӧ�ð����ҵ�����Ļ��ĵĳ��ȡ���һ�л���Ӧ�ð���������ĵ�ԭ�ģ�û�г�ȥ�����ţ��ո�ȣ�����������������һ�л���У���������а������з�����
����ж�����ĳ��ȶ��������ֵ�������ǰ����ֵ���һ����ע�⣬���ʱ��Ҫȥ���������˵������ַ���
eg��
�������룺
Confucius say: Madam, I'm Adam.
Ԥ�������
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

	int index=0;//art���ַ���

	cin.getline(art,10125,'\t');

	index=strlen(art);

	char temp[2],tmp[2];
	int m;//max���һλ�±�
	char max[10125]={'\0'};
	int judge=0;//�Ƿ����
	int i=0,j=0;

	int num=index,start=0,begin=0;
	for(num=index;num>=2;num--)//��λ�������ַ�����ʼ�жϣ�ÿ��ѭ������һ��
	{
		start=0;//����ǰ�濪ʼ

		do//��ʼ��ÿ��ѭ������һ��
		{
			char test[10125]={'\0'};
			for(begin=start;begin<start+num;begin++)//�ӿ�ʼ��������Ӧλ�����ַ����õ�test
			{
				temp[0]=art[begin];
				//cout<<"temp="<<temp<<endl;
				strcat(test,temp);
				//cout<<"test="<<test<<endl;
			}

			char check[10125]={'\0'};
            i=0;j=0;
			for(i=0;i<num;i++)//ȥ��test�г���ĸ������ַ��õ�check
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

			if(j%2==0)//�ж�check�Ƿ���ģ�����ż����
			{
				int x=0;
				for(x=0;x<j/2;x++)
				{
					if(check[x]!=check[j-1-x]&&check[x]-check[j-1-x]!=32&&check[x]-check[j-1-x]!=-32)//���Դ�Сд
					{
						break;//һλ�����ľ�break������ѭ������
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
				strcpy(max,test);//��check���ģ���test����max��
				m=strlen(max)-1;
                break;//�õ���break����ΪҪ��λ�����ģ�����ѭ������
				//cout<<"max="<<max<<endl;
			}

			start++;

		}while(start<=index-num);

        if(judge==1)
        {
            break;
        }
	}

    for(int n=m;n>=0;n--)//ȥ������������ĸ����ķ���
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

    }while(1);//����ǰ��������ĸ����ķ���

    cout<<j<<endl;

    for(int final=fro;max[final]!='\0';final++)
    {
        cout<<max[final];
    }

	return 0;
}
