#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node(int d,node *n=NULL)
    {
        data=d;
        next=n;
    }
};

int main()
{
    node *head,*p,*q; //head为链表头
    int n,i;
    //输入n
    cout<<"\ninput n:";
    cin>>n;
    //建立链表
    head=p=new node(0); //创建第一个结点，head指向表头，p指向表尾
    for(i=1;i<n;i++) //构建单循环链表
    {
        p=p->next=new node(i); //创建的结点连入表尾
    }
    p->next=head; //头尾相连

    q=head; //head报数为1，q指向被删结点
    while(q->next!=q) //表中元素多于一个
    {
        p=q->next;
        q=p->next; //p报数为2，q报数为3
        //删除q
        p->next=q->next; //绕过结点q
        cout<<q->data<<'\t'; //显示被删者的编号
        delete q; //回收被删者的空间
        q=p->next; //让q指向报1的结点
    }
    //打印结果
    cout<<"\n最后剩下："<<q->data<<endl;
    return 0;
}
