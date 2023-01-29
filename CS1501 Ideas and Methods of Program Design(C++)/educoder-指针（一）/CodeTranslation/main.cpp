#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[30];

    cin.getline(str,30);

    int len=strlen(str);

    for(int i=1;i<=len;i++)
    {
        switch(i%7)
        {
            case 1:str[i-1]+=8;break;
            case 2:str[i-1]+=7;break;
            case 3:str[i-1]+=3;break;
            case 4:str[i-1]+=4;break;
            case 5:str[i-1]+=9;break;
            case 6:str[i-1]+=6;break;
            case 0:str[i-1]+=2;break;
        }

        if(str[i-1]>122)
        {
            str[i-1]=str[i-1]%91;
        }
    }

    cout<<str<<endl;


    for(int j=1;j<=len;j++)
    {
        switch(j%7)
        {
            case 1:str[j-1]-=8;break;
            case 2:str[j-1]-=7;break;
            case 3:str[j-1]-=3;break;
            case 4:str[j-1]-=4;break;
            case 5:str[j-1]-=9;break;
            case 6:str[j-1]-=6;break;
            case 0:str[j-1]-=2;break;
        }

        if(str[j-1]<32)
        {
            str[j-1]=str[j-1]+91;
        }
    }

    cout<<str;

    return 0;
}
