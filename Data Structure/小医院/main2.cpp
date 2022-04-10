#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct people
{
	int ID;
	int weight;
	bool operator<(const people p)const
	{
		return ((weight < p.weight) || (weight == p.weight) && (ID > p.ID));
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int w, pID, n, dID;
	int j = 0;
	cin >> n;
	char* str = new char[5];
	priority_queue<people> q1, q2, q3;
	for(int i = 1; i <= n; i++)
	{
		cin >> str;
		if(strlen(str)==2)
        {
			cin >> pID >> w;
			j++;
			people tmp;
			tmp.ID = j;
			tmp.weight = w;
			switch(pID)
			{
			case 1: q1.push(tmp); break;
			case 2: q2.push(tmp); break;
			case 3: q3.push(tmp); break;
			}
		}
		else
		{
			cin >> dID;
			switch (dID)
			{
                case 1:
                        if(q1.empty())
                        {
                            cout << "EMPTY\n";
                        }
                        else
                        {
                            people tmp = q1.top();
                            q1.pop();
                            cout << tmp.ID << '\n';
                        }
                        break;
                case 2:
                        if(q2.empty())
                        {
                            cout << "EMPTY\n";
                        }
                        else
                        {
                            people tmp = q2.top();
                            q2.pop();
                            cout << tmp.ID << '\n';
                        }
                        break;
                case 3:
                        if(q3.empty())
                        {
                            cout << "EMPTY\n";
                        }
                        else
                        {
                            people tmp = q3.top();
                            q3.pop();
                            cout << tmp.ID << '\n';
                        }
                        break;
			}
		}
	}
	return 0;
}
