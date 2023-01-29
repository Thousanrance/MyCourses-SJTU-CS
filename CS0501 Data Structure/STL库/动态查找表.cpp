#include <iostream>
//#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
    /*
    cout<<"关联容器set的使用实例如下："<<endl;
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
    cout<<"关联容器map的使用实例如下："<<endl;
    map<string,string> s;
    string name[6]={"钱一","孙二","张三","李四","王五","赵六"};
    string addr[6]={"上海","南京","杭州","南京","上海","上海"};
    map<string,string>::iterator p;

    //添加六个人的信息并显示
    for(int i=0;i<6;i++)
    {
        s.insert(pair<string,string>(name[i],addr[i]));
    }
    cout<<"The content of s:"<<endl;
    for(p=s.begin();p!=s.end();p++)
    {
        cout<<p->first<<" "<<p->second<<endl;
    }
    p=s.find("张三");
    cout<<"\nfind(\"张三\"):"<<p->first<<" "<<p->second<<endl;
    s.erase("张三");
    cout<<"After erase(\"张三\"),the content of s:"<<endl;
    for(p=s.begin();p!=s.end();p++)
    {
        cout<<p->first<<" "<<p->second<<endl;
    }
    cout<<endl;

    return 0;
}
