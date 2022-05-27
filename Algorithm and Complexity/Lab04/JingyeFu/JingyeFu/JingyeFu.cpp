#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>

#define MAX_SIZE 1001

// You may add some other Header file at here
using namespace std;

int n; //几个朋友
int m; //几张复制卡
double P; //概率下限

int Fu[MAX_SIZE]; //每个朋友有几张福卡
int JyF[MAX_SIZE]; //每个朋友有几张敬业福

int FortuneValue; //福气值
int res[MAX_SIZE]; //最终选中的朋友的编号

int sel[MAX_SIZE]; //被选的朋友的编号
int vis[MAX_SIZE]; //在dfs中记录朋友是否被访问过

void dfs(int step, int start)//参数step代表选取第几个数字，参数start代表从集合的第几个开始选
{
    if (step == m)//如果选够了m个就计算检查是否更优
    {
        int tmpFortuneValue = 0;
        double tmp_P = 1;
        for (int i = 0; i < m; i++)
        {
            tmpFortuneValue += Fu[sel[i]];
            tmp_P *= ((Fu[sel[i]] - JyF[sel[i]]) * 1.0 / Fu[sel[i]]);
        }
        tmp_P = 1 - tmp_P;
        if (tmp_P >= P && tmpFortuneValue > FortuneValue) //更优的标准：概率合法且福气值更大
        {
            FortuneValue = tmpFortuneValue;
            for (int i = 0; i < m; i++)
            {
                res[i] = sel[i];
            }
        }
    }

    for (int i = start; i < n; i++)
    {
        if (vis[i] == 1)
        {
            continue;
        }
        vis[i] = 1;
        sel[step] = i;
        dfs(step + 1, i + 1);   //不降原则的核心步骤：从第i+1个元素开始选取(避免重选)
        vis[i] = 0;
    }
    return;
}

void JingyeFu()
{
	// You should complete your code at here
    //Input
    scanf("%d %d %lf", &n, &m, &P);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &Fu[i], &JyF[i]);
    }

    //initialize
    FortuneValue = 0;
    for (int i = 0; i < m; i++)
    {
        res[i] = -1;
    }

    //Find the optimal solution
    dfs(0, 0);

    //Output
    if (res[0] == -1) //没有可行解
    {
        cout << "No Solution" << endl;
    }
    else
    {
        cout << FortuneValue << endl;
        for (int i = 0; i < m; i++)
        {
            cout << res[i] + 1 << ' ';
        }
        cout << endl;
    }

	return;
}

int main()
{
	freopen("Lab04-JingyeFu.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		JingyeFu();
	}
	return 0;
}
