#include<iostream>
using namespace std;


class TrieNode{
    public:
        TrieNode *children[26];
        bool isEnds = false;

        TrieNode(){
        for (int i = 0; i < 26; i ++)
        {
            children[i] = nullptr;
        }
}
};

class Trie{
    public:
        TrieNode *root;
        Trie()
        {
            root = new TrieNode;
        }
        void insert(const string letter)
        {
            TrieNode *node = root;

            for (char c:letter)
            {
                int index = c - 'a';
                if(!node->children[index])
                {
                    node->children[index] = new TrieNode;
                }
                node = node->children[index];
            }
            node->isEnds = true;
        }
};