/*
题目描述
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。

输入格式
一行字符串表示二叉树，每个节点用','隔开。 比如二叉树 "3,9,20,null,null,15,7" 表示二叉树：

输出格式
一个整数，表示树的深度。

样例输入
Sample Input 1
3,9,20,null,null,15,7

Sample Input 2
2,null,3,null,4,null,5,null,6

样例输出
Sample Output 1
2

Sample Output 2
5

数据范围
节点个数不超过10^5。节点的值在-1000到1000范围内。
*/

#include <iostream>

using namespace std;

class BTree;

class Node
{
    friend class BTree;
public:
    int data;
    int left;
    int right;
    Node(int x,int l=1001,int r=1001)
    {
        data=x;
        left=l;
        right=r;
    };
};

class BTree
{
private:
    Node *root;
    char stopFlag;
    int Size(Node<elemType> *t); //求以t为根的二叉树的结点个数。
    int Height(Node<elemType> *t); //求以t为根的二叉树的高度。
    void DelTree(Node<elemType> *t); //删除以t为根的二叉树
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
};

void BTree::createTree(int &flag) //创建一棵二叉树
{
    seqQueue<Node*> que;
    int e, el, er;
    Node *p, *pl, *pr;
    stopFlag = flag;
    cout<<"Please input the root: ";
    cin>>e;
    if(e==flag)
    {
    	root = NULL;
        return;
    }
    p = new Node(e);
    root = p; //根结点为该新创建结点que.enQueue(p);
    while(!que.isEmpty())
    {
    	p = que.front(); //获得队首元素并出队
    	que.deQueue();
    	cout<<"Please input the left child and the right child of "<<p->data<<" using "<<flag<<" as no child: ";
    	cin>>el>>er;
        if(el!=flag) //该结点有左孩子
        {
        	pl = new Node(el);
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

int main()
{
    char* str;
    Node tree[100000];
    str=new char[1000000]
    cin.getline(str,1000000,'\n');
    int i=0;
    int j=0;
    int flag==0;
    int tmp=0;
    while(str[i]!='\0')
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            if(flag==0)
            {
                tmp=0;
            }
            tmp=tmp*10+(int)(str[i]);
        }
        else if(str[i]=='n')
        {
            Node n(1001);
            tree[j]=n;
            j++;
            i=i+5;
            flag=0;
        }
        else if(str=',')
        {
            Node n(tmp);
            flag=0;
        }
    }
    BTree tree;
    tree.createTree(1001);

    return 0;
}
