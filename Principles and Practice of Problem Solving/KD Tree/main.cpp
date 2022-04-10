/*
Problem Description
Implement a k-d Tree(in this problem k=2) and support the following operations:

insert: Insert a new node with key into the k-d tree.
search: Search the node with the given key.
remove: Remove the node with the given key.
findMin: Find the node with minimum value given the dimension.
rangeSearch: x
min
​
 ,x
max
​
 ,y
min
​
 ,y
max
​
  will be given. Count the nodes whose keys are within the given range(closed).
Examples
Input:
9
insert 1 1 1
insert 3 4 2
insert 6 5 3
findMin 1
rangeSearch 2 8 0 6
search 6 5
remove 3 4
rangeSearch 2 8 0 6
search 3 4
Output:
1 # Key (1,1) has the minimum value in dimension 1 (min(1,4,5))
2 # Key (3,4) and Key (6,5) are in the rectangle [2,8] [0,6]
3 # Key (6,5) has value 3
1 # Key (6,5) is in the rectangle [2,8] [0,6] ((3,4) has been removed)
NULL # Key (3,4) has been removed
Note
Keys are integer pairs, such as (1,2),(5,11).
It would be helpful to refer to our slide Lecture 12-Data Structures Recap (3).
*/
#include <iostream>
#include <cstring>
using namespace std;

struct Item
{
    int key[2];
    int value;
};

class Node
{
public:
    Node *left, *right;
    Item item;

    Node(Item _item): item(_item), left(NULL), right(NULL) {}
};

void insert(Node *&root, Item item, int dim)
{
    //TODO
    if(root == NULL)
    {
        root = new Node(item);
        //cout<<&root<<endl;
        return;
    }
    if(item.key[0]==root->item.key[0]&&item.key[1]==root->item.key[1])
    {
        return;
    }
    if(item.key[dim]<root->item.key[dim])
    {
        insert(root->left,item,(dim+1)%2);
    }
    else
    {
        insert(root->right,item,(dim+1)%2);
    }
}

// If the queried key doesn't exist, return NULL.
Node *search(Node *root, int key[2], int dim)
{
    //TODO
    if(root==NULL)
    {
        cout<<"search null"<<endl;
        return NULL;
    }
    if(key[0]==root->item.key[0]&&key[1]==root->item.key[1])
    {
        cout<<&root<<endl;
        cout<<root->item.value<<endl;
        return root;
    }
    if(key[dim]<root->item.key[dim])
    {
        cout<<"flag1"<<endl;
        return search(root->left,key,(dim+1)%2);
    }
    if(key[dim]>root->item.key[dim])
    {
        cout<<"flag2"<<endl;
        return search(root->right,key,(dim+1)%2);
    }
    return NULL;
}

// Find the minimum value in a dimension(dimCmp)
Node* minNode(Node* n1,Node* n2,int dim)
{
    if(n1==NULL&&n2==NULL)
    {
        return NULL;
    }
    else if(n1==NULL)
    {
        return n2;
    }
    else if(n2==NULL)
    {
        return n1;
    }
    else
    {
        if(n1->item.key[dim]<n2->item.key[dim])
        {
            //cout<<n1->item.value<<endl;
            return n1;
        }
        else
        {
            //cout<<n2->item.value<<endl;
            return n2;
        }
    }
}

Node *findMin(Node *root, int dimCmp, int dim)
{
    //TODO
    if(!root)
    {
        return NULL;
    }
    Node *minn=findMin(root->left,dimCmp,(dim+1)%2);
    if(dimCmp!=dim)
    {
        Node* rightMin=findMin(root->right,dimCmp,(dim+1)%2);
        minn=minNode(minn,rightMin,dimCmp);
    }
    return minNode(minn,root,dimCmp);
}

//remove

Node* maxNode(Node* n1,Node* n2,int dim)
{
    if(n1==NULL&&n2==NULL)
    {
        return NULL;
    }
    else if(n1==NULL)
    {
        return n2;
    }
    else if(n2==NULL)
    {
        return n1;
    }
    else
    {
        if(n1->item.key[dim]>n2->item.key[dim])
        {
            //cout<<n1->item.value<<endl;
            return n1;
        }
        else
        {
            //cout<<n2->item.value<<endl;
            return n2;
        }
    }
}

Node* findMax(Node* root,int dimCmp,int dim)
{
    if(!root)
    {
        return NULL;
    }
    Node* maxn=findMax(root->right,dimCmp,(dim+1)%2);
    if(dimCmp!=dim)
    {
        Node* leftMax=findMax(root->left,dimCmp,(dim+1)%2);
        maxn=maxNode(maxn,leftMax,dimCmp);
    }
    return maxNode(maxn,root,dimCmp);
}

void remove(Node *&root, int key[2], int dim)
{
    //TODO
    if(!root)
    {
        return;
    }
    if(key[0]==root->item.key[0]&&key[1]==root->item.key[1])
    {
        if (root->left==NULL&&root->right==NULL)
        {
            delete root;
            root = NULL;
            return;
        }
        if(root->right)
        {
            Node* tmp=findMin(root->right,dim,(dim+1)%2);
            root->item=tmp->item;
            remove(root->right,tmp->item.key,(dim+1)%2);
            return;
        }
        else
        {
            Node* tmp=findMax(root->left,dim,(dim+1)%2);
            root->item = tmp->item;
            remove(root->left,tmp->item.key,(dim+1)%2);
            return;
        }
    }
    if(key[dim]<root->item.key[dim])
    {
        remove(root->left,key,(dim+1)%2);
    }
    else
    {
        remove(root->right,key,(dim+1)%2);
    }
}

// searchRange contains 4 values [x_min, x_max, y_min, y_max]
// Our test program will call this function with dim=0 treeRange={-9999, 9999, -9999, 9999}
int rangeSearch(Node *root, int dim, int searchRange[4], int treeRange[4])
{
    //TODO
    if(!root)
    {
        //cout<<"null"<<endl;
        return 0;
    }
    if(treeRange[dim*2+1]<searchRange[dim*2]||treeRange[dim*2]>searchRange[dim*2+1])
    {
        //cout<<"end compare"<<endl;
        return 0;
    }

    int ltreeRange[4];
    for(int i=0;i<4;i++)
    {
        ltreeRange[i]=treeRange[i];
    }
    ltreeRange[dim*2+1]=root->item.key[dim];

    int rtreeRange[4];
    for(int i=0;i<4;i++)
    {
        rtreeRange[i]=treeRange[i];
    }
    rtreeRange[dim*2]=root->item.key[dim];

    if(root->item.key[0]>=searchRange[0]&&root->item.key[0]<=searchRange[1]&&root->item.key[1]>=searchRange[2]&&root->item.key[1]<=searchRange[3])
    {
        //cout<<&root<<endl;
        //cout<<root->item.value<<endl;
        return 1+rangeSearch(root->left,(dim+1)%2,searchRange,ltreeRange)+rangeSearch(root->right,(dim+1)%2,searchRange,rtreeRange);
    }
    else
    {
        //cout<<"out of range"<<endl;
        //cout<<root->item.value<<endl;
        //cout<<root->item.key[0]<<endl;
        //cout<<root->item.key[1]<<endl;
        return rangeSearch(root->left,(dim+1)%2,searchRange,ltreeRange)+rangeSearch(root->right,(dim+1)%2,searchRange,rtreeRange);
    }
}

int main()
{
    int num=1000;
    Node* root=NULL;
    int treeRange[4]={-9999,9999,-9999,9999};

    while(num--)
    {
        char* order;
        cin.getline(order,12,' ');
        //cout<<order;
        if(!strcmp(order,"insert"))
        {
            //cout<<"1"<<endl;
            int key1,key2,value;
            cin>>key1>>key2>>value;
            cin.ignore();
            Item it;
            it.key[0]=key1;
            it.key[1]=key2;
            it.value=value;
            insert(root,it,0);
        }
        if(!strcmp(order,"search"))
        {
            //cout<<"2"<<endl;
            int key1,key2;
            cin>>key1>>key2;
            cin.ignore();
            int key[2];
            key[0]=key1;
            key[1]=key2;
            Node* res=search(root,key,0);
            if(res==NULL)
            {
                cout<<"NULL"<<endl;
            }
            else
            {
                cout<<"search:"<<res->item.value<<endl;
            }

        }
        if(!strcmp(order,"remove"))
        {
            int key1,key2;
            cin>>key1>>key2;
            cin.ignore();
            int key[2];
            key[0]=key1;
            key[1]=key2;
            remove(root,key,0);
            continue;
        }
        if(!strcmp(order,"findMin"))
        {
            int dimcmp;
            cin>>dimcmp;
            cin.ignore();
            Node* minnode=findMin(root,dimcmp,0);
            cout<<"findMin:"<<minnode->item.value<<endl;

        }
        if(!strcmp(order,"rangeSearch"))
        {
            int xmin,xmax,ymin,ymax;
            cin>>xmin>>xmax>>ymin>>ymax;
            cin.ignore();
            int searchrange[4];
            searchrange[0]=xmin;
            searchrange[1]=xmax;
            searchrange[2]=ymin;
            searchrange[3]=ymax;
            int cnt=rangeSearch(root,0,searchrange,treeRange);
            cout<<"rangeSearch:"<<cnt<<endl;

        }
    }

    system("pause");

    return 0;
}
