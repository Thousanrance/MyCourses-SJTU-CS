/*
��Ŀ����
����1��n��һ�����й���һ�����У��������������Ͻ��п��������㷨��Ҫ�ıȽϴ�����
����Ŀ�������������Ҫ��
ÿ��ѡ��������ĵ�һ��Ԫ����Ϊpivot
�ڸ���pivot���������������Ԫ�ص�˳����ԭ�����е�˳��һ�¡���������ͬ��
���磺����Ϊ 5, 3, 6, 8, 2, 4,1 , 9, 10, 75,3,6,8,2,4,1,9,10,7��ѡ��55Ϊpivot�����ֵõ�����������3, 2, 4,13,2,4,1����������6,8,9,10,76,8,9,10,7��

�����ʽ
��һ��һ������n,
�ڶ���n����������1��n��һ������

�����ʽ
һ����������ʾ��������ıȽϴ���

��������
6
3 2 4 1 6 5

�������
9
���ͣ�������3Ϊpivot������5�αȽϵõ�2,1��4,6,5��������������ͬ���ķ���������Ҫ1�κ�3�Σ�����Ϊ9�Ρ�

���ݷ�Χ
����40%�����ݣ�n��100��
����40%�����ݣ�n��10000��
����20%�����ݣ�n��1000000. (ֱ��ģ�ⷽ�������޷�ͨ��)
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
