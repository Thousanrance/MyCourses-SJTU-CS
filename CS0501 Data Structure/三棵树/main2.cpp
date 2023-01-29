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
/* Preb,Pree�ֱ��ʾǰ������������յ㣬
Inb,Ine��ʾ���������������յ�*/
Binode* createBTree(int Preb,int Pree,int Inb,int Ine,char Preorder[], char Inorder[])
{
	if (Preb > Pree || Preb < 0)
		return NULL;
	Binode* Node = new Binode;
	Node->data = Preorder[Preb];//ÿ�ҵ�һ�����ڵ�㽫�����ݴ����轨��������
	Node->lchild = NULL;
	Node->rchild = NULL;
	int k = 0;//k��¼ÿ�����ڵ���±꣨����ĸ��ڵ����ָ�������ĸ��ڵ㣬Ҳ��ָ���������ĸ��ڵ㣩
	for (int i = Inb; i < Ine + 1; i++)//ͨ����ѭ�����Ҹ��ڵ�����������е�λ�ã��Ӷ���������������ȷ����������Ԫ�ظ���
	{
		if (Preorder[Preb] == Inorder[i])
		{
			k = i;
			break;
		}
	}
	Node->lchild = createBTree(Preb + 1, Preb + k - Inb, Inb, k - 1, Preorder, Inorder);//�����k-Inb���Կ�����Inorder[k]Ϊ���ڵ���������Ľڵ���������Preb+1~Preb+k-Inb��Ϊ����������ǰ���ж�Ӧ�����Σ������Ŀ��������ƶϡ�
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
	//cout << "������ǰ�����:";
	cin >> Preorder;
	//cout << "�������������:";
	cin >> Inorder;
	int len = strlen(Preorder)-1;
	root=createBTree(0, len, 0, len, Preorder, Inorder);
	//cout << "�ö������ĺ�������Ϊ:";
	Postorder(root);
	destroy(root);
}
