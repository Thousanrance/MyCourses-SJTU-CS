#include <iostream>

using namespace std;

int main()
{
    char str1[20],str2[20];

    cin.getline(str1,20);
    cin.getline(str2,20);

    char tmp;
    char *p=str1;

    while((*p!='\0')&&(*(p-str1+str2)!='\0'))//ָ����Ժ�ƫ������Ӽ���ָ���ָ��Ҳ���������ƫ��������ָ�뱾�������
    {
        tmp=*p;
        *p=*(p-str1+str2);
        *(p-str1+str2)=tmp;
        p++;
    }

    cout<<str1<<endl;
    cout<<str2;

    return 0;
}
