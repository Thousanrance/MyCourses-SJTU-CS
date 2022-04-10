#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[25];
    cin.getline(str,25);
    int len=strlen(str),num=0;

    if(len>20)
    {
        cout<<"输入不符合要求";//长度不能大于20个字符
        return 0;
    }

    do
    {
        num=0;//敏感词个数归零
        for(int i=0;i<len;i++)
        {
            if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9')||str[i]==','||str[i]=='.'||str[i]=='"'||str[i]==';'||str[i]=='@'||str[i]=='#'||str[i]=='$'||str[i]==' '||str[i]=='\0')
            {
                if(str[i]=='L'||str[i]=='l')
                {
                    for(int j=i+1;j<len;j++)
                    {
                        if(str[j]=='@'||str[j]=='#'||str[j]=='$'||str[j]==' '||str[j]=='\0')
                        {
                            continue;
                        }
                        else if(str[j]=='4')
                        {
                            num++;
                            for(int m=i;m<=j;m++)
                            {
                                str[m]='\0';
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }//处理L4

                if(str[i]=='F'||str[i]=='f')
                {
                    for(int x=i+1;x<len;x++)
                    {
                        if(str[x]=='@'||str[x]=='#'||str[x]=='$'||str[x]==' '||str[x]=='\0')
                        {
                            continue;
                        }
                        else if(str[x]=='D'||str[x]=='d')
                        {
                            num++;
                            for(int y=i;y<=x;y++)
                            {
                                str[y]='\0';
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }//处理Fd

                if(str[i]=='D'||str[i]=='d')
                {
                    for(int p=i+1;p<len;p++)
                    {
                        if(str[p]=='@'||str[p]=='#'||str[p]=='$'||str[p]==' '||str[p]=='\0')
                        {
                            continue;
                        }
                        else if(str[p]=='2')
                        {
                            for(int q=p+1;q<len;q++)
                            {
                                if(str[q]=='@'||str[q]=='#'||str[q]=='$'||str[q]==' '||str[q]=='\0')
                                {
                                    continue;
                                }
                                else if(str[q]=='6')
                                {
                                    num++;
                                    for(int r=i;r<=q;r++)
                                    {
                                        str[r]='\0';
                                    }
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }//处理D26
            }
            else
            {
                cout<<"输入不符合要求";//有不接受字符
                return 0;
            }
        }
    }while(num!=0);//目前还有没有敏感词？

    char final[20]={'\0'},tmp[2]={'\0'};

    for(int k=0;k<len;k++)
    {
       if(str[k]!='\0')
       {
           tmp[0]=str[k];
           strcat(final,tmp);
       }
    }//删掉'\0'

    cout<<final;

    return 0;
}
