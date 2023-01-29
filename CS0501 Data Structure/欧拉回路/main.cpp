#include <iostream>

using namespace std;

struct EulerNode
{
    int NodeNum;
    EulerNode *next;
    EulerNode(int ver)
    {
        NodeNum = ver;
        next =NULL;
    }
};

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::verNode *adjListGraph<TypeOfVer, TypeOfEdge>::clone()const
{
    verNode *tmp = new verNode[Vers];
    edgeNode *p;
    for(int i = 0; i < Vers; ++i)
    {
        tmp[i].ver = verList[i].ver;
        p = verList[i].head;
        while(p != NULL)
        {
            //��ԭʼ�߱�ȣ�˳��������
            tmp[i].head = new edgeNode(p->end, p->weight, tmp[i].head);
            p = p->next;
        }
    }
    return tmp;
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::EulerNode *adjListGraph //���ص�������β
<TypeOfVer, TypeOfEdge>::EulerCircuit(int start, EulerNode *&end)
{
    EulerNode *beg; int nextNode;
    beg = end = new EulerNode(start); //��һ�����������д���һ�����
    while(verList[start].head != NULL)
    {
        //ֱ����ǰ�߲������޻���
        nextNode = verList[start].head->end; //start���ڽӶ����±�
        remove( start, nextNode);
        remove(nextNode, start); //˫��ɾ��
        start = nextNode;
        end->next = new EulerNode(start);
        end = end->next;
    }
    return beg;
    //���˵�һ��������������м��㶼�н��г����������һ���㣬�����޳����������beg = end
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::EulerCircuit(TypeOfVer start)
{
    EulerNode *beg, *end, *p, *q, *tb, *te;
    int numOfDegree;
    edgeNode *r;
    verNode *tmp;
    //���ÿ������Ķȣ��ж��Ƿ����ŷ����·
    for(int i=0; i<Vers; ++i)
    {
        numOfDegree = 0;
        r = verList[i].head;
        while(r != 0)
        {
            ++numOfDegree;
            r= r->next;
        }
        if(numOfDegree ==0 || numOfDegree % 2) //��Ϊ0������������ŷ����·
        {
            cout << "������ŷ����·" << endl;
            return;
        }
    }
    //Ѱ����ʼ���ı��
    i = find(start);
    //����һ���ڽӱ�Ŀ���
    tmp = clone(); 113
    //Ѱ�Ҵ�i������·����·���������յ��ַ�ֱ���beg��end
    beg = EulerCircuit(i, end); //��һ�λ�·���ù��ı��Ѿ�ɾ��
    while(true)
    {
        p = beg;
        while(p->next != NULL) //��ǰ������·��������ߵĶ���
        if(verList[p->next->NodeNum].head != NULL)
        {
            break;
        }
        else
        {
            p = p->next;
        }
        if(p->next == NULL)
        {
            break; //ȫ���߶����ʹ�����ʧ��
        }
        q = p->next; //��һ����ʼ����
        tb = EulerCircuit(q->NodeNum, te); //��һ��ŷ��·��
        te->next =q->next;
        p->next = tb; //q��ȡ��
        delete q;
    }
    //�ָ�ԭͼ
    delete [] verList;
    verList = tmp;
    //��ʾ�õ���ŷ����·
    cout << "ŷ����·�ǣ�" << endl;
    while(beg !=NULL)
    {
        //������ͷŵ�����
        cout << verList[beg->NodeNum].ver << '\t';
        p = beg;
        beg = beg->next;
        delete p;
    }
    cout << endl;
}

