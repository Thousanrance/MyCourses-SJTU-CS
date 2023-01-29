#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include "../������/SET.h"

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
    SET<KEY, OTHER> *find2(const KEY &x)const; //�ǵݹ�ʵ��
    void insert2(const SET<KEY, OTHER> &x); //�ǵݹ�ʵ��
    void remove2(const KEY &x); //�ǵݹ�ʵ��
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
        return; //Ԫ���Ѿ�����
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
        //����������
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
        //��ɾ�����Ҷ����ֻ��һ������
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
    int flag; //0Ϊ�����˳����������1Ϊ�����˳����������
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
        //ɾ����ʼ
        if(!p->left && !p->right) //Ҷ�ӽ��
        {
            delete p;
            if(!parent)
            {
                root = NULL;
                return;
            } //��ɾ�����Ϊ�����Ҹ�ΪҶ��
            if(flag == 0)//��ɾ�����Ϊ����������
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }

            return;
        }
        if(!p->left || !p->right) //��ɾ��������һ�����ӽ��
        {
            BinaryNode *tmp; tmp = p;
            if(!parent) //��ɾ�����Ϊ�����Ҹ���һ������
            {
                root = (p->left)?p->left:p->right;
            }
            else if (flag == 0)//��ɾ�����Ϊ����������
            {
                parent->left = (p->left)?p->left:p->right;
            }
            else //��ɾ�����Ϊ����������
            {
                parent->right = (p->left)?p->left:p->right;
            }
            delete tmp;

            return;
        }
        //��ɾ������ж������ӽ��
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
        //������ɾ�����������Ԫ��ֵ
        SET<KEY, OTHER> e;
        e = p->data;
        p->data = substitute->data;
        substitute->data = e;
        p = substitute; //ɾ�����ָ���Ϊ�����������ѭ��
    }
}

#endif // BINARYSEARCHTREE_H_INCLUDED
