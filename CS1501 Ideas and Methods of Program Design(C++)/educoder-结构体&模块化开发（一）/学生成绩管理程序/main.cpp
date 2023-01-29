#include<iostream>
#include<cstring>

using namespace std;

struct Student
{
    long long id;
    int grade1;
    int grade2;
    int grade3;
    char name[50];
};
static int i=0;

void order1(Student all[])
{
    long long idt;
    cin>>idt;
    int pos=0;
    while(pos<i&&all[pos].id!=idt)
    {
        pos++;
    }
    all[pos].id=idt;
    cin>>all[pos].grade1>>all[pos].grade2>>all[pos].grade3;
    cin.clear();
    cin.ignore();
    cin.getline(all[pos].name,50,'\n');
    //cout<<all[pos].id<<' '<<all[pos].grade1<<' '<<all[pos].grade2<<' '<<all[pos].grade3<<' '<<all[pos].name<<endl;
    if(pos<i)
    {
        return;
    }
    else
    {
        i++;
        //cout<<i<<endl;
    }
}
void order2(Student all[])
{
    long long idt;
    cin>>idt;
    int pos=0;
    while(pos<i&&all[pos].id!=idt)
    {
        pos++;
    }
    if(pos<i)
    {
        cin>>all[pos].grade1>>all[pos].grade2>>all[pos].grade3;
        cin.clear();
        cin.ignore();
        cin.getline(all[pos].name,50,'\n');
    }
    else
    {
        int ws1,ws2,ws3;
        cin>>ws1>>ws2>>ws3;
        cin.clear();
        cin.ignore();
        char strws[50];
        cin.getline(strws,50,'\n');
        return;
    }
}
void order3(Student all[])
{
    long long idt;
    cin>>idt;
    int pos=0;
    while(pos<i&&all[pos].id!=idt)
    {
        pos++;
    }
    if(pos<i)
    {
        for(int j=pos;j<i-1;j++)
        {
            all[j].id=all[j+1].id;
            all[j].grade1=all[j+1].grade1;
            all[j].grade2=all[j+1].grade2;
            all[j].grade3=all[j+1].grade3;
            strcpy(all[j].name,all[j+1].name);
        }
        i--;
        //cout<<i<<endl;
    }
    else
    {
        return;
    }

}
void order4(Student all[])
{
    long long idt;
    cin>>idt;
    //cout<<idt<<endl;
    int pos=0;
    while(pos<i&&all[pos].id!=idt)
    {
        pos++;
    }
    if(pos<i)
    {
        cout<<all[pos].id<<' '<<all[pos].name<<' '<<all[pos].grade1<<' '<<all[pos].grade2<<' '<<all[pos].grade3<<' '<<endl;
    }
    else
    {
        return;
    }
}
void order5(Student all[])
{
    char namet[50];
    cin.getline(namet,50,'\n');
    for(int m=0;m<i;m++)
    {
        if(strcmp(all[m].name,namet)==0)
        {
            cout<<all[m].id<<' '<<all[m].name<<' '<<all[m].grade1<<' '<<all[m].grade2<<' '<<all[m].grade3<<' '<<endl;
        }
    }
}
void order6(Student all[])
{
    int tmp;
    int index[1000];
    for(int k=0;k<=1000;k++)
    {
        index[k]=k;
    }
    for(int x=0;x<i-1;x++)
    {
        for(int y=x+1;y<i;y++)
        {
            if(all[index[y]].id<all[index[x]].id)
            {
                tmp=index[x];
                index[x]=index[y];
                index[y]=tmp;
            }
        }
    }
    for(int p=0;p<i;p++)
    {
        cout<<all[index[p]].id<<' '<<all[index[p]].name<<' '<<all[index[p]].grade1<<' '<<all[index[p]].grade2<<' '<<all[index[p]].grade3<<' '<<endl;
    }
}
void order7(Student all[])
{
    int tmp;
    int index[1000];
    for(int k=0;k<=1000;k++)
    {
        index[k]=k;
    }
    for(int x=0;x<i-1;x++)
    {
        for(int y=x+1;y<i;y++)
        {
            if((all[index[y]].grade1+all[index[y]].grade2+all[index[y]].grade3)>(all[index[x]].grade1+all[index[x]].grade2+all[index[x]].grade3))
            {
                tmp=index[x];
                index[x]=index[y];
                index[y]=tmp;
            }
            else if((all[index[y]].grade1+all[index[y]].grade2+all[index[y]].grade3)==(all[index[x]].grade1+all[index[x]].grade2+all[index[x]].grade3))
            {
                if(all[index[y]].id<all[index[x]].id)
                {
                    tmp=index[x];
                    index[x]=index[y];
                    index[y]=tmp;
                }
            }
        }
    }
    for(int q=0;q<i;q++)
    {
        cout<<all[index[q]].id<<' '<<all[index[q]].name<<' '<<all[index[q]].grade1<<' '<<all[index[q]].grade2<<' '<<all[index[q]].grade3<<' '<<endl;
    }
}

int main()
{
    int order;
    Student all[1000];

    while(1)
    {
        cin>>order;
        cin.clear();
        cin.ignore();
        if(order==1)
        {
            order1(all);
            cin.clear();
        }
        else if(order==2)
        {
            order2(all);
            cin.clear();
        }
        else if(order==3)
        {
            order3(all);
            cin.clear();
        }
        else if(order==4)
        {
            order4(all);
            cin.clear();
        }
        else if(order==5)
        {
            order5(all);
            cin.clear();
        }
        else if(order==6)
        {
            order6(all);
            cin.clear();
        }
        else if(order==7)
        {
            order7(all);
            cin.clear();
        }
        else if(order==0)
        {
            return 0;
        }
        //cout<<order<<endl;
    }
}
