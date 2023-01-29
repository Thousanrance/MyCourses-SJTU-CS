/*
题目描述
输入1到n的一个排列构成一个序列，输出在这个序列上进行快速排序算法需要的比较次数。
本题的快速排序有以下要求：
每次选择子数组的第一个元素作为pivot
在根据pivot划分完的左子数组元素的顺序与原数组中的顺序一致。右子数组同理。
比如：数组为 5, 3, 6, 8, 2, 4,1 , 9, 10, 75,3,6,8,2,4,1,9,10,7，选择55为pivot，划分得到的左子数组3, 2, 4,13,2,4,1，右子数组6,8,9,10,76,8,9,10,7。

输入格式
第一行一个整数n,
第二行n个整数，是1到n的一个排列

输出格式
一个整数，表示快速排序的比较次数

样例输入
6
3 2 4 1 6 5

样例输出
9
解释：首先以3为pivot，进行5次比较得到2,1和4,6,5这两个子数组用同样的方法依次需要1次和3次，最终为9次。

数据范围
对于40%的数据，n≤100，
对于40%的数据，n≤10000，
对于20%的数据，n≤1000000. (直接模拟方法可能无法通过)
*/



#include <iostream>

using namespace std;

class AvlTree
{
    struct AvlNode
    {
        int data;
        AvlNode* left;
        AvlNode* right;
        int height;

        AvlNode(const int& element, AvlNode* lt, AvlNode* rt, int h = 1)
            :data(element), left(lt), right(rt), height(h) {}
    };

    AvlNode* root;

public:
    AvlTree(long n)
    {
        root = nullptr;
        cmp = 0;
        num = n;
    }
    ~AvlTree()
    {
        makeEmpty(root);
    }
    void insert(const int& x)
    {
        insert(x, root);
    }
    void scan(const long& x)
    {
        AvlNode* t = root;
        long long min = 0, max = num + 1;
        while(t)
        {
            if(t->data < x)
            {
                min = t->data;
                t = t->right;
            }
            else
            {
                max = t->data;
                t = t->left;
            }
        }
        cmp += max - min - 2;
    }
    long cmp;
    long num;
private:
    int height(AvlNode* t)const
    {
        return t == nullptr ? 0 : t->height;
    }
    int max(int a, int b)
    {
        return(a > b) ? a : b;
    }

    void insert(const int& x, AvlNode*& t)
    {
        if(!t)
        {
            t = new AvlNode(x, nullptr, nullptr);
        }
        else if(x < t->data)
        {
            insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                {
                    LL(t);
                }
                else
                {
                    LR(t);
                }
            }
        }
        else if (t->data < x)
        {
            insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(t->right->data < x)
                {
                    RR(t);
                }
                else
                {
                    RL(t);
                }
            }
        }
        t->height = max(height(t->left), height(t->right)) + 1;
    }
    void makeEmpty(AvlNode*& t)
    {
        if(!t)
        {
            return;
        }
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    void LL(AvlNode*& t)
    {
        AvlNode* t1 = t->left;
        t->left = t1->right;
        t1->right = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        t1->height = max(height(t1->left), height(t)) + 1;
        t = t1;
    }

    void RR(AvlNode*& t)
    {
        AvlNode* t1 = t->right;
        t->right = t1->left;
        t1->left = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        t1->height = max(height(t1->right), height(t)) + 1;
        t = t1;
    }

    void LR(AvlNode*& t)
    {
        RR(t->left);
        LL(t);
    }

    void RL(AvlNode*& t)
    {
        LL(t->right);
        RR(t);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n;
    cin >> n;
    AvlTree avl(n);
    long op;
    while (n--)
    {
        cin >> op;
        avl.scan(op);
        avl.insert(op);
    }
    cout << avl.cmp;
    return 0;
}
