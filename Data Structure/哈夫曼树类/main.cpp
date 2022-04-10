#include <iostream>
#include "hfTree.h"

using namespace std;

int main()
{
    char ch[] = {"aeistdn"};
    int w[] = {10,15,12,3,4,13,1};
    hfTree<char> tree(ch, w, 7);
    hfTree<char>::hfCode result[7];
    tree.getCode(result);
    for (int i=0; i<7; ++i)
    {
        cout << result[i].data << ' ' << result[i].code << endl;
    }
    return 0;
}
