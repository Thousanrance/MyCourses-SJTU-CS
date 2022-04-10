#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    char article[10][80];

    int i=0,j=0;
    
    for(i=0;i<=n;i++)
    {
        j=0;
        while((article[i][j]=cin.get())!='\n')
        {    
            j++;
        }
        article[i][j] = '\0';
    }

    int num_cha=0,num_fig=0,num_els=0;

    for(int p=0;p<=n;p++)
    {
        for(int q=0;article[p][q]!='\0';q++)
        {
            if(article[p][q]>='0'&&article[p][q]<='9')
            {
                num_fig++;
            }
            else if(article[p][q]>='a'&&article[p][q]<='z'||article[p][q]>='A'&&article[p][q]<='Z')
            {
                num_cha++;
            }
            else if(article[p][q]==' ')
            {
                continue; 
            }
            else
            {
                num_els++;
            }
        }
    }

    cout<<"×ÖÄ¸:"<<num_cha<<endl;
    cout<<"Êý×Ö:"<<num_fig<<endl;
    cout<<"ÆäËû:"<<num_els<<endl;
     
    return 0;
}

