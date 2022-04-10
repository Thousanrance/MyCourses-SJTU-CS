#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 100;
struct Binode
{
	char data;
	Binode* rchild;
	Binode* lchild;
};
/* Preb,Pree分别表示前序遍历的起点和终点，
Inb,Ine表示后续遍历的起点和终点*/
Binode* createBTree(int Preb,int Pree,int Inb,int Ine,char Preorder[], char Inorder[])
{
	if (Preb > Pree || Preb < 0)
		return NULL;
	Binode* Node = new Binode;
	Node->data = Preorder[Preb];//每找到一个根节点便将其数据存入需建立的树中
	Node->lchild = NULL;
	Node->rchild = NULL;
	int k = 0;//k记录每个根节点的下标（这里的根节点可以指整棵树的根节点，也可指左右子树的根节点）
	for (int i = Inb; i < Ine + 1; i++)//通过该循环查找根节点在中序遍历中的位置，从而划分左右子树并确定左右子树元素个数
	{
		if (Preorder[Preb] == Inorder[i])
		{
			k = i;
			break;
		}
	}
	Node->lchild = createBTree(Preb + 1, Preb + k - Inb, Inb, k - 1, Preorder, Inorder);//这里的k-Inb可以看做以Inorder[k]为根节点的左子树的节点数，所以Preb+1~Preb+k-Inb即为该左子树在前序中对应的区段，其他的可以依此推断。
	Node->rchild = createBTree(Preb + k - Inb + 1, Pree, k + 1, Ine, Preorder, Inorder);
	return Node;
}
void Postorder(Binode* Node)
{
	if (Node == NULL)
		return;
	Postorder(Node->lchild);
	Postorder(Node->rchild);
	cout << Node->data;
}
void destroy(Binode* root)
{
	if (root != NULL)
	{
		destroy(root->lchild);
		destroy(root->rchild);
		delete root;
	}
}
int main()
{
	Binode *root=NULL;
	char Preorder[MAX];
	char Inorder[MAX];
	//cout << "请输入前序遍历:";
	cin >> Preorder;
	//cout << "请输入中序遍历:";
	cin >> Inorder;
	int len = strlen(Preorder)-1;
	root=createBTree(0, len, 0, len, Preorder, Inorder);
	//cout << "该二叉树的后续遍历为:";
	Postorder(root);
	destroy(root);
}
