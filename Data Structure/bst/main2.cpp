/*
  题目1158 1160
 * 实现二叉查找树(not avlTree!!!)，支持插入，查找，删除，查找第 i 小的元素，删除大于 a 且小于 b 的所有元素, 查找最近共同祖先

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

 */


#include <iostream>
using namespace std;


//集合
template <class KEY, class OTHER>
struct SET {
    KEY key;  //如学号
    OTHER other; //包含姓名、性别、出生日期等的结构体变量
    SET() = default;
    SET(KEY k, OTHER o) {key = k; other = o;}
//    bool operator>(const SET &o) const {return key > o.key;}
//    bool operator==(const SET &o) const {return key == o.key;}
//    bool operator<(const SET &o) const {return key < o.key;}
};


template <class KEY, class OTHER>
class dynamicSearchTree {
public:
    virtual SET<KEY, OTHER> *find(const KEY &x) const = 0;
    virtual void insert(const SET<KEY, OTHER> &x) = 0;
    virtual void remove(const KEY &x) = 0;
    virtual ~dynamicSearchTree() = default;
};



template <class KEY, class OTHER>
class binarySearchTree: public dynamicSearchTree<KEY, OTHER>
{
private:
    struct node
    {
        SET<KEY, OTHER> data;
        node *left;
        node *right;

        explicit node( const SET<KEY, OTHER> &x,node *lt=nullptr,  node *rt=nullptr ): data(x), left(lt), right(rt) {}
    };

    node *root;
    void make_empty( node *t );
    bool find (node *t, const KEY &x) const;
    void delete_interval(node *&t, const KEY & x, const KEY & y);
    int size(node *t) const;
    [[nodiscard]] bool find_ith(node *t, int x) const;
    void remove(node *&t, const KEY &x);

public:
    binarySearchTree(){root = nullptr;}
    ~binarySearchTree() override {make_empty(root); root = nullptr;}
    SET<KEY, OTHER> *find(const KEY &x) const override ;
    void insert(const SET<KEY, OTHER> &x) override;
    void remove( const KEY & x) override;
    [[nodiscard]] KEY findClosestCommonAncestor(const KEY & x, const KEY & y) const;
    void delete_interval(const KEY &x, const KEY &y);
    [[nodiscard]] bool find_ith(int x) const;
};


template<class KEY, class OTHER>
void binarySearchTree<KEY, OTHER>::make_empty(binarySearchTree::node *t) {
    if(!t) return;
    make_empty(t->left);
    make_empty(t->right);
    delete t;
}

template <class KEY, class OTHER>
SET<KEY, OTHER>* binarySearchTree<KEY, OTHER>::find(const KEY &x) const {  //非递归实现
    if (!root) return nullptr;
    node *p = root;
    while (p) {
        if (x == p->data.key) return &p->data;
        if (x > p->data.key) p = p->right;
        else p = p->left;
    }
    return nullptr;
}

template <class KEY, class OTHER>
void binarySearchTree<KEY,OTHER>::insert(const SET<KEY, OTHER> &x) {  //非递归实现
    if (!root) { root = new node(x); return;}
    node *p = root;
    while(p){
        if (p->data.key == x.key) { p->left = new node(x, p->left); return;}
        if (x.key < p->data.key) {
            if (!p->left) { p->left = new node(x); return; }
            p = p->left;
        }
        else {
            if (!p->right) { p->right = new node(x); return; }
            p = p->right;
        }
    }
}

template<class KEY, class OTHER>
void binarySearchTree<KEY, OTHER>::remove(const KEY &x) {   //非递归实现
    if (!root) return;
    node *p = root, *parent = nullptr;
    int flag;    //0为父结点顺左子下来，1为父结点顺右子下来。
    while(p){
        if (x < p->data.key){ parent = p; flag = 0; p = p->left; continue; }
        if (x > p->data.key){ parent = p; flag = 1; p = p->right; continue;}

        // 删除开始
        if (!p->left or !p->right){  //单子结点 or 叶子结点
            node *tmp = p;
            if (!parent) { root = (p->left)? p->left : p->right; return;}
            if (flag) parent->right = (p->left)? p->left : p->right;
            else parent->left = (p->left)? p->left : p->right;
            delete tmp;
            return;
        }
        else {  //双子结点
            node *q = p->right; parent = p; flag = 1;
            while(q->left) { parent = q; q = q->left; flag = 0; }

            SET<KEY,OTHER> s = p->data;  //交换待删除结点和替身的元素值
            p->data = q->data;
            q->data = s;

            p = q;   //删除结点指针变为替身继续返回循环
        }
    }
}


template<class KEY, class OTHER>
bool binarySearchTree<KEY, OTHER>::find(binarySearchTree::node *t, const KEY &x) const {
    if (!t) return false;
    if (t->data.key == x) return true;
    return find(t->left, x) or find(t->right, x);
}

template<class KEY, class OTHER>
KEY binarySearchTree<KEY, OTHER>::findClosestCommonAncestor(const KEY & x, const KEY & y) const {
    node *p = root, *q;
    while (find(p, x) and find(p, y))
    {
        q = p->left;
        if (find(q, x) and find(q,y)) { p = q; continue;}
        q = p->right;
        if (find(q, x) and find(q,y)) { p = q; continue;}
        break;
    }
    return p->data.key;
}

template<class KEY, class OTHER>
void binarySearchTree<KEY, OTHER>::delete_interval(binarySearchTree::node *&t, const KEY &x, const KEY &y) {
    if (!t) return;
    while (t and t->data.key > x and t->data.key < y) remove(t, t->data.key);
    if (t){
        if (t->data.key <= x) { delete_interval(t->right, x, y); return; }
        if (t->data.key >= y) { delete_interval(t->left, x, y); return; }
    }
}

template<class KEY, class OTHER>
void binarySearchTree<KEY, OTHER>::delete_interval(const KEY &x, const KEY &y) {
    delete_interval(root, x, y);
}

template<class KEY, class OTHER>
int binarySearchTree<KEY, OTHER>::size(binarySearchTree::node *t) const {
    if (!t) return 0;
    return size(t->left) + size(t->right) + 1;
}

template<class KEY, class OTHER>
bool binarySearchTree<KEY, OTHER>::find_ith(binarySearchTree::node *t, int x) const {
    if (x <= 0 or size(t) < x) return false;
    int s = size(t->left) + 1;
    if (x < s) return find_ith(t->left, x);
    if (s == x) { cout << t->data.key << endl; return true; }
    return find_ith(t->right, x - s);
}

template<class KEY, class OTHER>
bool binarySearchTree<KEY, OTHER>::find_ith(int x) const {
    if (find_ith(root, x)) return true;
    return false;
}

template<class KEY, class OTHER>
void binarySearchTree<KEY, OTHER>::remove(binarySearchTree::node *&t, const KEY &x) {
    if (!t) return;
    if (t->data.key > x) { remove(t->left, x); return; }
    if (t->data.key < x) { remove(t->right, x); return; }
    if (!t->left or !t->right) { node * tmp = t; t = (t->left)? t->left : t->right; delete tmp; return; }
    node *p = t->right;
    while(p->left) p = p->left;
    t->data = p->data;
    remove(t->right, p->data.key);
}


int main()
{
    int n, x, y;
    cin >> n;
    string s;
    binarySearchTree<int, int> bs;
    while(n--){
        cin >> s;
        if (s == "insert") { cin >> x; bs.insert(SET<int, int>(x,x)); }
        if (s == "find") { cin >> x; if (bs.find(x)) cout << "Y" << endl; else cout << "N" << endl; }
        if (s == "delete") { cin >> x; bs.remove(x); }
        if (s == "find_ith") { cin >> x; if (!bs.find_ith(x)) cout << "N" << endl; }
        if (s == "delete_interval") { cin >> x >> y; bs.delete_interval(x,y); }
    }
}