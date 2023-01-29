/*
��Ŀ����
����һ�����������ҳ�����С��ȡ�
��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

�����ʽ
һ���ַ�����ʾ��������ÿ���ڵ���','������ ��������� "3,9,20,null,null,15,7" ��ʾ��������

�����ʽ
һ����������ʾ������ȡ�

��������
Sample Input 1
3,9,20,null,null,15,7

Sample Input 2
2,null,3,null,4,null,5,null,6

�������
Sample Output 1
2

Sample Output 2
5

���ݷ�Χ
�ڵ����������10^5���ڵ��ֵ��-1000��1000��Χ�ڡ�
*/

#include <iostream>

using namespace std;

class BTree;

class Node
{
    friend class BTree;
public:
    int data;
    int left;
    int right;
    Node(int x,int l=1001,int r=1001)
    {
        data=x;
        left=l;
        right=r;
    };
};

class BTree
{
private:
    Node *root;
    char stopFlag;
    int Size(Node<elemType> *t); //����tΪ���Ķ������Ľ�������
    int Height(Node<elemType> *t); //����tΪ���Ķ������ĸ߶ȡ�
    void DelTree(Node<elemType> *t); //ɾ����tΪ���Ķ�����
public:
    BTree()
    {
        root=NULL;
    }
    void createTree(const elemType &flag);//����һ�ö�����
    bool isEmpty()
    {
        return (root == NULL);
    } // �жϲ����Ƿ�Ϊ��
    Node<elemType> * GetRoot()
    {
        return root;
    }
    int Size (); //��������Ľ�������
    int Height (); //��������ĸ߶ȡ�
    void DelTree(); //ɾ��������
};

void BTree::createTree(int &flag) //����һ�ö�����
{
    seqQueue<Node*> que;
    int e, el, er;
    Node *p, *pl, *pr;
    stopFlag = flag;
    cout<<"Please input the root: ";
    cin>>e;
    if(e==flag)
    {
    	root = NULL;
        return;
    }
    p = new Node(e);
    root = p; //�����Ϊ���´������que.enQueue(p);
    while(!que.isEmpty())
    {
    	p = que.front(); //��ö���Ԫ�ز�����
    	que.deQueue();
    	cout<<"Please input the left child and the right child of "<<p->data<<" using "<<flag<<" as no child: ";
    	cin>>el>>er;
        if(el!=flag) //�ý��������
        {
        	pl = new Node(el);
        	p->left = pl;
        	que.enQueue(pl);
        }
        if(er!=flag) //�ý�����Һ���
        {
        	pr = new Node<elemType>(er);
        	p->right = pr;
        	que.enQueue(pr);
        }
    }
}

template <class elemType>
int BTree<elemType>::Size()
{
    return Size(root);
}
template <class elemType>
int BTree<elemType>::Size (Node<elemType> *t) //�õ���tΪ�����������������ݹ��㷨ʵ�֡�
{
    if(!t)
    {
    	return 0;
    }
    return 1+Size(t->left)+Size(t->right);
}

template <class elemType>
int BTree<elemType>::Height()
{
    return Height(root);
}
template <class elemType>
int BTree<elemType>::Height(Node<elemType> *t) //�õ���tΪ���������ĸ߶ȣ��ݹ��㷨ʵ�֡�
{
    int hl, hr;
    if(!t)
    {
    	return 0;
    }
    hl = Height(t->left);
    hr = Height(t->right);
    if(hl>=hr)
    {
    	return 1+hl;
    }
    return 1+hr;
}

template <class elemType>
void BTree<elemType>::DelTree()
{
    DelTree(root);
	root = NULL;
}
template <class elemType>
void BTree<elemType>::DelTree(Node<elemType> *t)//ɾ����tΪ���Ķ��������ݹ��㷨ʵ��
{
    if(!t)
    {
    	return;
    }
    DelTree(t->left);
    DelTree(t->right);
    delete t;
}

int main()
{
    char* str;
    Node tree[100000];
    str=new char[1000000]
    cin.getline(str,1000000,'\n');
    int i=0;
    int j=0;
    int flag==0;
    int tmp=0;
    while(str[i]!='\0')
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            if(flag==0)
            {
                tmp=0;
            }
            tmp=tmp*10+(int)(str[i]);
        }
        else if(str[i]=='n')
        {
            Node n(1001);
            tree[j]=n;
            j++;
            i=i+5;
            flag=0;
        }
        else if(str=',')
        {
            Node n(tmp);
            flag=0;
        }
    }
    BTree tree;
    tree.createTree(1001);

    return 0;
}
