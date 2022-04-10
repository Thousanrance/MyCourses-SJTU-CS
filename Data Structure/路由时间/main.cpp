#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn=100;
int map[maxn][maxn];
int dis[maxn];
bool vis[maxn];

int n;
void dijk(int s)
{
    memset(dis,0x3f,sizeof(dis));      //快速初始化为无穷大
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    while(1)
    {
        int k=0;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]<dis[k]) //这一步找未收录顶点中dis值最小的
                k=j;
        }
        if(!k) return ;               //没有未收录的顶点，则返回（注意顶点从1开始，k为0一定是没找到）
        vis[k]=1;                     //收录顶点k
        for(int j=1;j<=n;j++)
        {
            if(dis[j]>dis[k]+map[k][j])
            {
                dis[j]=dis[k]+map[k][j];
            }
        }
    }
}

int main()
{
    int m;
    cin>>n>>m;
    int s;
    cin>>s;
    memset(map,0x3f,sizeof(map));
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        map[x][y]=z;
    }
    dijk(s);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>res)
        {
            res=dis[i];
        }
    }
    if(res>10000)
    {
        res=-1;
    }
    cout<<res;
    return 0;
}

