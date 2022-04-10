/*
Cuckoo Hashing
We will implement Cuckoo Hashing here, which is a simple hash table with worst-case O(1) lookups and deletions.

Cuckoo Hashing maintains two tables, each of which has m elements. Given an array X⊂N
+
 , each element x∈X will either be at position h
1
​
 (x) in the first table or h
2
​
 (x) in the second, where h
1
​
 :N
+
 →{0,1,…,m−1} and h
2
​
 :N
+
 →{0,1,…,m−1} are hash functions we selected.

If element x already exists at place h
1
​
 (x) in table 1 or place h
2
​
 (x) in table 2, then return. Otherwise to insert an element x, we start by inserting it into table 1. If h
1
​
 (x) is empty, then place x there. Otherwise, place x there and evict the old element y, and try placing y into table 2. Repeat this process bouncing between tables, until all elements stabilize. You are required to output the final two stable hashtables.

Note that insertion may fail if we run into a cycle. If that happens, we usually perform a rehash by choosing a new h
1
​
  and h
2
​
  and inserting all elements again. Usually multiple rehashes might be necessary before success. But here in this problem, you can just output Failed! when face the cycle.

Note
To make life easier, we simplify the problem as follows:

The hash functions are given already, do not change them! (m is related with hash functions.)
If we have array X with size n as input, then m will set to be n+1.
Elements are all positive integers (and ≤1000), and the input array has size smaller than 100.
Finish the codes in place() function.
The first line in input refers to the size of input array, the second line refers to the array. However it seems that the educoder site just ignores the line-separators in the input and mixes the two lines together. Anyway you only need to know that the first number refers to the array size and not the actual element in the array, since the input function is already given.
Example1
Input:
10
20 50 53 75 100 67 105 3 36 39
Output:
- 100 - 36 - - 50 - - 75 -
3 20 - 39 53 - 67 - - 105 -
Explanations:
The first line in input refers to the size of input array; - in output refers to the place is empty.
Hash Functions:
h
1
​
 (x)=x%11
h
2
​
 (x)=(x/11)%11

Then the mapping table:

,

After inserting 20:ch2

Next 50:

 ch3

Next 53. h1(53)=9, so we place 53 in table 1 at place 9, and place 20 at h2(20) = 1 in table 2.

 ch4

Next 75. h1(75)=9, so we place 75 in table 1 at place 9, and place 53 at h2(53) = 4 in table 2.

 ch6

...Finally we can reach the final tables:

 ch12

Example2
Input:
10
6 15 15 2 20 9 7 5 13 18
Output:
Failed!
Explanations:

During the process we will face a cycle and fail.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

// upper bound on hashtable size
#define MAXN 101
// actual used hashtable size
int m;

// number of tables
#define ver 2

int hashtable[ver][MAXN];

// possible positions for a key
int pos[ver];

/* function to fill hash table with dummy value
* dummy value: -1
* number of hashtables: ver */
void initTable()
{
	for (int j=0; j<MAXN; j++)
		for (int i=0; i<ver; i++)
			hashtable[i][j] = -1;
}

/* return hashed value for a key
* function: ID of hash function
* key: item to be hashed */
int myhash(int function, int key, int n)
{
	switch (function)
	{
		case 1: return key%m;
		case 2: return (key/m)%m;
	}
}

void place(int key, int tableID, int cnt, int n)
{
	//code here
	if(key==hashtable[0][myhash(1,key,n)]||key==hashtable[1][myhash(2,key,n)])
    {
        return;
    }
	while(cnt<=2*m)
    {
        //cout<<"key="<<key<<endl;
        tableID=cnt%2+1;
        //cout<<"tableID="<<tableID<<endl;
        int tmppos=myhash(tableID,key,n);
        if(hashtable[tableID-1][tmppos]==-1)
        {
            hashtable[tableID-1][tmppos]=key;
            //cout<<"insert "<<key<<" in hashtable["<<tableID<<"]"<<"["<<tmppos<<"]"<<endl;
            return;
        }
        else
        {
            //cout<<"else"<<endl;
            cnt++;
            int tmpy=hashtable[tableID-1][tmppos];
            //cout<<"tmpy="<<tmpy<<endl;
            hashtable[tableID-1][tmppos]=key;
            //cout<<"insert "<<key<<" in hashtable["<<tableID<<"]"<<"["<<tmppos<<"]"<<endl;
            key=tmpy;
        }
        //system("pause");
    }
    cout<<"Failed!"<<endl;
    exit(1);
}

/* function to print hash table contents */
void printTable(int n)
{
	for (int i=0; i<ver; i++, std::cout<<endl)
		for (int j=0; j<m; j++)
			(hashtable[i][j]==-1)? std::cout<<"- ":
					std::cout<<hashtable[i][j]<<" ";

}

/* function for Cuckoo-hashing keys
* keys[]: input array of keys
* n: size of input array */
void cuckoo(int keys[], int n)
{
	//init
	initTable();

	// start with placing every key at its position in
	// the first hash table according to first hash
	// function
	for (int i=0, cnt=0; i<n; i++, cnt=0)
		place(keys[i], 0, cnt, n);

	//print the final hash tables
	printTable(n);
}

int main()
{
	int keys_1[MAXN];
    //input array size
    int n;
	std::cin >> n;
    //m in hash function
	m = n + 1;
	int i=0;
    while(i < n)
    {
		std::cin >> keys_1[i++];
    }
	cuckoo(keys_1, n);

	return 0;
}
