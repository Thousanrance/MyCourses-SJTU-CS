#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXV = 20;//最大顶点数
const int INF = 100000;//无穷大
struct Node
{
	int v, dis;//v为邻接边的目标顶点，dis是边权
};
vector<Node> Adj[MAXV];//邻接表
int V;//顶点数
int E;//边数
int d[MAXV];//起点到达各点的最短路径长度
int num[MAXV];//记录顶点的入队次数
bool inq[MAXV];//记录顶点是否在队列里

void Bellman(int s)//指定顶点s
{
	for (int u = 0; u < V; u++)
	{
		d[u] = INF;
		num[u] = 0;
		inq[u] = false;
	}
	queue<int> Q;
	Q.push(s);//源点入队
	inq[s] = true;//源点已入队
	num[s]++;//源点入队次数加一
	d[s] = 0;//源点的d显然为0
	while (!Q.empty())
	{
		int u = Q.front();//队首顶点编号为u
		Q.pop();//出队
		inq[u] = false;//设置u不在队列中
		//遍历u的所有邻接边v
		for(int j = 0; j < Adj[u].size(); j++)
		{
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if (d[v] > d[u] + dis)
			{
				d[v] = d[u] + dis;//松弛操作
				if (!inq[v])//如果v不在队列里
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
		Adj[u].push_back(e);//注意一个问题vector是从0开始的
	}
	Bellman(s);
	cout<<d[e];
	return 0;
}

