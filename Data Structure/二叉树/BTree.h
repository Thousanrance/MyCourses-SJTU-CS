#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include<iostream>
#include"../链式栈/linkStack.h"
#include"../链式队列/linkQueue.h"
#include"../顺序队列/seqQueue.h"
using namespace std;

//BTree类的前项说明
template <class elemType>
class BTree;

template <class elemType>
class Node
{
    friend class BTree<elemType>;
private:
    elemType data;
    Node *left, *right;
    int leftFlag; //用于标识是否线索，0时left为左孩子结点，1时为前驱线索
    int rightFlag; //用于标识是否线索，0时right为右孩子结点，1时为后继线索
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
    int Size(Node<elemType> *t); //求以t为根的二叉树的结点个数。
    int Height(Node<elemType> *t); //求以t为根的二叉树的高度。
    void DelTree(Node<elemType> *t); //删除以t为根的二叉树
    void PreOrder(Node<elemType> *t); // 按前序遍历输出以t为根的二叉树的结点的数据值
    void InOrder(Node<elemType> *t); // 按中序遍历输出以t为根的二叉树的结点的数据值
    void PostOrder(Node<elemType> *t); // 按后序遍历输出以t为根的二叉树的结点的数据值
public:
    BTree()
    {
        root=NULL;
    }
    void createTree(const elemType &flag);//创建一棵二叉树
    bool isEmpty()
    {
        return (root == NULL);
    } // 判断叉树是否为空
    Node<elemType> * GetRoot()
    {
        return root;
    }
    int Size (); //求二叉树的结点个数。
    int Height (); //求二叉树的高度。
    void DelTree(); //删除二叉树
    void PreOrder(); //按前序遍历输出二叉树的结点的数据值
    void InOrder(); //按中序遍历输出二叉树的结点的数据值
    void PostOrder(); //按后序遍历输出二叉树的结点的数据值
    void LevelOrder(); //按中序遍历输出二叉树的结点的数据值
    void PreOrder2(); // 按前序遍历输出以t为根的二叉树的结点的数据值【非递归】
    void InOrder2(); // 按中序遍历输出以t为根的二叉树的结点的数据值【非递归】
    void PostOrder2(); // 按后序遍历输出以t为根的二叉树的结点的数据值【非递归】
};

template <class elemType>
void BTree<elemType>::createTree(const elemType &flag) //创建一棵二叉树
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
    root = p; //根结点为该新创建结点que.enQueue(p);
    while(!que.isEmpty())
    {
    	p = que.front(); //获得队首元素并出队
    	que.deQueue();
    	cout<<"Please input the left child and the right child of "<<p->data<<" using "<<flag<<" as no child: ";
    	cin>>el>>er;
        if(el!=flag) //该结点有左孩子
        {
        	pl = new Node<elemType>(el);
        	p->left = pl;
        	que.enQueue(pl);
        }
        if(er!=flag) //该结点有右孩子
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
void BTree<elemType>::PreOrder(Node<elemType> *t) //前序遍历以t为根二叉树递归算法的实现。
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
void BTree<elemType>::InOrder(Node<elemType> *t) //后序遍历以t为根二叉树递归算法的实现。
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
void BTree<elemType>::PostOrder(Node<elemType> *t) //后序遍历以t为根二叉树递归算法的实现。
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
int BTree<elemType>::Size (Node<elemType> *t) //得到以t为根二叉树结点个数，递归算法实现。
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
int BTree<elemType>::Height(Node<elemType> *t) //得到以t为根二叉树的高度，递归算法实现。
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
void BTree<elemType>::DelTree(Node<elemType> *t)//删除以t为根的二叉树，递归算法实现
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
void BTree<elemType>::LevelOrder() //层次遍历二叉树算法的实现。
{
    linkQueue<Node<elemType> *> que;
    Node<elemType> *p;
    if(!root)
    {
    	return;
    } //二叉树为空
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
void BTree<elemType>::PreOrder2()  //前序遍历的非递归算法实现
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
void BTree<elemType>::PostOrder2()  //后序遍历的非递归算法实现。
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
