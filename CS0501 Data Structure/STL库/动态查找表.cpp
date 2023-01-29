#include <iostream>
//#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
    /*
    cout<<"��������set��ʹ��ʵ�����£�"<<endl;
    set<int> s;
    int a[21]={0,4,7,10,2,9,8,12,13,17,3,18,1,15,5,6,11,14,16,20,19};
    set<int>::iterator p;
    for(int i=0;i<21;i++)
    {
        s.insert(a[i]);
    }
    cout<<"The content of s:";
    for(p=s.begin();p!=s.end();p++)
    {
        cout<<*p<<' ';
    }
    cout<<"\nfind(18):"<<*(s.find(18))<<endl;
    s.erase(17);
    cout<<"After erase(17),the content of s:";
    for(p=s.begin();p!=s.end();p++)
    {
        cout<<*p<<' ';
    }
    cout<<endl;
    */

    cout<<endl;
    cout<<"��������map��ʹ��ʵ�����£�"<<endl;
    map<string,string> s;
    string name[6]={"Ǯһ","���","����","����","����","����"};
    string addr[6]={"�Ϻ�","�Ͼ�","����","�Ͼ�","�Ϻ�","�Ϻ�"};
    map<string,string>::iterator p;

    //��������˵���Ϣ����ʾ
    for(int i=0;i<6;i++)
    {
        s.insert(pair<string,string>(name[i],addr[i]));
    }
    cout<<"The content of s:"<<endl;
    for(p=s.begin();p!=s.end();p++)
    {
        cout<<p->first<<" "<<p->second<<endl;
    }
    p=s.find("����");
    cout<<"\nfind(\"����\"):"<<p->first<<" "<<p->second<<endl;
    s.erase("����");
    cout<<"After erase(\"����\"),the content of s:"<<endl;
    for(p=s.begin();p!=s.end();p++)
    {
        cout<<p->first<<" "<<p->second<<endl;
    }
    cout<<endl;

    return 0;
}
