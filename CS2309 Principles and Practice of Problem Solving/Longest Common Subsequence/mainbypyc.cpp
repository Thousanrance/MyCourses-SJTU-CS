#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>>c;
vector<vector<int>>b;

set<string>lcs;

void length(string X, string Y)
{
	int l1 = X.size();
	int l2 = Y.size();
	c = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1));
	b = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1));
	for (int i = 0; i <= l1; i++)
	{
		for (int j = 0; j <= l2; j++)
		{
			if (i == 0 || j == 0)
			{
				c[i][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;//0 zuoshangjiao
			}
			else if (c[i - 1][j] > c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 1; // 1 shang
			}
			else if (c[i - 1][j] < c[i][j - 1])
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = -1; // -1 zuo
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 2;
			}
		}
	}
}

string reverse(string str)
{
	if (str.size() == 1)
		return str;
	string tmp;
	int l = str.size();
	for (int i = 0; i < l; i++)
		tmp.push_back(str[l - 1 - i]);
	return tmp;
}

void findLCS(string X, int m, int n, string lcs_tmp)
{
	while (m > 0 && n > 0)
	{
		if (b[m][n] == 0)
		{
			lcs_tmp.push_back(X[m - 1]);
			m--;
			n--;
		}
		else if (b[m][n] == 1) m--;
		else if (b[m][n] == -1) n--;
		else if (b[m][n] == 2)
		{
			findLCS(X, m - 1, n, lcs_tmp);
			findLCS(X, m, n - 1, lcs_tmp);
			return;
		}
	}
	lcs.insert(reverse(lcs_tmp));
}

int main()
{
	string X, Y;
	cin >> X;
	cin >> Y;
	int m = X.size(), n = Y.size();

	length(X, Y);
	string sstr{};
	findLCS(X, m, n, sstr);
	// print set elements
	for (string str : lcs)
		cout << str << endl;
	return 0;
}
