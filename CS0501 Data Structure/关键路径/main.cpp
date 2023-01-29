#include <iostream>

using namespace std;

template <class edgeType>
struct keyEdge
{
    int u, v;
    edgeType weight;
    edgeType early, last;
};
template <class verType, class edgeType>
void Graph<verType, edgeType>::keyActivity (verType start, verType end)const
{
    int *inDegree;
    edgeType *verEarly,
    *verLast; //�¼�-��������緢��ʱ�䡢��ٷ���ʱ��
    keyEdge<edgeType> *edgeEL; //��¼ÿ���-�ߵ����緢��ʱ�䡢��ٷ���ʱ��
    seqStack<int> s1; //s1�������Ϊ0�Ķ���
    seqStack<int> s2; //s2����ȷ���������緢��ʱ��Ķ���˳��
    int i, j, k;
    int u, v;
    int intStart, intEnd;
    //������̬����ռ�
    inDegree = new int[verts];
    verEarly = new edgeType[verts];
    verLast = new edgeType[verts];
    edgeEL = new keyEdge<edgeType>[edges];
    //�ҵ������յ���±�
    intStart = intEnd = -1;
    for(i=0; i<verts; i++)
    {
        if(verList[i]==start)
        {
            intStart = i;
        }
        if(verList[i]==end)
        {
            intEnd = i;
        }
    }
    if((intStart==-1)||(intEnd==-1))
    {
        throw outOfBound(); //����ÿ���������ȣ��ڽӾ���ÿһ���бߵ�Ԫ�ظ������
    }
    for(j=0; j<verts; j++)
    {
        inDegree[j] = 0;
        for(i=0; i<verts; i++)
        {
            if((i!=j)&&(edgeMatrix[i][j]!=noEdge))
            {
                inDegree[j]++;
            }
        }
    }//��ʼ���������緢��ʱ��
    for(i=0; i<verts; i++)
    {
        verEarly[i] = 0;
    }
    //����ÿ����������緢��ʱ��
    //��ʼ���������緢��ʱ��
    verEarly[intStart] = 0;
    i = intStart; //����������������緢��ʱ��
    while(i!=intEnd) //���յ���Ϊ���Ϊ��ѹջ����ջʱ���������
    {
        for(j=0; j<verts; j++)
        {
            if ((i!=j)&&(edgeMatrix[i][j]!=noEdge))
            {
                inDegree[j]--;
                if(inDegree[j]==0)
                {
                    s1.push(j); //���Ϊ0����ջ
                }
                if(verEarly[j]<verEarly[i]+edgeMatrix[i][j])
                {
                    verEarly[j] = verEarly[i]+edgeMatrix[i][j];
                }
            }
        }
        s2.push(i); //��ǰȷ�������緢��ʱ��Ķ�����ջ
        i = s1.top();
        s1.pop();
    }//��ʼ��������ٷ���ʱ��
    for(i=0; i<verts; i++)
    {
        verLast[i] = verEarly[intEnd];
    }
    //���ռ��㶥�����緢��ʱ���������μ��㶥����ٷ���ʱ��
    while(!s2.isEmpty())
    {
        j = s2.top();
        s2.pop();
        //�޸��������붥��j�ıߵļ�β�������ٷ���ʱ��
        for(i=0; i<verts; i++)
        {
            if((i!=j)&&(edgeMatrix[i][j]!=noEdge))
            {
                if(verLast[i] > verLast[j] - edgeMatrix[i][j])
                {
                    verLast[i] = verLast[j] - edgeMatrix[i][j];
                }
            }
        }
    }//��������Ϣ����
    k=0;
    for(i=0; i<verts; i++)
    {
        for (j=0; j<verts; j++)
        {
            if ((i!=j)&&(edgeMatrix[i][j]!=noEdge))
            {
                edgeEL[k].u = i;
                edgeEL[k].v = j;
                edgeEL[k].weight = edgeMatrix[i][j];
                k++;
            }//���ߵ����緢��ʱ��<u,v>����Ϊ��β����u�����緢��ʱ��
        }//���ߵ���ٷ���ʱ��<u,v>����Ϊ��ͷ����v����ٷ���ʱ��
    }
    //-<u,v>�ߵ�Ȩ��
    for(k=0; k<edges; k++)
    {
        u = edgeEL[k].u;
        v = edgeEL[k].v;
        edgeEL[k].early = verEarly[u];
        edgeEL[k].last = verLast[v] - edgeEL[k].weight;
    }//����ؼ��
    cout<<"�ؼ����"<<endl;
    for(k=0; k<edges; k++)
    {
        if (edgeEL[k].early == edgeEL[k].last)
        {
            u = edgeEL[k].u;
            v = edgeEL[k].v;
            cout<<verList[u]<<"->"<<verList[v]<<endl;
            cout<<"early: "<<edgeEL[k].early<<" "<<"last: "<<edgeEL[k].last;
            cout<<endl<<endl;
        }
    }
}
