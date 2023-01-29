#include <iostream>
#include <cmath>
#include<queue>
using namespace std;

class binaryTree
{
private:
	struct Node
	{
		Node* left, * right;
		int data;

		Node():left(NULL),right(NULL){}
		Node(int item,Node*L = NULL,Node*R = NULL):data(item),left(L),right(R){}
		~Node(){}
	};
	Node* root;
public:
	binaryTree()
	{
	    root = NULL;
    }
	void createTree(int a[],int size,int flag)
	{
		queue<Node*>que;
		Node* tmp;
		int x, ldata, rdata;
		x = a[0];
		int i = 1;
		root = new Node(x);
		que.push(root);
		while (!que.empty() && i< size)
		{
			tmp = que.front();
			que.pop();
			ldata = a[i];
			rdata = a[++i];
			if(ldata != flag)
            {
                que.push(tmp->left = new Node(ldata));
            }
			if(rdata != flag)
            {
                que.push(tmp->right = new Node(rdata));
            }
			i++;
		}
	}
	int minDepth()
	{
		return minDepth(root);
	}
private:
	int minDepth(Node* t)
	{
		if(!t)
        {
            return 0;
        }
		if(!t->left && !t->right)
        {
            return 1;
        }
		int ans = 10000;
		if(t->left)
        {
            ans = minDepth(t->left) < ans ? minDepth(t->left) : ans;
        }
		if(t->right)
        {
            ans = minDepth(t->right) < ans ? minDepth(t->right) : ans;
        }
		return (ans + 1);
	}
};

int main()
{
	char* str = new char[100000];
	cin >> str;
	int tree[100000];
	int n = 0;
	while(*str != '\0')
	{
		if(*str == '-')
        {
			int num[5];
			str++;
			int i = 0;
			while (*str != ',' && *str != '\0')
			{
				num[i] = *str - '0';
				i++;
				str++;
			}
			int k = 0;
			int j = 0;
			while (j <= i)
			{
				k += num[j] * pow(10, i - j- 1);
				j++;
			}
			k *= (-1);
			tree[n] = k;
			n++;
		}
		if(*str == ',')
		{
			str++;
		}
		if(*str >= '0' && *str <= '9')
		{
			int num[5]{};
			int i = 0;
			while (*str != ','&&*str!='\0')
			{
				num[i] = *str - '0';
				i++;
				str++;
			}
			int k = 0;
			int j = 0;
			while (j <= i)
			{
				k += num[j] * pow(10, i - j - 1);
				j++;
			}
			tree[n] = k;
			n++;
		}
		if(*str == 'n')
		{
			str += 4;
			tree[n] = -1001;
			n++;
		}
	}
	binaryTree btree;
	btree.createTree(tree, n, -1001);
	int m = btree.minDepth();
	cout << m;
	return 0;
}
