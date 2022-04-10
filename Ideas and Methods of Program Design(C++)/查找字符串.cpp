#include <iostream>

using namespace std;

int main()
{
    char str1[160],str2[160];
    
    int i=0,j=0;

    while((str1[i]=cin.get())!='\n')
    {    
        i++;
    }
    str1[i] = '\0';

    while((str2[j]=cin.get())!='\n')
    {    
        j++;
    }
    str2[j] = '\0';
    
    int x=0,y=0,index=0;

    for(x=0;str1[x+j-1]!='\0';x++)
    {
        for(y=0;str2[y]!='\0';y++)
        {
            if(str1[x+y]!=str2[y])
			{
				break;
			} 
        }
        
        if(str2[y]=='\0')
		{
			index=x;
			break;
		} 
    }
    
    if(str1[x+j-1]=='\0')
    {
    	index=-1;
	}
	
	cout<<index;
    
    return 0;
}
