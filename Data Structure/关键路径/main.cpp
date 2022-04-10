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
    *verLast; //事件-顶点的最早发生时间、最迟发生时间
    keyEdge<edgeType> *edgeEL; //记录每个活动-边的最早发生时间、最迟发生时间
    seqStack<int> s1; //s1保存入度为0的顶点
    seqStack<int> s2; //s2保存确定顶点最早发生时间的顶点顺序
    int i, j, k;
    int u, v;
    int intStart, intEnd;
    //创建动态数组空间
    inDegree = new int[verts];
    verEarly = new edgeType[verts];
    verLast = new edgeType[verts];
    edgeEL = new keyEdge<edgeType>[edges];
    //找到起点和终点的下标
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
        throw outOfBound(); //计算每个顶点的入度，邻接矩阵每一列有边的元素个数相加
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
    }//初始化顶点最早发生时间
    for(i=0; i<verts; i++)
    {
        verEarly[i] = 0;
    }
    //计算每个顶点的最早发生时间
    //初始化起点的最早发生时间
    verEarly[intStart] = 0;
    i = intStart; //计算其他顶点的最早发生时间
    while(i!=intEnd) //当终点因为入度为零压栈、出栈时，计算结束
    {
        for(j=0; j<verts; j++)
        {
            if ((i!=j)&&(edgeMatrix[i][j]!=noEdge))
            {
                inDegree[j]--;
                if(inDegree[j]==0)
                {
                    s1.push(j); //入度为0，进栈
                }
                if(verEarly[j]<verEarly[i]+edgeMatrix[i][j])
                {
                    verEarly[j] = verEarly[i]+edgeMatrix[i][j];
                }
            }
        }
        s2.push(i); //当前确定了最早发生时间的顶点入栈
        i = s1.top();
        s1.pop();
    }//初始化顶点最迟发生时间
    for(i=0; i<verts; i++)
    {
        verLast[i] = verEarly[intEnd];
    }
    //按照计算顶点最早发生时间逆序依次计算顶点最迟发生时间
    while(!s2.isEmpty())
    {
        j = s2.top();
        s2.pop();
        //修改所有射入顶点j的边的箭尾顶点的最迟发生时间
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
    }//建立边信息数组
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
            }//将边的最早发生时间<u,v>设置为箭尾顶点u的最早发生时间
        }//将边的最迟发生时间<u,v>设置为箭头顶点v的最迟发生时间
    }
    //-<u,v>边的权重
    for(k=0; k<edges; k++)
    {
        u = edgeEL[k].u;
        v = edgeEL[k].v;
        edgeEL[k].early = verEarly[u];
        edgeEL[k].last = verLast[v] - edgeEL[k].weight;
    }//输出关键活动
    cout<<"关键活动："<<endl;
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
