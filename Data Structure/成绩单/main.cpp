#include <iostream>

using namespace std;

struct Stu
{
    double math;
    double chinese;
    double english;
    double average;

    Stu(double a=0,double b=0,double c=0)
    {
        math=a;
        chinese=b;
        english=c;
        average=math*0.4+chinese*0.3+english*0.3;
    }

    void display()
    {
        cout<<math<<' '<<chinese<<' '<<english<<endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num;
    cin>>num;
    Stu* stus=new Stu[num];
    for(int i=0;i<num;i++)
    {
        double a,b,c;
        cin>>a>>b>>c;
        Stu tmp(a,b,c);
        stus[i]=tmp;
    }
    for(int i=0;i<num-1;i++)
    {
        for(int j=1;j<num;j++)
        {
            if(stus[j].average>stus[i].average)
            {
                Stu temp;
                temp=stus[i];
                stus[i]=stus[j];
                stus[j]=temp;
            }
            else if(stus[j].average==stus[i].average)
            {
                if(stus[j].math>stus[i].math)
                {
                    Stu temp;
                    temp=stus[i];
                    stus[i]=stus[j];
                    stus[j]=temp;
                }
                else if(stus[j].math==stus[i].math)
                {
                    if(stus[j].chinese>stus[i].chinese)
                    {
                        Stu temp;
                        temp=stus[i];
                        stus[i]=stus[j];
                        stus[j]=temp;
                    }
                    else if(stus[j].chinese==stus[i].chinese)
                    {
                        if(stus[j].english>stus[i].english)
                        {
                            Stu temp;
                            temp=stus[i];
                            stus[i]=stus[j];
                            stus[j]=temp;
                        }
                    }
                }
            }
        }
    }

    for(int i=0;i<num;i++)
    {
        stus[i].display();
    }
    return 0;
}
