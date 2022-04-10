#include <iostream>
#include <cstring>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

struct Student
{
    char name[21];
    Date birthday;
    char phone[12];
    char address[50];
};


int main()
{
    int n;
    cin>>n;
    cin.clear();
    cin.ignore();

    Student eachstudent[10];

    for(int i=0;i<n;i++)
    {
        cin.getline(eachstudent[i].name,21,' ');
        cin>>eachstudent[i].birthday.year>>eachstudent[i].birthday.month>>eachstudent[i].birthday.day;
        cin.clear();
        cin.ignore();
        cin.getline(eachstudent[i].phone,12,' ');
        cin.getline(eachstudent[i].address,50,'\n');
    }

        int index[10]={0,1,2,3,4,5,6,7,8,9};
        int tmp;

        for(int x=0;x<n-1;x++)
        {
            for(int y=x+1;y<n;y++)
            {
                if(eachstudent[index[y]].birthday.year>eachstudent[index[x]].birthday.year)
                {
                    tmp=index[x];
                    index[x]=index[y];
                    index[y]=tmp;
                }
                else if(eachstudent[index[y]].birthday.year==eachstudent[index[x]].birthday.year)
                {
                    if(eachstudent[index[y]].birthday.month>eachstudent[index[x]].birthday.month)
                    {
                        tmp=index[x];
                        index[x]=index[y];
                        index[y]=tmp;
                    }
                    else if(eachstudent[index[y]].birthday.month==eachstudent[index[x]].birthday.month)
                    {
                        if(eachstudent[index[y]].birthday.day>eachstudent[index[x]].birthday.day)
                        {
                            tmp=index[x];
                            index[x]=index[y];
                            index[y]=tmp;
                        }
                    }
                }
            }
        }

    Student *p;

    for(int j=0;j<n;j++)
    {
        p=&eachstudent[index[j]];
        cout<<p->name<<' ';
        cout<<p->birthday.year<<' '<<p->birthday.month<<' '<<p->birthday.day<<' ';
        cout<<p->phone<<' ';
        cout<<p->address;
        cout<<endl;
    }

    return 0;
}
