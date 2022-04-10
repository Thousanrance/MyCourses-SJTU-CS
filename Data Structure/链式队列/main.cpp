#include <iostream>
#include "linkQueue.h"

using namespace std;

int main()
{
    linkQueue <int> s;
    for(int i=0; i<15; ++i)
    {
        s.enQueue(i);
    }
    while(!s.isEmpty())
    {
        cout<<s.deQueue()<<' ';
    }
    cout << endl;
    return 0;
}
