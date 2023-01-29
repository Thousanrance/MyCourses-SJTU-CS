#include <iostream>
using namespace std;

int main()
{
    char str[80];
    int i=0;

    while((str[i]=cin.get())!='\n')
    {    
        i++;
    }
    str[i+1] = '\0';

    char str2[80];
    int j=0,p=0;
    
    for(j=0;j<=i+1;j++)
    {
        for(p=j+1;p<=i+1;p++)
        {
            if(str[j]==str[p])
            {
                break;
            }
        }

        if(p>i+1)
        {
            str2[j]=str[j];
        }
        else
        {
            str2[j]='\0';
        }
    }

    char tmp;

    for(int x=0;x<=i;x++)
    {
        for(int y=x+1;y<=i;y++)
        {
            if(str2[y]>str2[x])
            {
                tmp=str2[x];
                str2[x]=str2[y];
                str2[y]=tmp;
            }
        }
    }
   
   for(int q=0;q<=i;q++)
   {
   		if(str2[q]=='\0')
   		{
   			continue;	
		}
		else
		{
			cout<<str2[q];	
		}
   }
   
    return 0;
}

