#include <iostream>

using namespace std;

class Node
{
public:
    int coff,exp; //coff�洢ϵ����exp�洢ָ��
    Node *next;
    Node()
    {
        next=NULL;
    }
    Node(int n1,int n2,Node *p=NULL):coff(n1),exp(n2),next(p){};
};

Node *add(Node *exp1,Node *exp2)
{
    Node *res,*p,*tmp; //res��żӵĽ���ĵ�����pָ��res�ı�β�ڵ�
    res=p=new Node(); //Ϊ��Ž���ĵ���������ͷ���
    exp1=exp1->next;
    exp2=exp2->next;
    while(exp1!=NULL&&exp2!=NULL) //�鲢����������
    {
        if(exp1->exp<exp2->exp) //ֱ�Ӹ��Ʊ��ʽ1����
        {
            p->next=new Node(exp1->coff,exp1->exp);
            exp1=exp1->next;
        }
        else if(exp1->exp>exp2->exp) //ֱ�Ӹ��Ʊ��ʽ2����
        {
            p->next=new Node(exp2->coff,exp2->exp);
            exp2=exp2->next;
        }
        else if(exp1->coff+exp2->coff!=0) //�鲢�������ʽ��ͬ����
        {
            p->next=new Node(exp1->coff+exp2->coff,exp2->exp);
            exp1=exp1->next;
            exp2=exp2->next;
        }
        p=p->next;
    }
    //����δ�����ı��ʽ���������ʽ
    if(exp1==NULL)
    {
        tmp=exp2;
    }
    else
    {
        tmp=exp1;
    }
    while(tmp!=NULL)
    {
        p->next=new Node(tmp->coff,tmp->exp);
        tmp=tmp->next;
        p=p->next;
    }
    return res;
}

int main()
{
    return 0;
}
