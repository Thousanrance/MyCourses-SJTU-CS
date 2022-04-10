#include <iostream>
#include "../ºØ∫œ¿‡/SET.h"
#include "BinarySearchTree.h"

using namespace std;
int main ()
{
    SET<int, char *> a[] = {{10, "aaa"}, {8,"bbb"}, {21,"ccc"},{87,"ddd"},
                            {56,"eee"}, {4,"fff"}, {11,"ggg"}, {3,"hhh"},
                            {22,"iiiii"}, {7,"jjj"}};
    BinarySearchTree<int, char*> tree;
    SET<int, char*> x;
    SET<int, char*> *p;
    for(int i = 0; i < 10; ++i) tree.insert(a[i]);
    if(p)
    {
        cout << "find 56 is " << p->key << " " << p->other << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    tree.remove(56);
    p = tree.find(56);
    if(p)
    {
        cout << "find 56 is " << p->key << " " << p->other << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    p = tree.find(21);
    if(p)
    {
        cout << "find 21 is " << p->key << " " << p->other << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    tree.remove(21);
    p = tree.find(21);
    if(p)
    {
        cout << "find 21 is " << p->key << " " << p->other << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    x.key = 30;
    x.other = "xyz";
    tree.insert(x);
    p = tree.find(30);
    if(p)
    {
        cout << "find 30 is " << p->key << " " << p->other << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    return 0;
}
