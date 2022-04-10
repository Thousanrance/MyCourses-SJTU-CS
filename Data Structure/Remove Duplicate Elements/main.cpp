/*
Description
Given a linked list, remove the duplicate elements so that no neighboring elements are the same.
There are three types of elements:
0: int
1: char (lower and upper case character) 2: string (const char *)
Please use Class Template to implement the LinkedNode class.
Also, your code are required to avoid memory lead.
(TAs will check your code, so solutions without class template cannot get full score)
Tip: to compare the different types, you may need Overloaded Functions. or Template Functions.
If you have forgotten this knowledge, please refer to your programming textbook.

Permissible libraries:
iostream
cstdio
cstring
cmath

Input Format
Line 1: two numbers
k
 and
n
Line 2:
n
 elements of type
k
Output Format
Line 1: elements of the processed linked list, separated by space.

Input Sample 1
0 5

1 2 2 4 4

Output Sample 1
1 2 4

Input Sample 2
2 6

cat dog dog dog fish fish

Output Sample 2
cat dog fish

Limits
k = 0, 1, 2​

1 <= n <= 100000​

1 <= int elements <= 100000​

1 <= length of string <= 10
*/

//逻辑：
//1、把第一个数据插到第一位；
//2、下一个数据如果与第一位的数据不同，就插在第一位；
//3、插入完成后将链表就地倒置；
//4、遍历输出。

#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class LinkedNode
{
private:
    struct node
    {
        T data;
        node* next;
        node(const T &x, node *p = NULL)
        {
            data = x;
            next = p;
        }
        node():next(NULL){}
        ~node(){}
    };
    node* head;
public:
    LinkedNode();
    ~LinkedNode()
    {
        clearr();
        delete head;
    }
    bool visit(const char *x)const;
    bool searchh(const T &x)const;
    void insertt(const T &x);
    void clearr();
    void reversee();
    void traverse()const;
};

template <class T>
LinkedNode<T>::LinkedNode()
{
    head=new node();
    //cout<<"create over!"<<endl;
}

template <class T>
bool LinkedNode<T>::visit(const char *x)const
{
    //cout<<"Enter the Function:visit"<<endl;
    if(head->next==NULL)
    {
        return false;
    }
    if(strcmp(head->next->data,x)==0)
    {
        return true;
    }
    return false;
}

template <class T>
bool LinkedNode<T>::searchh(const T &x)const
{
    //cout<<"Enter the Function:searchh"<<endl;
    //cout<<"x="<<x<<endl;
    if(head->next==NULL)
    {
        return false;
    }
    if(head->next->data==x)
    {
        return true;
    }
    return false;
}

template <class T>
void LinkedNode<T>::insertt(const T &x)
{
    //cout<<"Enter the Function:insertt"<<endl;
    //cout<<"inserting:"<<x<<endl;
    node* p=new node (x,head->next);
    head->next=p;
    //cout<<"inserted:"<<p->next->data<<endl;
}

template <class T>
void LinkedNode<T>::clearr()
{
    node *p,*q;
    p=head->next;
    head->next=NULL;
    while(p)
    {
        q=p->next;
        delete p;
        p=q;
    }
}

template <class T>
void LinkedNode<T>::reversee()
{
    //cout<<"Enter the Function:reversee"<<endl;
    node *p, *q;
    p=head->next;
    head->next=NULL;
    while(p)
    {
        q=p->next;
        p->next=head->next;
        head->next=p;
        p=q;
    }
}

template <class T>
void LinkedNode<T>::traverse()const
{
    //cout<<"Enter the Function:traverse"<<endl;
    node* p=head->next;
    while(p)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
}

int main()
{
    int k,n;
    cin>>k>>n;
    //cin.ignore();

    if(k==0)
    {
        LinkedNode<int> output;
        for(int i=0;i<n;i++)
        {
            int* input=new int;
            cin>>*input;
            if(!output.searchh(*input))
            {
                output.insertt(*input);
            }
            delete input;
        }
        output.reversee();
        output.traverse();
    }
    else if(k==1)
    {
        LinkedNode<char> output;
        for(int i=0;i<n;i++)
        {
            char* input=new char;
            cin>>*input;
            if(!output.searchh(*input))
            {
                output.insertt(*input);
            }
            delete input;
        }
        output.reversee();
        output.traverse();
    }
    else if(k==2)
    {
        LinkedNode<char*> output;
        cin.ignore();
        for(int i=0;i<n;i++)
        {
            char* input=new char[10];
            if(i<n-1)
            {
                cin.getline(input,10,' ');
            }
            else
            {
                cin.getline(input,10,'\n');
            }
            if(!output.visit(input))
            {
                output.insertt(input);
            }
        }
        output.reversee();
        output.traverse();
    }
    return 0;
}
