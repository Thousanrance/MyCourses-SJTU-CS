#include <iostream>
#include "BTree.h"

using namespace std;

int main()
{
    BTree<char> tree;
    tree.createTree('@');
    cout << "�߶�Ϊ��" << tree.height() << endl;
    cout << "��ģΪ��" << tree.size() << endl;
    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();
    return 0;
}
