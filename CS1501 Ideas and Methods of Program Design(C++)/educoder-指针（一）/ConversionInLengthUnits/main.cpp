#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char ContinueCheck;
    char inch[]="inch",feet[]="feet",yard[]="yard",mm[]="millimeter",cm[]="centimeter",dm[]="decimeter",m[]="meter";
    int len;
    double data;

label:  char *question;
        question=new char [100];
        cout<<"Please input:"<<endl;
        cin.getline(question,100);
        len=strlen(question);

        for(int i=0;i<len;i++)
        {
            if(question[i]>='0'&&question[i]<='9')
            {
                data=(int)(question[i]-'0');
            }
        }

        if(strstr(question,inch)!=NULL)
        {
            if(strstr(question,m)!=NULL&&strstr(question,mm)==NULL&&strstr(question,cm)==NULL&&strstr(question,dm)==NULL)
            {
                data=data*39.4;
            }
            else if(strstr(question,dm)!=NULL)
            {
                data=data*3.94;
            }
            else if(strstr(question,cm)!=NULL)
            {
                data=data*0.394;
            }
            else if(strstr(question,mm)!=NULL)
            {
                data=data*0.0394;
            }
        }
        else if(strstr(question,feet)!=NULL)
        {
            if(strstr(question,m)!=NULL&&strstr(question,mm)==NULL&&strstr(question,cm)==NULL&&strstr(question,dm)==NULL)
            {
                data=data*3.28;
            }
            else if(strstr(question,dm)!=NULL)
            {
                data=data*0.328;
            }
            else if(strstr(question,cm)!=NULL)
            {
                data=data*0.0328;
            }
            else if(strstr(question,mm)!=NULL)
            {
                data=data*0.00328;
            }
        }

        else if(strstr(question,yard)!=NULL)
        {
            if(strstr(question,m)!=NULL&&strstr(question,mm)==NULL&&strstr(question,cm)==NULL&&strstr(question,dm)==NULL)
            {
                data=data*1.0936;
            }
            else if(strstr(question,dm)!=NULL)
            {
                data=data*0.10936;
            }
            else if(strstr(question,cm)!=NULL)
            {
                data=data*0.010936;
            }
            else if(strstr(question,mm)!=NULL)
            {
                data=data*0.0010936;
            }
        }
        cout<<data<<endl;

        delete question;

        cout<<"Go on?(y/n):";
        cin>>ContinueCheck;

        if(ContinueCheck=='n')
        {
            return 0;
        }
        else
        {
            cin.clear();
            cin.ignore();
            goto label;
        }
}
