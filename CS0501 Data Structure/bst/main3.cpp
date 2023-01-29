/*
题目描述
实现二叉查找树，支持插入，查找，删除，查找第 i 小的元素，删除大于 a 且小于 b 的所有元素

输入格式
第 1 行: 一个数, n, 表示总操作个数。
接下来 n 行: 每行首先一个单词, 表示操作的名称, 这一行接下来的格式每种操作不同:

- "insert": 插入, 接下来一个整数, x, 表示被插入的元素
- "find": 查找, 接下来一个整数, x, 表示被查找的元素
- "delete": 删除, 接下来一个整数, x, 表示被删除的元素（若树中有重复删除任意一个）
- "find_ith": 查找第 i 小的元素, 接下来一个整数, i
- "delete_interval": 删除大于 a 且小于 b 的所有元素, 接下来两个整数, a, b

输出格式
其中对于 "find" 操作，输出 Y/N，表示是否查找到询问的元素。
对于 "find_ith" 操作，输出第 i 小的元素值，若不存在输出 N。
注意: 对于数列 1, 2, 2, 3, 我们认为第 1 小的元素是 1, 第 2 小的元素是 2, 第 3 小的元素还是 2, 第 4 小的元素是 3

样例输入
20
insert 1863
insert 1513
delete 1863
find 1863
insert 291
delete_interval 1697 2739
insert -4249
insert -4105
find_ith 3
insert 8169
delete 1513
insert 7225
find_ith 4
delete -4105
delete 8169
insert 7543
find 7543
delete 7543
delete -4249
find_ith 1

样例输出
N
291
7225
Y
291

数据范围
保证任意时刻树中元素不超过 5000 个,操作数小于300000
 */


#include <iostream>
using namespace std;

class binarySearchTree
{
private:
    struct node
    {
        int data;
        node *left;
        node *right;
        node(const int &x,node *lt=nullptr,  node *rt=nullptr ): data(x), left(lt), right(rt) {}
    };
    node *root;
    void make_empty(node *t);
    void delete_interval(node *&t, const int & x, const int & y);
    int size(node *t) const;
    bool find_ith(node *t, int x) const;
    void remove(node *&t, const int &x);

public:
    binarySearchTree()
    {
        root = nullptr;
    }
    ~binarySearchTree()
    {
        make_empty(root);
        root = nullptr;
    }
    bool find(const int &x)const;
    void insert(const int &x);
    void remove(const int & x);
    void delete_interval(const int &x, const int &y);
    bool find_ith(int x) const;
};

void binarySearchTree::make_empty(binarySearchTree::node *t)
{
    if(!t)
    {
        return;
    }
    make_empty(t->left);
    make_empty(t->right);
    delete t;
}

void binarySearchTree::insert(const int &x)
{
    if(!root)
    {
        root = new node(x);
        return;
    }
    node *p = root;
    while(p)
    {
        if(p->data== x)
        {
            p->left = new node(x, p->left);
            return;
        }
        if(x < p->data)
        {
            if(!p->left)
            {
                p->left = new node(x);
                return;
            }
            p = p->left;
        }
        else
        {
            if(!p->right)
            {
                p->right = new node(x);
                return;
            }
            p = p->right;
        }
    }
}

bool binarySearchTree::find(const int &x)const
{
    if (!root)
    {
        return false;
    }
    node *p = root;
    while(p)
    {
        if(x == p->data)
        {
            return true;
        }
        if(x > p->data)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    return false;
}


void binarySearchTree::delete_interval(binarySearchTree::node *&t, const int &x, const int &y)
{
    if(!t)
    {
        return;
    }
    while(t && t->data > x && t->data < y)
    {
        remove(t, t->data);
    }
    if(t)
    {
        if(t->data <= x)
        {
            delete_interval(t->right, x, y);
            return;
        }
        if(t->data >= y)
        {
            delete_interval(t->left, x, y);
            return;
        }
    }
}


void binarySearchTree::delete_interval(const int &x, const int &y)
{
    delete_interval(root, x, y);
}


int binarySearchTree::size(binarySearchTree::node *t)const
{
    if(!t)
    {
        return 0;
    }
    return size(t->left) + size(t->right) + 1;
}


bool binarySearchTree::find_ith(binarySearchTree::node *t, int x)const
{
    if(x <= 0 || size(t) < x)
    {
        return false;
    }
    int s = size(t->left) + 1;
    if(x < s)
    {
        return find_ith(t->left, x);
    }
    if(s == x)
    {
        cout << t->data << endl;
        return true;
    }
    return find_ith(t->right, x - s);
}


bool binarySearchTree::find_ith(int x)const
{
    if(find_ith(root, x))
    {
        return true;
    }
    return false;
}

void binarySearchTree::remove(const int &x)
{
    if(!root)
    {
        return;
    }
    node *p = root, *parent = nullptr;
    int flag;
    while(p)
    {
        if(x < p->data)
        {
            parent = p;
            flag = 0;
            p = p->left;
            continue;
        }
        if(x > p->data)
        {
            parent = p;
            flag = 1;
            p = p->right;
            continue;
        }
        if(!p->left or !p->right)
        {
            node *tmp = p;
            if(!parent)
            {
                root = (p->left)? p->left : p->right;
                return;
            }
            if(flag)
            {
                parent->right = (p->left)? p->left : p->right;
            }
            else
            {
                parent->left = (p->left)? p->left : p->right;
            }
            delete tmp;
            return;
        }
        else
        {
            node *q = p->right;
            parent = p;
            flag = 1;
            while(q->left)
            {
                parent = q;
                q = q->left;
                flag = 0;
            }
            int s = p->data;
            p->data = q->data;
            q->data = s;
            p = q;
        }
    }
}

void binarySearchTree::remove(binarySearchTree::node *&t, const int &x)
{
    if(!t)
    {
        return;
    }
    if(t->data > x)
    {
        remove(t->left, x);
        return;
    }
    if(t->data < x)
    {
        remove(t->right, x);
        return;
    }
    if(!t->left || !t->right)
    {
        node * tmp = t;
        t = (t->left)? t->left : t->right;
        delete tmp;
        return;
    }
    node *p = t->right;
    while(p->left)
    {
        p = p->left;
    }
    t->data = p->data;
    remove(t->right, p->data);
}


int main()
{
    int n, x, y;
    cin >> n;
    string s;
    binarySearchTree tree;
    while(n--)
    {
        cin >> s;
        if(s == "insert")
        {
            cin >> x;
            tree.insert(x);
        }
        if(s == "find")
        {
            cin >> x;
            if(tree.find(x))
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
        }
        if(s == "delete")
        {
            cin >> x;
            tree.remove(x);
        }
        if(s == "find_ith")
        {
            cin >> x;
            if(!tree.find_ith(x))
            {
                cout << "N" << endl;
            }
        }
        if(s == "delete_interval")
        {
            cin >> x >> y;
            tree.delete_interval(x,y);
        }
    }
    return 0;
}
