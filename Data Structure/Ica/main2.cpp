#include<iostream>
using namespace std;

struct node
{
	int left;
	int right;
	int parent;
};
int main()
{
	int N, X, Y, tmp, * xparent, * yparent, countx = 0, county = 0, m = 0;
	node* tree;
	cin >> N >> X >> Y;

	tree = new node[N + 1];
	tree[1].parent = 0;
	for (int i = 1; i <= N; i++)
	{
		int left, right;

		cin >> left >> right;
		tree[i].left = left;
		tree[i].right = right;
		if(left)
        {
            tree[left].parent = i;
        }
		if(right)
        {
            tree[right].parent = i;
        }
	}
	tmp = X;
	while(tree[tmp].parent)
	{
		tmp = tree[tmp].parent;
		countx++;
	}
	tmp = Y;
	while(tree[tmp].parent)
	{
		tmp = tree[tmp].parent;
		county++;
	}
	xparent = new int[countx];
	m = 0;
	tmp = X;
	while(tree[tmp].parent)
	{
		tmp = tree[tmp].parent;
		xparent[m] = tmp;
		m++;
	}
	yparent = new int[county];
	m = 0;
	tmp = Y;
	while(tree[tmp].parent)
	{
		tmp = tree[tmp].parent;
		yparent[m] = tmp;
		m++;
	}
	for(int j = 0; j < m; j++)
	{
		for (int k = 0; k < countx; k++)
        {
			if (yparent[j] == xparent[k])
            {
				cout << yparent[j] << endl;
                return 0;
			}
        }
	}

	return 0;

}
