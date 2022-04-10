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
            //和原始边表比，顺序逆置了
            tmp[i].head = new edgeNode(p->end, p->weight, tmp[i].head);
            p = p->next;
        }
    }
    return tmp;
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::EulerNode *adjListGraph //返回单链表首尾
<TypeOfVer, TypeOfEdge>::EulerCircuit(int start, EulerNode *&end)
{
    EulerNode *beg; int nextNode;
    beg = end = new EulerNode(start); //第一步，单链表中创建一个结点
    while(verList[start].head != NULL)
    {
        //直到向前走不动，无回溯
        nextNode = verList[start].head->end; //start的邻接顶点下标
        remove( start, nextNode);
        remove(nextNode, start); //双向删除
        start = nextNode;
        end->next = new EulerNode(start);
        end = end->next;
    }
    return beg;
    //除了第一个点仅出，其他中间结点都有进有出，最后进入第一个点，可能无出。所以最后beg = end
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::EulerCircuit(TypeOfVer start)
{
    EulerNode *beg, *end, *p, *q, *tb, *te;
    int numOfDegree;
    edgeNode *r;
    verNode *tmp;
    //检查每个顶点的度，判断是否存在欧拉回路
    for(int i=0; i<Vers; ++i)
    {
        numOfDegree = 0;
        r = verList[i].head;
        while(r != 0)
        {
            ++numOfDegree;
            r= r->next;
        }
        if(numOfDegree ==0 || numOfDegree % 2) //度为0或者奇数，无欧拉回路
        {
            cout << "不存在欧拉回路" << endl;
            return;
        }
    }
    //寻找起始结点的编号
    i = find(start);
    //创建一份邻接表的拷贝
    tmp = clone(); 113
    //寻找从i出发的路径，路径的起点和终点地址分别是beg和end
    beg = EulerCircuit(i, end); //第一段回路，用过的边已经删除
    while(true)
    {
        p = beg;
        while(p->next != NULL) //从前往后找路径上尚余边的顶点
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
            break; //全部边都访问过，消失了
        }
        q = p->next; //下一个开始顶点
        tb = EulerCircuit(q->NodeNum, te); //下一个欧拉路径
        te->next =q->next;
        p->next = tb; //q被取下
        delete q;
    }
    //恢复原图
    delete [] verList;
    verList = tmp;
    //显示得到的欧拉回路
    cout << "欧拉回路是：" << endl;
    while(beg !=NULL)
    {
        //边输出释放单链表
        cout << verList[beg->NodeNum].ver << '\t';
        p = beg;
        beg = beg->next;
        delete p;
    }
    cout << endl;
}

