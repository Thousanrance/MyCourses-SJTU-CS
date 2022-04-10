#include <iostream>
using namespace std;

struct Time
{
    int h;
    int m;
    int s;
};

void setTime(Time *p)
{
    cin>>p->h>>p->m>>p->s;
}

void increase(Time *p)
{
    p->s++;
    if(p->s>=60)
    {
        p->m++;
        p->s=p->s-60;
    }
    if(p->m>=60)
    {
        p->h++;
        p->m=p->m-60;
    }
    if(p->h>=24)
    {
        p->h=p->h-24;
    }
}

void standard(int t)
{
    if(t<10)
    {
        cout<<'0'<<t;
    }
    else
    {
        cout<<t;
    }
}

void showtime(Time *p)
{
    standard(p->h);
    cout<<':';
    standard(p->m);
    cout<<':';
    standard(p->s);
}

int main()
{
    Time time1,time2;
    Time *p1=&time1,*p2=&time2;

    setTime(p1);
    setTime(p2);

    showtime(p1);
    cout<<endl;
    increase(p1);
    showtime(p1);
    cout<<endl;
    showtime(p2);
    cout<<endl;
    increase(p2);
    showtime(p2);
    cout<<endl;

    return 0;
}
