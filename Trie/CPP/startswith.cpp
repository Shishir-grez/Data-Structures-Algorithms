#include <iostream>
#include <stdio.h>
#include <chrono>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26]; // A child of type TrieNode for each alphabet
    bool isEndsWith;        // To check if the word end at the current child ?
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = nullptr; // Set all children to nullptr to save memory
        }
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode;
    }

    void insert(const string &word) // Const add for :- 1) Copy by refrence 2) Does not modify the actual paramter 3) Standard practise
    {
        TrieNode *node = root;

        for (char c : word)
        {
            int index = c - 'a'; // Get the ascii difference

            if (!node->children[index])
            {
                node->children[index] = new TrieNode; // if Node does not exist create a new node
            }
            node = node->children[index]; // If it does exist traverse to its child element
        }
        node->isEndsWith = true;
    }

    bool search(const string &word)
    {
        TrieNode *node = root;

        for (char c : word)
        {
            int index = c - 'a';
            if (!node->children[index])
            {
                return false; // The word does not exists in your tree
            }
            node = node->children[index];
        }
        return true;
    }

    bool startsWith(const string &prefix)
    {
        TrieNode *node = root;
        for (char c : prefix)
        {
            int index = c - 'a';
            if (!node->children[index])
            {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    Trie trie;
    trie.insert("hello");
    trie.insert("hell");
    trie.insert("heaven");
    trie.insert("goodbye");

    std::cout << "Search 'hello': " << trie.search("hello") << std::endl;
    std::cout << "Search 'hell': " << trie.search("hell") << std::endl;
    std::cout << "Search 'heaven': " << trie.search("heaven") << std::endl;
    std::cout << "Search 'good': " << trie.search("good") << std::endl;

    std::cout << "Starts with 'he': " << trie.startsWith("he") << std::endl;
    std::cout << "Starts with 'go': " << trie.startsWith("go") << std::endl;
    std::cout << "Starts with 'hel': " << trie.startsWith("hel") << std::endl;
    std::cout << "Starts with 'good': " << trie.startsWith("good") << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}