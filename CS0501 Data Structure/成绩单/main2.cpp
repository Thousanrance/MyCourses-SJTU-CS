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

bool operator>=(const Stu &s1,const Stu &s2)
{
    if(s1.average>s2.average)
    {
        return true;
    }
    else if(s1.average==s2.average)
    {
        if(s1.math>s2.math)
        {
            return true;
        }
        else if(s1.math==s2.math)
        {
            if(s1.chinese>s2.chinese)
            {
                return true;
            }
            else if(s1.chinese==s2.chinese)
            {
                if(s1.english>=s2.english)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


int divide(Stu a[], int low, int high) //»®·Öº¯Êý
{
    Stu k = a[low];
    do
    {
        while(low < high && k >= a[high])
        {
            --high;
        }
        if(low < high)
        {
            a[low] = a[high];
            ++low;
        }
        while(low < high && a[low] >= k)
        {
            ++low;
        }
        if(low < high)
        {
            a[high] = a[low];
            --high;
        }
    }while(low != high);
    a[low] = k;
    return low;
}


void quickSort(Stu a[], int low, int high)
{
    int mid;
    if(low >= high)
    {
        return;
    }
    mid = divide(a, low, high);
    quickSort(a, low, mid-1); //ÅÅÐò×óÒ»°ë
    quickSort(a, mid+1, high); //ÅÅÐòÓÒÒ»°ë
}


void quickSort(Stu a[], int size) //°ü¹üº¯Êý
{
    quickSort(a, 0, size-1);
}

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
    quickSort(stus,num);
    for(int i=0;i<num;i++)
    {
        stus[i].display();
    }
    return 0;
}
