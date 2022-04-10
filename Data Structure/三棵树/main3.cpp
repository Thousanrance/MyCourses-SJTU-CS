#include<iostream>
#include<cstring>
using namespace std;

void BinaryTreePostOrder(char* preOrder, char* midOrder,int len)
{
    if(len==0)
    {
        return;
    }
    char tmp = *preOrder;
    int i = 0;
    for (; i < len; i++)
    {
        if(midOrder[i] == *preOrder)
        {
            break;
        }
    }
    BinaryTreePostOrder(preOrder + 1, midOrder, i);
    BinaryTreePostOrder(preOrder + i + 1, midOrder + i + 1, len - i - 1);
    cout << tmp;
}
int main()
{
    char* str1 = new char[1000], * str2 = new char[1000];
    cin >> str1;
    cin >> str2;
    int l = strlen(str1);
    BinaryTreePostOrder(str1, str2, l);
    delete[]str1;
    delete[]str2;
    return 0;
}
