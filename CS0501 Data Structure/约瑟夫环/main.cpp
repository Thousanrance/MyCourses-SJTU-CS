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
    node *head,*p,*q; //headΪ����ͷ
    int n,i;
    //����n
    cout<<"\ninput n:";
    cin>>n;
    //��������
    head=p=new node(0); //������һ����㣬headָ���ͷ��pָ���β
    for(i=1;i<n;i++) //������ѭ������
    {
        p=p->next=new node(i); //�����Ľ�������β
    }
    p->next=head; //ͷβ����

    q=head; //head����Ϊ1��qָ��ɾ���
    while(q->next!=q) //����Ԫ�ض���һ��
    {
        p=q->next;
        q=p->next; //p����Ϊ2��q����Ϊ3
        //ɾ��q
        p->next=q->next; //�ƹ����q
        cout<<q->data<<'\t'; //��ʾ��ɾ�ߵı��
        delete q; //���ձ�ɾ�ߵĿռ�
        q=p->next; //��qָ��1�Ľ��
    }
    //��ӡ���
    cout<<"\n���ʣ�£�"<<q->data<<endl;
    return 0;
}
