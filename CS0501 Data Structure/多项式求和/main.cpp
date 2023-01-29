#include <iostream>

using namespace std;

class Node
{
public:
    int coff,exp; //coff存储系数，exp存储指数
    Node *next;
    Node()
    {
        next=NULL;
    }
    Node(int n1,int n2,Node *p=NULL):coff(n1),exp(n2),next(p){};
};

Node *add(Node *exp1,Node *exp2)
{
    Node *res,*p,*tmp; //res存放加的结果的单链表，p指向res的表尾节点
    res=p=new Node(); //为存放结果的单链表申请头结点
    exp1=exp1->next;
    exp2=exp2->next;
    while(exp1!=NULL&&exp2!=NULL) //归并两个单链表
    {
        if(exp1->exp<exp2->exp) //直接复制表达式1的项
        {
            p->next=new Node(exp1->coff,exp1->exp);
            exp1=exp1->next;
        }
        else if(exp1->exp>exp2->exp) //直接复制表达式2的项
        {
            p->next=new Node(exp2->coff,exp2->exp);
            exp2=exp2->next;
        }
        else if(exp1->coff+exp2->coff!=0) //归并两个表达式的同次项
        {
            p->next=new Node(exp1->coff+exp2->coff,exp2->exp);
            exp1=exp1->next;
            exp2=exp2->next;
        }
        p=p->next;
    }
    //将尚未结束的表达式并入结果表达式
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
