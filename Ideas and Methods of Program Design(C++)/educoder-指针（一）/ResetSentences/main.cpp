#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[100];
    int num=1;
    char *rword[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

    cin.getline(str,100);
    int len=strlen(str);

    for(int i=0;i<len;i++)
    {
        if(str[i]==' ')
        {
            str[i]='\0';
            rword[num]=&str[i+1];
            num++;
        }
    }

    cout<<num<<endl;

    char tmp[10];
    int r[10];

    for(int j=0;j<num;j++)
    {
        cin>>tmp[j];
        r[j]=(int)tmp[j]-48;
    }

    int n;
    for(int m=0;m<num;m++)
    {
        if(r[m]==0)
        {
            cout<<str;
        }
        else
        {
            n=r[m];
            cout<<rword[n]<<' ';
        }
    }

    return 0;
}
