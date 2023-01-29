#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXV = 20;//��󶥵���
const int INF = 100000;//�����
struct Node
{
	int v, dis;//vΪ�ڽӱߵ�Ŀ�궥�㣬dis�Ǳ�Ȩ
};
vector<Node> Adj[MAXV];//�ڽӱ�
int V;//������
int E;//����
int d[MAXV];//��㵽���������·������
int num[MAXV];//��¼�������Ӵ���
bool inq[MAXV];//��¼�����Ƿ��ڶ�����

void Bellman(int s)//ָ������s
{
	for (int u = 0; u < V; u++)
	{
		d[u] = INF;
		num[u] = 0;
		inq[u] = false;
	}
	queue<int> Q;
	Q.push(s);//Դ�����
	inq[s] = true;//Դ�������
	num[s]++;//Դ����Ӵ�����һ
	d[s] = 0;//Դ���d��ȻΪ0
	while (!Q.empty())
	{
		int u = Q.front();//���׶�����Ϊu
		Q.pop();//����
		inq[u] = false;//����u���ڶ�����
		//����u�������ڽӱ�v
		for(int j = 0; j < Adj[u].size(); j++)
		{
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if (d[v] > d[u] + dis)
			{
				d[v] = d[u] + dis;//�ɳڲ���
				if (!inq[v])//���v���ڶ�����
				{
					Q.push(v);
					inq[v] = true;
					num[v]++;
				}
			}
		}
	}
}
int main()
{
	cin >> V >> E;
	int s,e;
	cin>>s>>e;
	for (int i = 0; i < E; i++)
	{
		int u, v,dis;
		cin >> u >> v >> dis;
		Node e;
		e.v = v;
		e.dis = dis;
		Adj[u].push_back(e);//ע��һ������vector�Ǵ�0��ʼ��
	}
	Bellman(s);
	cout<<d[e];
	return 0;
}

