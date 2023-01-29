#include<iostream>
using namespace std;

class ABTree
{
private:
   int* array;
   int size;
public:
    ABTree(int a[],int n)
    {
        array=new int[n+1];
        size=n;
        for(int i=0;i<n;i++)
        {
            array[i+1]=a[i];
        }
    }
    void preorder()
    {
        preorder(1);
    }
    void inorder()
    {
        inorder(1);
    }
    void postorder()
    {
        postorder(1);
    }
    ~ABTree()
    {
        delete [] array;
    }
private:
    void preorder(int root)
    {
        if(root>size)
        {
            return;
        }
        cout<<array[root];
        preorder(root*2);
        preorder(root*2+1);
    }
    void inorder(int root)
    {
        if(root>size)
        {
            return;
        }
        inorder(root*2);
        cout<<array[root];
        inorder(root*2+1);
    }
    void postorder(int root)
    {
        if(root>size)
        {
            return;
        }
        postorder(root*2);
        postorder(root*2+1);
        cout<<array[root];
    }
};

int main()
{
    return 0;
}
