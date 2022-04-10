#include <iostream>
#include <cstring>
using namespace std;

char *julian(int year,int day)
{
    char month[4];
    char date[3];
    char *calendar;
    calendar=new char[7];
    calendar[0]={'\0'};
    int f;
    if(year%400==0||(year%100!=0&&year%4==0))
    {
        f=29;
    }
    else
    {
        f=28;
    }
    if(day>337+f)
    {
        return NULL;
    }
    else if(day>0&&day<=31)
    {
        strcpy(month,"Jan");
    }
    else if(day>31&&day<=31+f)
    {
        strcpy(month,"Feb");
        day=day-31;
    }
    else if(day>31+f&&day<=62+f)
    {
        strcpy(month,"Mar");
        day=day-31-f;
    }
    else if(day>62+f&&day<=92+f)
    {
        strcpy(month,"Apr");
        day=day-62-f;
    }
    else if(day>92+f&&day<=123+f)
    {
        strcpy(month,"May");
        day=day-92-f;
    }
    else if(day>123+f&&day<=153+f)
    {
        strcpy(month,"Jun");
        day=day-123-f;
    }
    else if(day>153+f&&day<=184+f)
    {
        strcpy(month,"Jul");
        day=day-153-f;
    }
    else if(day>184+f&&day<=215+f)
    {
        strcpy(month,"Aug");
        day=day-184-f;
    }
    else if(day>215+f&&day<=245+f)
    {
        strcpy(month,"Sep");
        day=day-215-f;
    }
    else if(day>245+f&&day<=276+f)
    {
        strcpy(month,"Oct");
        day=day-245-f;
    }
    else if(day>276+f&&day<=306+f)
    {
        strcpy(month,"Nov");
        day=day-276-f;
    }
    else
    {
        strcpy(month,"Dec");
        day=day-306-f;
    }

    //cout<<month<<endl;

    date[0]=(char)(day/10)+'0';
    date[1]=(char)(day%10)+'0';

    //cout<<date<<endl;

    strcat(calendar,month);
    //cout<<calendar<<'$'<<endl;
    calendar[3]=' ';
    //cout<<calendar<<'$'<<endl;
    strcat(calendar,date);
    //cout<<calendar<<'$'<<endl;

    return calendar;
}

int main()
{
    int year,day;
    char* res;
    cin>>year>>day;
    res=julian(year,day);
    cout<<res<<endl;
    delete []res;
    return 0;
}
