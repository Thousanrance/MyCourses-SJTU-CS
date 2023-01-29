/*
��Ŀ����
�����������ָ���Ǹ���һ�ö���������T�������ڵ�(u,v)���ҵ�һ��������ڵ���Զ�Ľڵ�x����xͬʱ��u��v�����ȣ���ôx�������ǵ������������

               6
            /     \
          4         7
        /   \         \
      2      5         9
�������ͼ�Ķ�����������2��7���������������6��4��5���������������4��һ����������Լ������ȣ�

�����ʽ
ÿ������������3�й��� ��һ�������еĳ���n��n<=10000 �ڶ��������е�����n������Ԫ�� �������������ڵ�(u,v)

�����ʽ
���ڸ��������У��Ȱ�������˳�򹹽�����������T ��Ѱ�Ҹ����ڵ�������������x �������ǽڵ�x��ֵ

��������
6
6 4 2 7 5 9
2 7

�������
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
    int *find2(const int &x)const; //�ǵݹ�ʵ��
    void insert2(const int &x); //�ǵݹ�ʵ��
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
        return; //Ԫ���Ѿ�����
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
    if(!root) //����������ĸ�Ϊ�գ�ֱ�ӽ���һ����㲢��Ϊ�����
    {
        root = new BinaryNode(x);
        return;
    }
    p = root;
    while(p)
    {
        if(x==p->data)
        {
            return; //�Ѿ��ڶ�������
        }
        if(x<p->data)
        {
            if(!p->left) //����Ϊ�գ�����λ�ü��˵�
            {
                p->left = new BinaryNode(x);
                return;
            }
            p = p->left;
        }
        else
        {
            if(!p->right) //����Ϊ�գ�����λ�ü��˵�
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

