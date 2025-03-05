#include <iostream>
#include <stdio.h>
using namespace std;

class TrieNode{
    public:
        TrieNode *children[26];
        int endOfWord;
        int wordCount;

        TrieNode()
        {
            for (int i = 0; i < 26;i++)
            {
                this->children[i] = nullptr;
            }
            endOfWord = 0;
            wordCount = 0;
        }
};

class Trie{
    public:
        TrieNode *root;
        Trie(){
            root = new TrieNode;
        }
        
        void insert(const string& word)
        {
            TrieNode *node = root;
            for(char c : word)
            {
                int index = c - 'a';
                if(!node->children[index])
                {
                    node->children[index] = new TrieNode;
                }
                node->children[index]->wordCount++;
                node = node->children[index];
            }
            node->endOfWord++;
        }

        int countWordEqualTo(const string& word)
        {
            TrieNode *node = root;
            for(char c : word){
                int index = c - 'a';
                if(!node->children[index])
                {
                    return 0;
                }
                node = node->children[index];
            }
            return node->endOfWord;
        }

        int countWordsStartingWith(const string &prefix)
        {
            TrieNode *node = root;
            for (char c : prefix)
            {
                int index = c - 'a';
                if (!node->children[index])
                {
                    return 0;
                }
                node = node->children[index];
            }
            return node->wordCount;
        }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    trie.insert("appetite");

    cout << "Count of word 'app': " << trie.countWordEqualTo("app") << endl;                            // Expected: 1
    cout << "Count of word 'apple': " << trie.countWordEqualTo("apple") << endl;                        // Expected: 1
    cout << "Count of words starting with 'app': " << trie.countWordsStartingWith("app") << endl;       // Expected: 4
    cout << "Count of words starting with 'appl': " << trie.countWordsStartingWith("appl") << endl;     // Expected: 2
    cout << "Count of words starting with 'banana': " << trie.countWordsStartingWith("banana") << endl; // Expected: 0

    return 0;
}