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
        //�ڽӱ��д洢�ߵĽ����
        int end; //�յ���
        TypeOfEdge weight; //�ߵ�Ȩֵ
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
        //���涥�������Ԫ������
        TypeOfVer ver; //����ֵ
        edgeNode *head; //��Ӧ�ĵ������ͷָ��
        verNode(edgeNode *h = NULL)
        {
            head = h;
        }
        verNode *verList; //Ψһ���ԣ��ߴ縸�ඨ��
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
            //����ɾ�׽��
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
    verList[u].head = new edgeNode(v, w, verList[u].head);//�岱����
    ++Edges;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::remove(TypeOfVer x,TypeOfVer y)
{
    int u = find(x), v = find(y);
    edgeNode *p = verList[u].head, *q;
    if(p == NULL)
    {
        return; //���uû�������ı�
    }
    if(p->end == v)
    {
        //�������еĵ�һ�������Ǳ�ɾ���ı�
        verList[u].head = p->next;
        delete p; --Edges;
        return;
    }
    while(p->next !=NULL && p->next->end != v)
    {
        p = p->next;//���ұ�ɾ���ı�
    }
    if(p->next != NULL)
    {
        //ɾ��
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
    cout << "��ǰͼ��������ȱ�������Ϊ��" << endl;
    for(i = 0; i < Vers; ++i)
    {
        if(visited[i] == true)
        {
           continue;
        }
        dfs(i, visited); //˼��������ͼʱ��������õĴ�����ζ��ʲô��
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
        p = p->next; //����֮��
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
    cout << "��ǰͼ�Ĺ�����ȱ�������Ϊ��" << endl;
    for(i = 0; i < Vers; ++i)
    {
        if(visited[i] == true)
        {
            continue;
        }
        q.enQueue(i); //˼��������ͼʱ����ִ�еĴ�����ζ��ʲô��
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
                p = p->next; //һ������ڷ���ǰ���ܶ�ν���
            }
        }
        cout << endl;
    }
}

template <class verType, class edgeType>
void Graph<verType, edgeType>::DFS()const //������������ǵݹ�ʵ��
{
    seqStack<edgeNode<edgeType>> s;
    edgeNode<edgeType> *p;
    bool *visited;
    int i, start;
    //Ϊvisited������̬����ռ䣬���ó�ʼ���ʱ�־Ϊfalse
    visited = new bool[verts];
    if(!visited)
    {
        throw illegalSize();
    }
    for(i=0; i<verts; i++)
    {
        visited[i]=false;
    }
    //��һ�ҵ�δ�����ʹ����㣬��������ȱ���
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
bool Graph<verType, edgeType>::judgeCon()const //����ͼ�ж�������ͱ�������ϵ
{
    bool *visited;
    int i, count=0;
    //Ϊvisited������̬����ռ䣬���ó�ʼ���ʱ�־Ϊfalse��
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

