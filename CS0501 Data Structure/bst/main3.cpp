/*
��Ŀ����
ʵ�ֶ����������֧�ֲ��룬���ң�ɾ�������ҵ� i С��Ԫ�أ�ɾ������ a ��С�� b ������Ԫ��

�����ʽ
�� 1 ��: һ����, n, ��ʾ�ܲ���������
������ n ��: ÿ������һ������, ��ʾ����������, ��һ�н������ĸ�ʽÿ�ֲ�����ͬ:

- "insert": ����, ������һ������, x, ��ʾ�������Ԫ��
- "find": ����, ������һ������, x, ��ʾ�����ҵ�Ԫ��
- "delete": ɾ��, ������һ������, x, ��ʾ��ɾ����Ԫ�أ����������ظ�ɾ������һ����
- "find_ith": ���ҵ� i С��Ԫ��, ������һ������, i
- "delete_interval": ɾ������ a ��С�� b ������Ԫ��, ��������������, a, b

�����ʽ
���ж��� "find" ��������� Y/N����ʾ�Ƿ���ҵ�ѯ�ʵ�Ԫ�ء�
���� "find_ith" ����������� i С��Ԫ��ֵ������������� N��
ע��: �������� 1, 2, 2, 3, ������Ϊ�� 1 С��Ԫ���� 1, �� 2 С��Ԫ���� 2, �� 3 С��Ԫ�ػ��� 2, �� 4 С��Ԫ���� 3

��������
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

�������
N
291
7225
Y
291

���ݷ�Χ
��֤����ʱ������Ԫ�ز����� 5000 ��,������С��300000
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
