#include <iostream>

using namespace std;

template <class TypeOfVer, class TypeOfEdge>
class graph
{
public:
    virtual void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) = 0;
    virtual void remove(TypeOfVer x, TypeOfVer y) = 0;
    virtual bool exist(TypeOfVer x, TypeOfVer y)const = 0;
    int numOfVer()const
    {
        return Vers;
    }
    int numOfEdge()const
    {
        return Edges;
    }
protected:
    int Vers;
    int Edges;
};

template <class TypeOfVer, class TypeOfEdge>
class adjMatrixGraph:public graph<TypeOfVer, TypeOfEdge>
{
public:
    adjMatrixGraph(int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag);
    void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);
    void remove(TypeOfVer x, TypeOfVer y);
    bool exist(TypeOfVer x, TypeOfVer y)const;
    ~adjMatrixGraph();
private:
    int Vers;
    int Edges;
    TypeOfEdge **edge; //存放邻接矩阵
    TypeOfVer *ver; //存放结点值
    TypeOfEdge noEdge; //邻接矩阵中的∞的表示值
    int find(TypeOfVer v)const
    {
        for(int i = 0; i < Vers; ++i)
        {
            if(ver[i] == v)
            {
                return i;
            }
        }
     }
};

template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::~adjMatrixGraph()
{
    delete [] ver;
    for(int i=0; i<Vers; ++i)
    {
        delete [] edge[i];
    }
    delete [] edge;
}

template <class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w)
{
    int u = find(x), v = find(y);
    edge[u][v] = w;
    ++Edges;
}

template <class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::remove(TypeOfVer x, TypeOfVer y)
{
    int u = find(x), v = find(y);
    edge[u][v] = noEdge;
    --Edges;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjMatrixGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer x, TypeOfVer y) const
{
    int u = find(x), v = find(y);
    if(edge[u][v] == noEdge)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    return 0;
}

