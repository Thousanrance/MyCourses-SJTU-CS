#include <iostream>
#include "BTree.h"

using namespace std;

int main()
{
    BTree<char> tree;
    tree.createTree('@');
    cout << "高度为：" << tree.height() << endl;
    cout << "规模为：" << tree.size() << endl;
    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();
    return 0;
}
