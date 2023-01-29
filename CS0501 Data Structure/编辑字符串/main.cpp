#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
    char* str=new char [20001];
    cin>>str;
    int l=strlen(str);
    stack<char> del;
    for(int i=0;i<l;i++)
    {
        if(del.empty())
        {
            del.push(str[i]);
            continue;
        }
        char tmp;
        tmp=del.top();
        if(tmp==str[i])
        {
            del.pop();
        }
        else
        {
            del.push(str[i]);
        }
    }

    stack<char> print;
    while(1)
    {
        if(del.empty())
        {
            break;
        }
        char temp;
        temp=del.top();
        del.pop();
        print.push(temp);
    }
    while(1)
    {
        if(print.empty())
        {
            break;
        }
        char prt;
        prt=print.top();
        cout<<prt;
        print.pop();
    }
    return 0;
}
