#include<iostream>
#include<string>
#include<queue>
using namespace std;


struct ArcNode
{
    int adjvex;      //�ߵ�����һ�ߵĶ����±�
    ArcNode * next; //��һ���ߵı���
    int weight;
};
struct Vnode
{
    //string data;           //������Ϣ
    ArcNode * firstarc;  //��һ�������ڸö���ı�
};

struct Dis
{
    //string path;  //�Ӷ��㵽�øö������·��
    int  weight;  //���·����Ȩ��
};

class Graph
{
private:
    int vexnum;    //�ߵĸ���
    int edge;       //�ߵ�����
    Vnode * node; //�ڽӱ�
    Dis  * dis;   //��¼���·����Ϣ������
public:
    Graph(int vexnum, int edge);
    ~Graph();
    void createGraph(); //����ͼ
    bool SPFA(int begin);   //������·��
    void print_path(int e); //��ӡ���·��
};


Graph::Graph(int vexnum, int edge)
{
    //�Զ�������ͱߵ��������и�ֵ
    this->vexnum = vexnum;
    this->edge = edge;

    //Ϊ�ڽӾ��󿪱ٿռ�
    node = new Vnode[this->vexnum];
    dis = new Dis[this->vexnum];
    int i;
    //���ڽӱ���г�ʼ��
    for (i = 0; i < this->vexnum; ++i)
    {
        //node[i].data = "v" + to_string(i + 1);
        node[i].firstarc = NULL;
    }
}

Graph::~Graph()
{
    int i;
    //�ͷſռ䣬���Ǽ�סͼ��ÿ����������ҲҪһһ�ͷ�
    ArcNode * p, *q;
    for (i = 0; i < this->vexnum; ++i)
    {
        //һ��Ҫע�����Ҫ�жϸö���ĳ��ȵ����Ƿ�Ϊ�գ���Ȼ�����
        if (this->node[i].firstarc)
        {
            p = node[i].firstarc;
            while (p)
            {
                q = p->next;
                delete p;
                p = q;
            }
        }

    }
    delete [] node;
    delete [] dis;
}

// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
//�����1��ʼ���

void Graph::createGraph()
{
    //cout << "����ߵ������յ��Լ����ߵ�Ȩ��(�����Ŵ�1��ʼ)��" << endl;
    int i;
    int start;
    int end;
    int weight;
    for (i = 0; i < this->edge; ++i)
    {
        cin >> start >> end >> weight;

        ArcNode *temp = new ArcNode;
        temp->adjvex = end - 1;
        temp->weight = weight;
        temp->next = NULL;
        //����ö��������ı�Ϊ�գ�����Ե�һ����ʼ
        if(node[start - 1].firstarc == NULL)
        {
            node[start - 1].firstarc = temp;
        }
        else
        {
            //��������뵽����������һ��λ��
            ArcNode * now = node[start - 1].firstarc;
            //�ҵ���������һ�����
            while (now->next)
            {
                now = now->next;
            }
            now->next = temp;
        }
    }
}

bool Graph::SPFA(int begin)
{
    bool  *visit;
    //visit���ڼ�¼�Ƿ��ڶ�����
    visit = new bool[this->vexnum];
    int *input_queue_time;
    //input_queue_time���ڼ�¼ĳ����������еĴ���
    //���ĳ������еĴ������ڶ�����vexnum����ô˵�����ͼ�л���
    //û�����·���������˳���
    input_queue_time = new int[this->vexnum];
    queue<int> s;  //���У����ڼ�¼���·�����ı�ĵ�

    /*
    ���ֱ����ĳ�ʼ��
    */
    int i;
    for (i = 0; i < this->vexnum; i++)
    {
        visit[i] = false;
        input_queue_time[i] = 0;
        //·����ʼ����ʼ��Ϊֱ��·��,���ȶ�����Ϊ�����
        dis[i].weight = 10000000;
    }
    //�������������У����Ǽ�ס�Ǹ���������Ƕ����ţ���1��ʼ��
    s.push(begin - 1);
    visit[begin - 1] = true;
    ++input_queue_time[begin-1];
    //
    dis[begin - 1].weight = 0;

    int temp;
    int res;
    ArcNode *temp_node;
    //������е�ѭ��
    while (!s.empty())
    {
        //ȡ�����׵�Ԫ�أ����ҰѶ���Ԫ�س�����
        temp = s.front();
        s.pop();
        //����Ҫ��֤��һ����㲻Ϊ��
        if(node[temp].firstarc)
        {
            temp_node = node[temp].firstarc;
            while (temp_node)
            {
                //�����<temp,temp_node>��Ȩ�ؼ���temp���������·��
                //С��֮ǰtemp_node�����·���ĳ��ȣ������
                //temp_node�����·������Ϣ
                if (dis[temp_node->adjvex].weight > (temp_node->weight + dis[temp].weight))
                {
                    //����dis�������Ϣ
                    dis[temp_node->adjvex].weight = temp_node->weight + dis[temp].weight;

                    //�����û�ڶ����У�������У��޸Ķ�Ӧ����Ϣ
                    if (!visit[temp_node->adjvex])
                    {
                        visit[temp_node->adjvex] = true;
                        ++input_queue_time[temp_node->adjvex];
                        s.push(temp_node->adjvex);
                        if (input_queue_time[temp_node->adjvex] > this->vexnum)
                        {
                            //cout << "ͼ���л�" << endl;
                            return false;
                        }
                    }
                }
                temp_node = temp_node->next;
            }
        }
    }

    //��ӡ���·��

    return true;
}

void Graph::print_path(int e)
{
    cout<<dis[e-1].weight;
}


int main()
{
    int vexnum;
    int edge;
    int s,e;

    //cout << "����ͼ�Ķ�������ͱߵ�������" << endl;
    cin >> vexnum >> edge;

    cin >> s >> e;

    Graph graph(vexnum, edge);
    graph.createGraph();
    graph.SPFA(s);
    graph.print_path(e);
    return 0;
}
