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
    AvlTree(long n) { root = nullptr; cmp = 0; num = n; }
    ~AvlTree() { makeEmpty(root); }
    void insert(const int& x) { insert(x, root); }
    void remove(const int& x) { remove(x, root); }
    void scan(const long& x)
    {
        AvlNode* t = root;
        long long min = 0, max = num + 1;
        while (t)
        {
            if (t->data < x)
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
    int* find(const int& x) const
    {
        AvlNode* t = root;
        while (t && t->data != x)
            if (t->data > x) t = t->left;
            else t = t->right;
        if (!t) return nullptr;
        else return (int*)t;
    }
    long cmp;
    long num;
private:
    int height(AvlNode* t) const { return t == nullptr ? 0 : t->height; }
    int max(int a, int b) { return(a > b) ? a : b; }

    void insert(const int& x, AvlNode*& t)
    {
        if (!t) t = new AvlNode(x, nullptr, nullptr);
        else if (x < t->data)
        {
            insert(x, t->left);
            if (height(t->left) - height(t->right) == 2)
                if (x < t->left->data) LL(t);
                else LR(t);
        }
        else if (t->data < x)
        {
            insert(x, t->right);
            if (height(t->right) - height(t->left) == 2)
                if (t->right->data < x) RR(t);
                else RL(t);
        }
        t->height = max(height(t->left), height(t->right)) + 1;
    }

    bool remove(const int& x, AvlNode*& t)
    {
        if (!t) return true;
        if (x == t->data)
        {
            if (!t->left || !t->right)
            {
                AvlNode* oldNode = t;
                t = (t->left) ? t->left : t->right;
                delete oldNode;
                return false;
            }
            else
            {
                AvlNode* tmp = t->right;
                while (tmp->left) tmp = tmp->left;
                t->data = tmp->data;
                if (remove(tmp->data, t->right)) return true;
                return adjust(t, 1);
            }
        }
        if (x < t->data)
        {
            if (remove(x, t->left)) return true;
            return adjust(t, 0);
        }
        else
        {
            if (remove(x, t->right)) return true;
            return adjust(t, 1);
        }
    }

    void makeEmpty(AvlNode*& t)
    {
        if (!t) return;
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

    bool adjust(AvlNode*& t, int subTree)
    {
        if (subTree)
        {
            if (height(t->left) - height(t->right) == 1) return true;
            if (height(t->left) == height(t->right)) { --t->height; return false; }
            if (height(t->left->right) > height(t->left->left))
            {
                LR(t);
                return true;
            }
            LL(t);
            if (height(t->left) == height(t->right)) return false;
            else return true;
        }
        else
        {
            if (height(t->right) - height(t->left) == 1) return true;
            if (height(t->left) == height(t->right)) { --t->height; return false; }
            if (height(t->right->left) > height(t->right->right))
            {
                RL(t);
                return true;
            }
            RR(t);
            if (height(t->left) == height(t->right)) return false;
            else return true;
        }
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
