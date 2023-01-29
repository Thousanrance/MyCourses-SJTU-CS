#include <iostream>

using namespace std;

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::topSort( ) const
{
    linkQueue<int> q;
    edgeNode *p;
    int current, *inDegree = new int[Vers];
    //����ÿ����������
    for(int i = 0; i < Vers; ++i)
    {
        inDegree[i] = 0;
    }
    for(i = 0; i < Vers; ++i)
    {
        for(p = verList[i].head; p != NULL; p = p->next)
        {
            ++inDegree[p->end];
        }
    }
    for(i = 0; i < Vers; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.enQueue(i);
        }
    }
    cout << "��������Ϊ��" << endl;
    while(!q.isEmpty())
    {
        current = q.deQueue( );
        cout << verList[current].ver << '\t';
        //�����ڽӵ��Ķ�����ȼ�һ
        for(p = verList[current].head; p != NULL; p = p->next)
        {
            if(--inDegree[p->end] == 0)
            {
                q.enQueue(p->end);
            }
        }
        cout << endl;
    }
}
