#include <iostream>
#include <cstring>
using namespace std;

bool func(char arra[ ], int len);

int main() {
    char ch[20];
    bool result;

    cin >> ch;

    result=func(ch,strlen(ch));

	if(result)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }

    return 0;
}

bool func(char arra[ ], int len)
{
    if(len<=1)
    {
        return true;
    }
	else if(arra[strlen(arra)-len]!=arra[len-1])
    {
        return false;
    }
    else
    {
        return func(arra,len-1);
    }
}
