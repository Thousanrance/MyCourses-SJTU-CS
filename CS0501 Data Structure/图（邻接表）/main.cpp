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
class adjListGraph:public graph<TypeOfVer, TypeOfEdge>
{
public:
    adjListGraph(int vSize, const TypeOfVer d[]);
    void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);
    void remove(TypeOfVer x, TypeOfVer y);
    bool exist(TypeOfVer x, TypeOfVer y)const;
    ~adjListGraph();
    void dfs();
    void bfs();
private:
    struct edgeNode
    {
        //邻接表中存储边的结点类
        int end; //终点编号
        TypeOfEdge weight; //边的权值
        edgeNode *next;
        edgeNode(int e, TypeOfEdge w, edgeNode *n = NULL)
        {
            end = e;
            weight = w;
            next = n;
        }
    };
    struct verNode
    {
        //保存顶点的数据元素类型
        TypeOfVer ver; //顶点值
        edgeNode *head; //对应的单链表的头指针
        verNode(edgeNode *h = NULL)
        {
            head = h;
        }
        verNode *verList; //唯一属性，尺寸父类定义
        int find(TypeOfVer v)const
        {
            for(int i = 0; i < Vers; ++i)
            {
                if(verList[i].ver == v)
                {
                    return i;
                }
            }
        }
    };

    void dfs(int start, bool visited[])const;
};

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(int vSize, const TypeOfVer d[])
{
    Vers = vSize; Edges = 0;
    verList = new verNode[vSize];
    for(int i = 0; i < Vers; ++i)
    {
        verList[i].ver = d[i];
    }
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph()
{
    int i;
    edgeNode *p;
    for(i = 0; i < Vers; ++i)
    {
        while((p = verList[i].head)!=NULL)
        {
            //总是删首结点
            verList[i].head = p->next;
            delete p;
        }
    }
    delete [] verList;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w)
{
    int u = find(x), v = find(y);
    verList[u].head = new edgeNode(v, w, verList[u].head);//插脖子上
    ++Edges;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::remove(TypeOfVer x,TypeOfVer y)
{
    int u = find(x), v = find(y);
    edgeNode *p = verList[u].head, *q;
    if(p == NULL)
    {
        return; //结点u没有相连的边
    }
    if(p->end == v)
    {
        //单链表中的第一个结点就是被删除的边
        verList[u].head = p->next;
        delete p; --Edges;
        return;
    }
    while(p->next !=NULL && p->next->end != v)
    {
        p = p->next;//查找被删除的边
    }
    if(p->next != NULL)
    {
        //删除
        q = p->next;
        p->next = q->next;
        delete q;
        --Edges;
    }
}

template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer x, TypeOfVer y) const
{
    int u = find(x), v = find(y);
    edgeNode *p = verList[u].head;
    while(p !=NULL && p->end != v)
    {
        p = p->next;
    }
    if(p == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs()const
{
    bool *visited = new bool[Vers];
    for(int i=0; i < Vers; ++i)
    {
        visited[i] = false;
    }
    cout << "当前图的深度优先遍历序列为：" << endl;
    for(i = 0; i < Vers; ++i)
    {
        if(visited[i] == true)
        {
           continue;
        }
        dfs(i, visited); //思考：无向图时，这里调用的次数意味着什么？
        cout << endl;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start, bool visited[])const
{
    edgeNode *p = verList[start].head;
    cout << verList[start].ver << '\t';
    visited[start] = true;
    while(p != NULL)
    {
        if(visited[p->end] == false)
        {
            dfs(p->end, visited);
        }
        p = p->next; //巧妙之处
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::bfs()const
{
    bool *visited = new bool[Vers];
    int currentNode;
    linkQueue<int> q;
    edgeNode *p;
    for(int i=0; i < Vers; ++i)
    {
        visited[i] = false;
    }
    cout << "当前图的广度优先遍历序列为：" << endl;
    for(i = 0; i < Vers; ++i)
    {
        if(visited[i] == true)
        {
            continue;
        }
        q.enQueue(i); //思考：无向图时这里执行的次数意味着什么？
        while(!q.isEmpty())
        {
            currentNode = q.deQueue();
            if(visited[currentNode] == true)
            {
                continue;
            }
            cout << verList[currentNode].ver << '\t';
            visited[currentNode] = true;
            p = verList[currentNode].head;
            while(p != NULL)
            {
                if(visited[p->end] == false)
                {
                    q.enQueue(p->end);
                }
                p = p->next; //一个结点在访问前可能多次进队
            }
        }
        cout << endl;
    }
}

template <class verType, class edgeType>
void Graph<verType, edgeType>::DFS()const //深度优先搜索非递归实现
{
    seqStack<edgeNode<edgeType>> s;
    edgeNode<edgeType> *p;
    bool *visited;
    int i, start;
    //为visited创建动态数组空间，并置初始访问标志为false
    visited = new bool[verts];
    if(!visited)
    {
        throw illegalSize();
    }
    for(i=0; i<verts; i++)
    {
        visited[i]=false;
    }
    //逐一找到未被访问过顶点，做深度优先遍历
    for (i=0; i<verts; i++)
    {
        if(visited[i])
        {
            continue;
        }
        cout<<verList[start].data<<'\t';
        visited[i] = true;
        if(verList[i].adj)
        {
            s.push(verList[i].adj);
        }
        while (!s.isEmpty())
        {
            p = s.top();
            s.pop();
            if(!visited[p->dest])
            {
                cout<<verList[start].data<<'\t';
                visited[start] = true;
            }
            while(p->link)
            {
                if(!visited[p->link->dest])
                {
                    s.push(p->link);
                    break;
                }
                p = p->link;
            }
        }
        cout << endl;
    }
}

template <class verType, class edgeType>
bool Graph<verType, edgeType>::judgeCon()const //无向图中顶点个数和边条数关系
{
    bool *visited;
    int i, count=0;
    //为visited创建动态数组空间，并置初始访问标志为false。
    visited = new bool[verts];
    if(!visited)
    {
        throw illegalSize();
    }
    for(i=0; i<verts; i++)
    {
        visited[i]=false;
    }
    for(i=0; i<verts; i++)
    {
        if (!visited[i])
        {
            DFS(i, visited);
            count++;
        }
        cout<<endl;
    }
    if(count==1)
    {
        return true;
    }
    return false;
}

