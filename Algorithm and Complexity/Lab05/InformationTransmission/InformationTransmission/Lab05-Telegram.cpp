#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>

#define MAX_NUM_OF_CITY 500
#define MAX_NUM_OF_EDGE 250000

const int inf = 2147483647;

int num_of_city;
int num_of_edge;
int num_of_query;

int path[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY];

// You may add some other Header file at here
using namespace std;
void Telegram()
{
	// You should complete your code at here
	/* Input N, E */
	scanf("%d %d", &num_of_city, &num_of_edge);

	/* Initialize */
	for (int i = 0; i < num_of_city; i++)
	{
		for (int j = 0; j < num_of_city; j++)
		{
			if (i == j)
			{
				path[i][j] = 0;
			}
			else
			{
				path[i][j] = inf;
			}
		}
	}

	/* Input X, Y, M */
	int x, y, m;
	for (int i = 0; i < num_of_edge; i++)
	{
		scanf("%d %d %d", &x, &y, &m);
		path[x - 1][y - 1] = m;
	}

	/* Floyd: Shortest paths in Telegram mail mode */
	for (int k = 0; k < num_of_city; k++)
	{
		for (int u = 0; u < num_of_city; u++)
		{
			for (int v = 0; v < num_of_city; v++)
			{
				if (path[u][k] != inf && path[k][v] != inf && path[u][v] > path[u][k] + path[k][v])
				{
					path[u][v] = path[u][k] + path[k][v];
				}
			}
		}
	}

	/* Update the path for cities in the same zone */
	for (int i = 0; i < num_of_city; i++)
	{
		for (int j = 0; j < num_of_city; j++)
		{
			if (path[i][j] < inf && path[j][i] < inf)
			{
				path[i][j] = 0;
				path[j][i] = 0;
			}
		}
	}

	/* Floyd: Shortest paths in Internet transmission mode */
	for (int k = 0; k < num_of_city; k++)
	{
		for (int u = 0; u < num_of_city; u++)
		{
			for (int v = 0; v < num_of_city; v++)
			{
				if (path[u][k] != inf && path[k][v] != inf && path[u][v] > path[u][k] + path[k][v])
				{
					path[u][v] = path[u][k] + path[k][v];
				}
			}
		}
	}

	/* Input K */
	scanf("%d", &num_of_query);

	int a, b;
	for (int i = 0; i < num_of_query; i++)
	{
		/* Input A, B */
		scanf("%d %d", &a, &b);

		/* Output the shortest path */
		if (path[a - 1][b - 1] < inf)
		{
			if (path[b - 1][a - 1] < inf)
			{
				printf("0");
			}
			else
			{
				printf("%d", path[a - 1][b - 1]);
			}
		}
		else
		{
			printf("Impossible");
		}

		printf("\n");

	}
}

int main()
{
	freopen("Lab05-Telegram.in", "r", stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		Telegram();
	}
	return 0;
}
