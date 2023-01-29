/*
Problem Description
Implement a Trie(prefix tree) and support the following operations:

insert: insert a string into the Trie.
search: return true if the queried string has been inserted into the Trie.
startsWith: return true if there is any string in the Trie that starts with the given prefix.

Examples
Input:
4
insert abc
search abc
search ab
startsWith ab

Output:
True
False
True

Note
You may assume that all strings in the test cases consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
A word is a prefix of itself. (apple startsWith apple)
*/

// You can add any members in the class.
// The following 4 functions will be called in test program.
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Trie
{
private:
    vector<Trie*> kids;
    bool isEnd;

    Trie* searchPrefix(char* prefix)
    {
        Trie* node=this;

        int len=strlen(prefix);
        for(int i=0;i<len;i++)
        {
            char ch=prefix[i];
            ch-='a';
            if(node->kids[ch]==nullptr)
            {
                return nullptr;
            }
            node = node->kids[ch];
        }
        return node;
    }

public:
    Trie():kids(26),isEnd(false)
    {
        // TODO
    }

    void insert(char* word)
    {
        // TODO
        Trie* node=this;

        int len=strlen(word);
        for(int i=0;i<len;i++)
        {
            char ch=word[i];
            ch-='a';
            if(node->kids[ch]==nullptr)
            {
                node->kids[ch]=new Trie();
            }
            node=node->kids[ch];
        }
        node->isEnd=true;
    }

    bool search(char* word)
    {
        // TODO
        Trie* node=this->searchPrefix(word);
        return node!=nullptr&&node->isEnd;
    }

    bool startsWith(char* prefix)
    {
        // TODO
        return this->searchPrefix(prefix)!=nullptr;
    }
};
