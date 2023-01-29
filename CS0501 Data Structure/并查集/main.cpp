#include <iostream>

using namespace std;

int par[10000];//����
int height[10000];//���ĸ߶�

//��ʼ��n��Ԫ��
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        height[i]=0;
    }
}

//��ѯ���ĸ�
int find(int x)
{
    if(par[x]==x)
    {
        return x;
    }
    else
    {
        return par[x]=find(par[x]);
    }
}

//�ϲ�x��y�����ļ���
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
    {
        return;
    }
    if(height[x]<height[y])
    {
        par[x]=y;
    }
    else
    {
        par[y]=x;
        if(height[x]==height[y])
            height[x]++;
    }
}

//�ж�x��y�Ƿ�����ͬһ������
bool same(int x,int y)
{
    return find(x)==find(y);
}

int main()
{
    int n,m;
    cin>>n>>m;
    init(n);
    while(m--)
    {
        int op;
        int x,y;
        cin>>op>>x>>y;
        if(op==2)
        {
            if(same(x,y))
            {
                cout<<"Y"<<endl;
            }
            else
            {
                cout<<"N"<<endl;
            }
        }
        if(op==1)
        {
            unite(x,y);
        }
    }

    return 0;
}
