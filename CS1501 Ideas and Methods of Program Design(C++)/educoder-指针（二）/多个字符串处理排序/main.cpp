#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.clear();
    cin.ignore();
    char str[30][30];
    char ch;

    for(int i=0;i<n;i++)
    {
        cin.getline(str[i],30);
    }


    cin>>ch;

    int len;
    char tmp2[2]={'\0'};
    for(int x=0;x<n;x++)
    {
        char *tmp1;
        tmp1=new char[30];
        tmp1[0]='\0';
        len=strlen(str[x]);
        for(int y=0;y<len;y++)
        {
            if(str[x][y]!=ch)
            {
                tmp2[0]=str[x][y];
                strcat(tmp1,tmp2);
            }
        }
        strcpy(str[x],tmp1);
        delete []tmp1;
    }

    char tmp3[30]={'\0'};

    for(int p=0;p<n-1;p++)
    {
        for(int q=p+1;q<n;q++)
        {
            for(int r=0;str[p][r]!='\0'&&str[q][r]!='\0';r++)
            {
                if(str[q][r]>str[p][r])
                {
                    strcpy(tmp3,str[p]);
                    strcpy(str[p],str[q]);
                    strcpy(str[q],tmp3);
                    break;
                }
                else if(str[q][r]<str[p][r])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }

    for(int j=0;j<n;j++)
    {
        cout<<str[j]<<endl;
    }

    return 0;
}
