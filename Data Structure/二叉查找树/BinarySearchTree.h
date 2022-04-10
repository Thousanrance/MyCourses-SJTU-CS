#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include "../集合类/SET.h"

template <class KEY, class OTHER>
class dynamicSearchTable
{
public:
    virtual SET<KEY, OTHER> *find(const KEY &x)const = 0;
    virtual void insert(const SET<KEY, OTHER> &x) = 0;
    virtual void remove(const KEY &x) = 0;
    virtual ~dynamicSearchTable(){};
};

template <class KEY, class OTHER>
class BinarySearchTree: public dynamicSearchTable<KEY, OTHER>
{
private:
    struct BinaryNode
    {
        SET<KEY, OTHER> data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const SET<KEY,OTHER> & thedata,BinaryNode *lt=NULL,BinaryNode *rt=NULL)
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
    SET<KEY, OTHER> *find(const KEY &x)const;
    void insert(const SET<KEY, OTHER> &x);
    void remove(const KEY &x);
    SET<KEY, OTHER> *find2(const KEY &x)const; //非递归实现
    void insert2(const SET<KEY, OTHER> &x); //非递归实现
    void remove2(const KEY &x); //非递归实现
private:
    void insert(const SET<KEY, OTHER> & x, BinaryNode * &t);
    void remove(const KEY & x, BinaryNode * &t);
    SET<KEY, OTHER> *find(const KEY &x, BinaryNode *t)const;
    void makeEmpty(BinaryNode *t);
};

template<class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::makeEmpty(BinaryNode *t)
{
    if(!t)
    {
        return;
    }
    make_empty(t->left);
    make_empty(t->right);
    delete t;
}

template <class KEY, class OTHER>
SET<KEY, OTHER> * BinarySearchTree<KEY, OTHER>::find(const KEY &x)const
{
    return find(x,root);
}
template <class KEY, class OTHER>
SET<KEY, OTHER> * BinarySearchTree<KEY, OTHER>::find(const KEY &x, BinaryNode *t)const
{
    if (t == NULL)
    {
        return NULL;
    }
    if(t->data.key == x)
    {
        return &(t->data);
    }
    if(x < t->data.key)
    {
        return find(x, t->left);
    }
    else
    {
        return find(x, t->right);
    }
}

template <class KEY, class OTHER>
SET<KEY, OTHER> * BinarySearchTree<KEY, OTHER>::find2(const KEY &x)const
{
    if(!root)
    {
        return NULL;
    }
    BinaryNode *p; p = root;
    while(p)
    {
        if(x == p->data.key)
        {
            return &(p->data);
        }
        if(x < p->data.key)
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

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER> & x)
{
    insert(x, root);
}
template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER> & x, BinaryNode *&t)
{
    if(!t)
    {
        t = new BinaryNode(x, NULL, NULL);
        return;
    }
    if(x.key == t->data.key)
    {
        return; //元素已经存在
    }
    if(x.key < t->data.key)
    {
        insert(x, t->left);
    }
    else
    {
        insert(x, t->right);
    }
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert2(const SET<KEY, OTHER> & x)
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

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY & x)
{
    remove(x, root);
}
template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY & x, BinaryNode * & t)
{
    if(t == NULL)
    {
        return;
    }
    if(x < t->data.key)
    {
        remove(x, t->left);
    }
    else if(t->data.key < x)
    {
        remove(x, t->right);
    }
    else if(t->left && t->right) //x = t->data.key
    {
        //有两个孩子
        BinaryNode *tmp = t->right;
        while(tmp->left)
        {
            tmp = tmp->left;
        }
        t->data = tmp->data;
        remove(t->data.key,t->right);
    }
    else
    {
        //被删结点是叶结点或只有一个孩子
        BinaryNode *oldNode = t;
        t = (t->left)?t->left:t->right;
        delete oldNode;
    }
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove2(const KEY & x)
{
    if(!root)
    {
        return;
    }
    BinaryNode *p, *parent;
    int flag; //0为父结点顺左子下来，1为父结点顺右子下来。
    p = root; parent = NULL;
    while(p)
    {
        if(x < p->data.key)
        {
            parent = p;
            flag = 0;
            p = p->left;
            continue;
        }
        if(x > p->data.key)
        {
            parent = p;
            flag = 1;
            p = p->right;
            continue;
        }
        //删除开始
        if(!p->left && !p->right) //叶子结点
        {
            delete p;
            if(!parent)
            {
                root = NULL;
                return;
            } //待删除结点为根，且根为叶子
            if(flag == 0)//待删除结点为父结点的左子
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }

            return;
        }
        if(!p->left || !p->right) //待删除结点仅有一个孩子结点
        {
            BinaryNode *tmp; tmp = p;
            if(!parent) //待删除结点为根，且根有一个孩子
            {
                root = (p->left)?p->left:p->right;
            }
            else if (flag == 0)//待删除结点为父结点的左子
            {
                parent->left = (p->left)?p->left:p->right;
            }
            else //待删除结点为父结点的右子
            {
                parent->right = (p->left)?p->left:p->right;
            }
            delete tmp;

            return;
        }
        //待删除结点有二个孩子结点
        BinaryNode *q, *substitute;
        parent = p;
        flag = 0;
        q = p->left;
        while(q->right)
        {
            parent = q;
            flag = 1;
            q = q->right;
        }
        substitute = q;
        //交换待删除结点和替身的元素值
        SET<KEY, OTHER> e;
        e = p->data;
        p->data = substitute->data;
        substitute->data = e;
        p = substitute; //删除结点指针变为替身继续返回循环
    }
}

#endif // BINARYSEARCHTREE_H_INCLUDED
