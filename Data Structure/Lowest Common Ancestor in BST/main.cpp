/*
题目描述
最近公共祖先指的是给定一棵二叉搜索树T及两个节点(u,v)，找到一个距离根节点最远的节点x，且x同时是u和v的祖先，那么x就是它们的最近公共祖先

               6
            /     \
          4         7
        /   \         \
      2      5         9
例如对上图的二叉搜索树，2和7的最近公共祖先是6，4和5的最近公共祖先是4（一个点可以是自己的祖先）

输入格式
每个测试用例由3行构成 第一行是序列的长度n，n<=10000 第二行是序列的所有n个整型元素 第三行是两个节点(u,v)

输出格式
对于给定的序列，先按照输入顺序构建二叉搜索树T 再寻找给定节点的最近公共祖先x 输出结果是节点x的值

样例输入
6
6 4 2 7 5 9
2 7

样例输出
6
*/

#include <iostream>
#include <queue>
using namespace std;

queue<int> ans1;
queue<int> ans2;

struct BinaryNode
{
    int data;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode(const int & thedata,BinaryNode *lt=NULL,BinaryNode *rt=NULL)
                :data(thedata),left(lt),right(rt){}
};

class BinarySearchTree
{
private:
    BinaryNode *root;
public:
    BinarySearchTree()
    {
        root=NULL;
    }
    ~BinarySearchTree()
    {
        delete root;
    }
    int *find(const int &x, queue<int> &q)const;
    void insert(const int &x);
    int *find2(const int &x)const; //非递归实现
    void insert2(const int &x); //非递归实现
private:
    void insert(const int & x, BinaryNode * &t);
    int *find(const int &x, BinaryNode *t, queue<int> &q)const;
};

int * BinarySearchTree::find(const int &x, queue<int> &q)const
{
    q.push(root->data);
    return find(x,root,q);
}

int * BinarySearchTree::find(const int &x, BinaryNode *t,queue<int> &q)const
{
    if (t == NULL)
    {
        return NULL;
    }
    if(t->data == x)
    {
        q.push(t->data);
        return &t->data;
    }
    if(x < t->data)
    {
        q.push(t->data);
        return find(x, t->left,q);
    }
    else
    {
        q.push(t->data);
        return find(x, t->right,q);
    }
}


int * BinarySearchTree::find2(const int &x)const
{
    if(!root)
    {
        return NULL;
    }
    BinaryNode *p; p = root;
    while(p)
    {
        if(x == p->data)
        {
            return &(p->data);
        }
        if(x < p->data)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return NULL;
}


void BinarySearchTree::insert(const int & x)
{
    insert(x, root);
}

void BinarySearchTree::insert(const int & x, BinaryNode *&t)
{
    if(!t)
    {
        t = new BinaryNode(x,NULL,NULL);
        return;
    }
    if(x == t->data)
    {
        return; //元素已经存在
    }
    if(x < t->data)
    {
        insert(x, t->left);
    }
    else
    {
        insert(x, t->right);
    }
}


void BinarySearchTree::insert2(const int & x)
{
    BinaryNode *p;
    if(!root) //如果查找树的根为空，直接建立一个结点并作为根结点
    {
        root = new BinaryNode(x);
        return;
    }
    p = root;
    while(p)
    {
        if(x==p->data)
        {
            return; //已经在二叉树中
        }
        if(x<p->data)
        {
            if(!p->left) //左子为空，插入位置即此地
            {
                p->left = new BinaryNode(x);
                return;
            }
            p = p->left;
        }
        else
        {
            if(!p->right) //右子为空，插入位置即此地
            {
                p->right = new BinaryNode(x);
                return;
            }
            p = p->right;
        }
    }
}

int main()
{
    int nodenum;
    scanf("%d",&nodenum);
    BinarySearchTree tree;
    for(int i=0;i<nodenum;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        tree.insert(tmp);
    }
    int data1,data2;
    scanf("%d",&data1);
    scanf("%d",&data2);
    tree.find(data1,ans1);
    tree.find(data2,ans2);
    int tmp1,tmp2;
    int sameans;
    do
    {
        tmp1=ans1.front();
        ans1.pop();
        tmp2=ans2.front();
        ans2.pop();
        if(tmp1==tmp2)
        {
            sameans=tmp1;
        }
    }while(tmp1==tmp2);
    printf("%d",sameans);
    return 0;
}

