/*
Description
Let G=(V,E) be an undirected, connected, weighted graph who is represented as an adjacency matrix. Find the minimum spinning tree of G. A minimum spanning tree is a least-cost subset of the edges of a graph that connects all the nodes.

Input Format
An ∣V∣×∣V∣ adjacency matrix A=(a
ij
​
 ) such that

a
ij
​
 ={
edge weight,
0,
​

if (i,j)∈E
otherwise
​


Edge weights are integers in the range of [1, 255].

Output Format
The summation of the edge weights of the minimum spinning tree.

Example
Input:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
Output:
16
*/
 // Add any standard library if needed.
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define INF 256

// Implement your minimum spinning tree algorithm

int prim(int** A, int v)
{
    int* vis=new int [v];

    for(int i=0;i<v;i++)
    {
        vis[i]=0;
    }

    vis[0] = 1;
    int sum = 0;
    int minE;
    int s,e;
    int flag;
    vector<int> intree;
    intree.push_back(0);
    int n=1;

    do
    {
        flag=0;
        minE = INF;
        for(int i = 0;i < n;i++)
        {
            s = intree[i];
            for(int j = 0;j < v;j++)
            {
                if(vis[j] == 0 && A[s][j] < minE)
                {
                    e = j;
                    minE = A[s][j];
                }
            }
        }

        sum += minE;
        vis[e] = 1;
        intree.push_back(e);

        n = intree.size();
        if(n != v)
        {
            flag = 1;
        }

    }while(flag);

    return sum;
}

// Test your implementation
int main()
{
    string str;
    getline(cin,str);
    stringstream input(str);

    vector<int> G_elems;
    int a;
    while(input >> a)
    {
        if(a==0)
        {
            a=INF;
        }
        G_elems.push_back(a);
    }

    int v=G_elems.size();

    for(int i=1;i<v;i++)
    {
        string str;
        getline(cin, str);
        stringstream input(str);

        int a;

        while(input >> a)
        {
            if(a==0)
            {
                a=INF;
            }
            G_elems.push_back(a);
        }
    }

    int **A = new int* [v];

    for(int i=0;i<v;i++)
    {
        A[i]=new int [v];
    }

    int m=0;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            A[i][j] = G_elems[m++];
        }
    }

    /*
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
    */

    int minEsum=prim(A,v);

    cout<<minEsum;

    //system("pause");

    return 0;
}
