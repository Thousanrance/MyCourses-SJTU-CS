#include<iostream>
#include<stack>

using namespace std;

class Tree
{
private:
    struct Node
    {
        int num;
        Node* father;
        Node():father(NULL){};
        Node(int& x,Node* f=NULL)
        {
            num=x;
            father=f;
        }
        ~Node(){};
    };
    Node* tree;
    int current;

public:
    Tree(int n)
    {
        tree=new Node[n+1];
        tree[1].num=1;
        current=1;
    }
    void addchild(int& l,int& r,int i);
    int findanc(int x,int y);
    ~Tree(){};
};

void Tree::addchild(int& l,int& r,int i)
{
    if(l!=0)
    {
        Node left(l,&tree[i]);
        current++;
        tree[current]=left;
    }
    if(l!=0&&r!=0)
    {
        Node right(r,&tree[i]);
        current++;
        tree[current]=right;
    }
    if(l==0&&r!=0)
    {
        Node right(r,&tree[i]);
        current++;
        tree[current]=right;
    }
}

int Tree::findanc(int x,int y)
{
    int anc=0;
    stack<int> X;
    stack<int> Y;
    Node* tmp=&tree[x];
    while(tmp->num!=1)
    {
        tmp=tmp->father;
        X.push(tmp->num);
    }

    tmp=&tree[y];
    while(tmp->num!=1)
    {
        tmp=tmp->father;
        Y.push(tmp->num);
    }

    while(!X.empty()&&!Y.empty())
    {
        if(X.top()==Y.top())
        {
            anc=X.top();
            X.pop();
            Y.pop();
        }
        else
        {
            break;
        }
    }
    return anc;
}

int main()
{
    int n,x,y;
    scanf("%d",&n);
    //printf("n=%d\n",n);
    scanf("%d",&x);
    //printf("x=%d\n",x);
    scanf("%d",&y);
    //printf("y=%d\n",y);
    Tree a(n);
    for(int i=1;i<=n;i++)
    {
        int l,r;
        scanf("%d",&l);
        //printf("l=%d\n",l);
        scanf("%d",&r);
        //printf("r=%d\n",r);
        a.addchild(l,r,i);
    }
    if(a.findanc(x,y)==0)
    {
        return 0;
    }
    printf("%d",a.findanc(x,y));
    return 0;
}

/*
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
*/
