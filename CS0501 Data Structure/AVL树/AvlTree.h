#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

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
class AvlTree: public dynamicSearchTable<KEY, OTHER>
{
    struct AvlNode
    {
        SET<KEY, OTHER> data;
        AvlNode *left,*right;
        int height; //结点的高度
        AvlNode(const SET<KEY, OTHER> &element , AvlNode *lt, AvlNode *rt, int h=1)
                                    :data(element), left( lt ), right( rt ), height(h){}
    };
    AvlNode *root;
public:
    AvlTree()
    {
        root = NULL;
    }
    ~AvlTree()
    {
        makeEmpty(root);
    }
    SET<KEY, OTHER> *find(const KEY & x)const;
    SET<KEY, OTHER> *find2(const KEY & x)const;
    void insert(const SET<KEY, OTHER> & x);
    void remove(const KEY & x);
private:
    void insert(const SET<KEY, OTHER> & x, AvlNode * & t);
    bool remove(const KEY & x, AvlNode * & t);
    void makeEmpty(AvlNode *t);
    int height(AvlNode *t)const
    {
        return t == NULL ? 0 : t->height;
    }
    void LL(AvlNode * & t);
    void LR(AvlNode * & t);
    void RL(AvlNode * & t);
    void RR(AvlNode * & t);
    int max(int a, int b)
    {
        return (a>b)?a:b;
    }
    bool adjust(AvlNode *&t, int subTree);
};

template <class KEY, class OTHER>
SET<KEY, OTHER> *AvlTree<KEY, OTHER>::find(const KEY & x，const AvlNode *&t)const
{
    if(!t)
    {
        return NULL;
    }
    if(x == t->data.key)
    {
        return (SET<KEY, OTHER>*)t;
    }
    if(x>t->data.key)
    {
        return find(x, t->right);
    }
    else
    {
        return find(x, t->left);
    }
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *AvlTree<KEY, OTHER>::find2(const KEY & x)const
{
    AvlNode *t = root;
    while(t!=NULL && t->data.key != x)
    {
        if(t->data.key > x)
        {
        	t = t->left;
        }
        else
        {
            t = t->right;
        }
    }
    if(t==NULL)
    {
        return NULL;
    }
    else
    {
        return (SET<KEY, OTHER>*)t;
    }
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER> & x, AvlNode * & t)
{
    if(t == NULL) //在空树上插入
    {
        t = new AvlNode(x, NULL, NULL);
    }
    else if(x.key < t->data.key)
    {
        //在左子树上插入
        insert(x, t->left);
        if(height(t->left) - height(t->right) == 2) //t失衡
        {
        	if(x.key < t->left->data.key)
            {
                LL(t);
            }
            else
            {
                LR(t);
            }
        }
    }
    else if(x.key > t->data.key)
    {
        //在右子树上插入
        insert( x, t->right );
        if(height( t->left ) - height( t->right ) == - 2) //t失衡
        {
            if(x.key > t->right->data.key)
            {
                RR(t);
            }
            else
            {
                RL(t);
            }
        }
    }
    //重新计算t的高度
    t->height = max(height(t->left), height(t->right)) + 1;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LL(AvlNode * & t)
{
    AvlNode *t1 = t->left; // 未来的树根
    t->left = t1->right;
    t1->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    t1->height = max(height(t1->left), height(t)) + 1;
    t = t1; //新的父子关联
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RR(AvlNode * & t)
{
    AvlNode *t1 = t->right;
    t->right = t1->left;
    t1->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    t1->height = max(height(t1->right), height(t)) + 1;
    t = t1;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LR(AvlNode * & t)
{
    RR(t->left);
    LL(t);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RL(AvlNode * & t)
{
    LL(t->right);
    RR(t);
}

template <class KEY, class OTHER>
bool AvlTree<KEY, OTHER>::remove(const KEY & x, AvlNode * & t)
{
    if(t == NULL)
    {
        return true;
    }
    if(x == t->data.key)
    {
        //删除根结点
        if(t->left == NULL || t->right == NULL)
        {
            AvlNode *oldNode = t;
            t = (t->left != NULL) ? t->left : t->right;
            delete oldNode;
            return false;
    	}
        else
        {
            AvlNode *tmp = t->right;
            while(tmp->left != NULL)
            {
                tmp = tmp->left;
            }
            t->data = tmp->data;
            if (remove(tmp->data.key, t->right))
            {
                return true;
            }
            return adjust(t, 1);
        }
    }
    if(x < t->data.key)
    {
        //在左子树上删除
        if(remove(x, t->left))
        {
            return true;
        }
        return adjust(t, 0);
    }
    else
    {
        //在右子树上删除
        if(remove(x, t->right))
        {
            return true;
        }
        return adjust(t, 1);
    }
}

template <class KEY, class OTHER>
bool AvlTree<KEY, OTHER>::adjust(AvlNode * &t, int subTree)
{
    if(subTree)
    {
        //1、在右子树上删除，使右子树变矮
        if(height(t->left) - height(t->right) == 1) //情况a
        {
            return true;
        }
        if(height(t->right) == height(t->left)) //情况b
        {
            --t->height;
            return false;
        }
        if(height(t->left->right) > height(t->left->left)) // 情况d
        {
            LR(t);
            return false;
        }
        LL(t);
        if(height(t->right) == height(t->left))
        {
            return false;
        }
        else
        {
        	return true;
        }
    }
    else
    {
        //2、在左子树删除
        if(height(t->right) - height(t->left) == 1) //情况a
        {
            return true;
        }
        if(height(t->right) == height(t->left)) //情况b
        {
            --t->height;
            return false;
        }
        if(height(t->right->left) > height(t->right->right)) // 情况d
		{
            RL(t);
            return false;
        }
        RR(t);
        if(height(t->right) == height(t->left))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

#endif // AVLTREE_H_INCLUDED
