#include <iostream>
#include <cstring>

using namespace std;

class BinarySearchTree
{
private:
    struct BinaryNode
    {
        int data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const int & thedata,BinaryNode *lt=NULL,BinaryNode *rt=NULL)
                    :data(thedata),left(lt),right(rt){}
    };
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
    int InOrder(int i);
    int find(const int &x)const;
    void insert(const int &x);
    void remove(const int &x);
    void remove2(const int a,const int b);
private:
    int InOrder(BinaryNode *t,int i,int n);
    void insert(const int & x, BinaryNode * &t);
    void remove(const int & x, BinaryNode * &t);
    int find(const int &x, BinaryNode *t)const;
    void remove2(BinaryNode *t,const int a,const int b);
};

int BinarySearchTree::InOrder(int i)
{
    int calc=1;
    return InOrder(root,i,calc);
}

int BinarySearchTree::InOrder(BinaryNode *t,int i,int n) //后序遍历以t为根二叉树递归算法的实现。
{
	if(!t)
    {
    	return -1;
    }
    InOrder(t->left,i,n);
    if(n==i)
    {
        return t->data;
    }
    else
    {
        n++;
    }
    InOrder(t->right,i,n);
}

int BinarySearchTree::find(const int &x)const
{
    return find(x,root);
}

int BinarySearchTree::find(const int &x, BinaryNode *t)const
{
    if (t == NULL)
    {
        return 0;
    }
    if(t->data == x)
    {
        return 1;
    }
    if(x < t->data)
    {
        return find(x, t->left);
    }
    else
    {
        return find(x, t->right);
    }
}

void BinarySearchTree::insert(const int & x)
{
    insert(x, root);
}

void BinarySearchTree::insert(const int & x, BinaryNode *&t)
{
    if(!t)
    {
        t = new BinaryNode(x, NULL, NULL);
        return;
    }
    if(x <= t->data)
    {
        insert(x, t->left);
    }
    else
    {
        insert(x, t->right);
    }
}

void BinarySearchTree::remove(const int & x)
{
    remove(x, root);
}

void BinarySearchTree::remove(const int & x, BinaryNode * & t)
{
    if(t == NULL)
    {
        return;
    }
    if(x < t->data)
    {
        remove(x, t->left);
    }
    else if(t->data < x)
    {
        remove(x, t->right);
    }
    else if(t->left && t->right) //x = t->data
    {
        //有两个孩子
        BinaryNode *tmp = t->right;
        while(tmp->left)
        {
            tmp = tmp->left;
        }
        t->data = tmp->data;
        remove(t->data,t->right);
    }
    else
    {
        //被删结点是叶结点或只有一个孩子
        BinaryNode *oldNode = t;
        t = (t->left)?t->left:t->right;
        delete oldNode;
    }
}

void BinarySearchTree::remove2(int a,int b)
{
    remove2(root,a,b);
}

void BinarySearchTree::remove2(BinaryNode *t,int a,int b) //后序遍历以t为根二叉树递归算法的实现。
{
	if(!t)
    {
    	return;
    }
    remove2(t->left,a,b);
    if(t->data>a&&t->data<b)
    {
        remove(t->data);
    }
    remove2(t->right,a,b);
}

int main()
{
    int times;
    scanf("%d",&times);
    BinarySearchTree tree;
    for(int x=0;x<times;x++)
    {
        cin.ignore();
        char* op=new char [16];
        cin.getline(op,16,' ');
        //cout<<op<<endl;
        if(strcmp(op,"insert")==0)
        {
            //cout<<"check"<<endl;
            int tmp1;
            scanf("%d",&tmp1);
            tree.insert(tmp1);
        }
        if(strcmp(op,"find")==0)
        {
            //cout<<"check3"<<endl;
            int flag;
            int tmp2;
            scanf("%d",&tmp2);
            flag=tree.find(tmp2);
            if(flag==1)
            {
                printf("Y\n");
            }
            else
            {
                //cout<<"check1"<<endl;
                printf("N\n");
            }
        }
        if(strcmp(op,"delete")==0)
        {
            int tmp3;
            scanf("%d",&tmp3);
            tree.remove(tmp3);
        }
        if(strcmp(op,"find_ith")==0)
        {
            int i;
            scanf("%d",&i);
            int tmp4;
            tmp4=tree.InOrder(i);
            if(tmp4==-1)
            {
                //cout<<"check2"<<endl;
                printf("N\n");
            }
            else
            {
                printf("%d\n",tmp4);
            }
        }
        if(strcmp(op,"delete_interval")==0)
        {
            int a,b;
            scanf("%d",&a);
            scanf("%d",&b);
            tree.remove2(a,b);
        }
    }
    return 0;
}
