#include <iostream>
using namespace std;

int main()
{
    char str[30];
    int j=0;

    while((str[j]=cin.get())!='\n')
    {    
        j++;
    }
    str[j+1] = '\0';

    int Count=0,i=0;

    while(str[i]!='\0')
    {
        if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
        {
            Count++;
        }
        i++;
    }
	
	cout<<"Count="<<Count;
	
    return 0;
}

