#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include<iostream>
#include"../��ʽջ/linkStack.h"
#include"../��ʽ����/linkQueue.h"
#include"../˳�����/seqQueue.h"
using namespace std;

//BTree���ǰ��˵��
template <class elemType>
class BTree;

template <class elemType>
class Node
{
    friend class BTree<elemType>;
private:
    elemType data;
    Node *left, *right;
    int leftFlag; //���ڱ�ʶ�Ƿ�������0ʱleftΪ���ӽ�㣬1ʱΪǰ������
    int rightFlag; //���ڱ�ʶ�Ƿ�������0ʱrightΪ�Һ��ӽ�㣬1ʱΪ�������
public:
    Node()
    {
        left=NULL;
        right=NULL;
        leftFlag = 0;
        rightFlag = 0;
    };
    Node(const elemType &e, Node* L=NULL, Node *R=NULL)
    {
        data = e;
    	left=L;
        right=R;
        leftFlag = 0;
        rightFlag=0;
    };
};

template <class elemType>
class BTree
{
private:
    Node<elemType> *root;
    elemType stopFlag;
    int Size(Node<elemType> *t); //����tΪ���Ķ������Ľ�������
    int Height(Node<elemType> *t); //����tΪ���Ķ������ĸ߶ȡ�
    void DelTree(Node<elemType> *t); //ɾ����tΪ���Ķ�����
    void PreOrder(Node<elemType> *t); // ��ǰ����������tΪ���Ķ������Ľ�������ֵ
    void InOrder(Node<elemType> *t); // ��������������tΪ���Ķ������Ľ�������ֵ
    void PostOrder(Node<elemType> *t); // ��������������tΪ���Ķ������Ľ�������ֵ
public:
    BTree()
    {
        root=NULL;
    }
    void createTree(const elemType &flag);//����һ�ö�����
    bool isEmpty()
    {
        return (root == NULL);
    } // �жϲ����Ƿ�Ϊ��
    Node<elemType> * GetRoot()
    {
        return root;
    }
    int Size (); //��������Ľ�������
    int Height (); //��������ĸ߶ȡ�
    void DelTree(); //ɾ��������
    void PreOrder(); //��ǰ���������������Ľ�������ֵ
    void InOrder(); //�������������������Ľ�������ֵ
    void PostOrder(); //�������������������Ľ�������ֵ
    void LevelOrder(); //�������������������Ľ�������ֵ
    void PreOrder2(); // ��ǰ����������tΪ���Ķ������Ľ�������ֵ���ǵݹ顿
    void InOrder2(); // ��������������tΪ���Ķ������Ľ�������ֵ���ǵݹ顿
    void PostOrder2(); // ��������������tΪ���Ķ������Ľ�������ֵ���ǵݹ顿
};

template <class elemType>
void BTree<elemType>::createTree(const elemType &flag) //����һ�ö�����
{
    seqQueue<Node<elemType>*> que;
    elemType e, el, er;
    Node<elemType> *p, *pl, *pr;
    stopFlag = flag;
    cout<<"Please input the root: ";
    cin>>e;
    if(e==flag)
    {
    	root = NULL;
        return;
    }
    p = new Node<elemType>(e);
    root = p; //�����Ϊ���´������que.enQueue(p);
    while(!que.isEmpty())
    {
    	p = que.front(); //��ö���Ԫ�ز�����
    	que.deQueue();
    	cout<<"Please input the left child and the right child of "<<p->data<<" using "<<flag<<" as no child: ";
    	cin>>el>>er;
        if(el!=flag) //�ý��������
        {
        	pl = new Node<elemType>(el);
        	p->left = pl;
        	que.enQueue(pl);
        }
        if(er!=flag) //�ý�����Һ���
        {
        	pr = new Node<elemType>(er);
        	p->right = pr;
        	que.enQueue(pr);
        }
    }
}

template <class elemType>
void BTree<elemType>::PreOrder()
{
    PreOrder(root);
}
template <class elemType>
void BTree<elemType>::PreOrder(Node<elemType> *t) //ǰ�������tΪ���������ݹ��㷨��ʵ�֡�
{
    if(!t)
    {
    	return;
    }
    cout<<t->data;
    PreOrder(t->left);
    PreOrder(t->right);
}

template <class elemType>
void BTree<elemType>::InOrder()
{
    InOrder(root);
}
template <class elemType>
void BTree<elemType>::InOrder(Node<elemType> *t) //���������tΪ���������ݹ��㷨��ʵ�֡�
{
	if(!t)
    {
    	return;
    }
    InOrder(t->left);
    cout<<t->data;
    InOrder(t->right);
}

template <class elemType>
void BTree<elemType>::PostOrder()
{
    PostOrder(root);
}
template <class elemType>
void BTree<elemType>::PostOrder(Node<elemType> *t) //���������tΪ���������ݹ��㷨��ʵ�֡�
{
	if(!t)
    {
    	return;
    }
    PostOrder(t->left);
    PostOrder(t->right);
    cout<<t->data;
}

template <class elemType>
int BTree<elemType>::Size()
{
    return Size(root);
}
template <class elemType>
int BTree<elemType>::Size (Node<elemType> *t) //�õ���tΪ�����������������ݹ��㷨ʵ�֡�
{
    if(!t)
    {
    	return 0;
    }
    return 1+Size(t->left)+Size(t->right);
}

template <class elemType>
int BTree<elemType>::Height()
{
    return Height(root);
}
template <class elemType>
int BTree<elemType>::Height(Node<elemType> *t) //�õ���tΪ���������ĸ߶ȣ��ݹ��㷨ʵ�֡�
{
    int hl, hr;
    if(!t)
    {
    	return 0;
    }
    hl = Height(t->left);
    hr = Height(t->right);
    if(hl>=hr)
    {
    	return 1+hl;
    }
    return 1+hr;
}

template <class elemType>
void BTree<elemType>::DelTree()
{
    DelTree(root);
	root = NULL;
}
template <class elemType>
void BTree<elemType>::DelTree(Node<elemType> *t)//ɾ����tΪ���Ķ��������ݹ��㷨ʵ��
{
    if(!t)
    {
    	return;
    }
    DelTree(t->left);
    DelTree(t->right);
    delete t;
}

template <class elemType>
void BTree<elemType>::LevelOrder() //��α����������㷨��ʵ�֡�
{
    linkQueue<Node<elemType> *> que;
    Node<elemType> *p;
    if(!root)
    {
    	return;
    } //������Ϊ��
    que.enQueue(root);
    while (!que.isEmpty())
    {
        p = que.front();
        que.deQueue();
        cout<<p->data;
        if(p->left)
        {
        	que.enQueue(p->left);
        }
        if(p->right)
        {
        	que.enQueue(p->right);
        }
    }
    cout << endl;
}

template <class elemType>
void BTree<elemType>::PreOrder2()  //ǰ������ķǵݹ��㷨ʵ��
{
    if(!root)
    {
    	return;
    }
    Node<elemType> *p;
    seqStack<Node<elemType> *> s;
    s.push(root);
    while (!s.isEmpty())
    {
        p=s.top(); s.pop();
    	cout << p->data;
    	if(p->right)
        {
        	s.push(p->right);
        }
    	if(p->left)
        {
        	s.push(p->left);
        }
    }
    cout << endl;
}

template <class elemType>
void BTree<elemType>::InOrder2()
{
    if(!root)
    {
    	return;
    }
    Node<elemType> *p;
    seqStack<Node<elemType> *> s;
    s.push(root);
    p=root;
    while(p->left)
    {
        s.push(p->left);
        p=p->left;
    }
    while(!s.isEmpty())
    {
        p=s.top();
        s.pop();
        cout<<p->data;
        if(p->right)
        {
            s.push(p->right);
            p=p->right;
            while(p->left)
            {
                s.push(p->left);
                p=p->left;
            }
        }
    }
}

template <class elemType>
void BTree<elemType>::PostOrder2()  //��������ķǵݹ��㷨ʵ�֡�
{
    if(!root)
    {
    	return;
    }
    Node<elemType> *p;
    linkStack<Node<elemType> *> s1;
    linkStack<int> s2;
    int zero=0, one=1, two=2;
    int flag;
    s1.push(root);
    s2.push(zero);
    while(!s1.isEmpty())
    {
        flag = s2.top(); s2.pop();
        p = s1.top();
        switch(flag)
        {
            case 2:
            		s1.pop();
            		cout << p->data;
            		break;
            case 1:
            		s2.push(two);
            		if(p->right)
                    {
                    	s1.push(p->right);
                    	s2.push(zero);
                    }
                    break;
            case 0:
                    s2.push(one);
                    if(p->left)
                    {
                    	s1.push(p->left);
                    	s2.push(zero);
                    }
                    break;
        }
    }
}

template <class T>
void printTree(const binaryTree<T> &t,T flag)
{
    linkQueue<T> q;
    q.enQueue(t.root->data);
    cout<<endl;
    while(!q.isEmpty())
    {
        char p,l,r;
        p=q.deQueue();
        l=t.lchild(p,flag);
        r=t.rchild(p,flag);
        cout<<p<<" "<<l<<" "<<r<<endl;
        if(l!=flag)
        {
            q.enQueue(l);
        }
        if(r!=flag)
        {
            q.enQueue(r);
        }
    }
}

#endif // BTREE_H_INCLUDED
