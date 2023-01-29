/*
Description
Implement the LCS algorithm introduced in the class. You are required to output all possible LCS. The output set of LCS should in lexicographical order. Same LCS only need to output once.

Examples
  Input:

springtime
printing
  Output:

printi
  Input:

basketball
krzyzewski
  Output:

ke
sk
Note
To make life easier, the input sequences only contain lower case letters.

You can use containers and common libraries to simplify coding.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

//#define £Ü 1
//#define ¡ü 2
//#define ¡û 3
//#define ©¾ 4

void printLCS(int** b,string X,int m,int n,string alcs, set<string>& lcss)
{
	while(m > 0 && n > 0)
	{
		if(b[m][n] == 1)
		{
			alcs = X[m - 1] + alcs;
			m--;
			n--;
		}
		else if(b[m][n] == 2)
        {
            m--;
        }
		else if(b[m][n] == 3)
        {
            n--;
        }
		else if(b[m][n] == 4)
		{
			printLCS(b,X,m - 1,n,alcs,lcss);
			printLCS(b,X,m,n - 1,alcs,lcss);
			return;
		}
	}
	lcss.insert(alcs);
}

set<string> LCS(string X, string Y)
{
    int m = X.size();
    int n = Y.size();
    //cout<<m<<' '<<n<<endl;

    int** b=new int*[m+1];
    for(int i = 0;i <= m;i++)
    {
        b[i] = new int[n+1];
    }

    int** c = new int*[m+1];
    for(int i = 0;i <= m;i++)
    {
        c[i] = new int[n+1];
    }

    for(int i = 0;i <= m;i++)
    {
        for(int j = 0;j <= n;j++)
        {
            b[i][j]=0;
            c[i][j]=0;
        }

    }

    for(int i = 1;i <= m;i++)
    {
        c[i][0] = 0;
    }
    for(int j = 0;j <= n;j++)
    {
        c[0][j] = 0;
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(X[i-1] == Y[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 1;
            }
            else if(c[i-1][j] > c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }
            else if(c[i-1][j] < c[i][j-1])
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
            else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 4;
			}
        }
    }

/*
    for(int i = 0;i <= m;i++)
    {
        for(int j = 0;j <= n;j++)
        {
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i = 0;i <= m;i++)
    {
        for(int j = 0;j <= n;j++)
        {
            cout<<b[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;

*/

    set<string> lcss;

    string alcs;

    printLCS(b,X,m,n,alcs,lcss);

    return lcss;
}

int main()
{
	string X, Y;
	cin >> X;
	cin >> Y;

	set<string> lcs = LCS(X, Y);

	// print set elements
	for (string str : lcs)
	{
		cout << str << endl;
	}

	return 0;
}
