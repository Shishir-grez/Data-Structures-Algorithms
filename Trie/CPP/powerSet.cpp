#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    int wordEnds;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = nullptr;
            this->wordEnds = 0;
        }
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode;
    }

    void distinctSubstringGenerator(const string &word, int &result)
    {
        result = 0;
        TrieNode *node = root;
        string subStringGen = "";
        int startCounter = 0;
        for (char c : word)
        {
            subStringGen += c;
            char outerIndex = c - 'a';
            if (!node->children[outerIndex])
            {
                node->children[outerIndex] = new TrieNode;
                node->children[outerIndex]->wordEnds++;
                result++;
            }
            else
            {
                node->children[outerIndex]->wordEnds++;
                result++;
            }
            node = root;
            for (int i = startCounter + 1; i < word.length(); i++)
            {
                subStringGen += word[i];
                string temp = "";
                for (int j = 0; j < subStringGen.length(); j++)
                {
                    temp += subStringGen[j];
                    int innerIndex = subStringGen[j] - 'a';
                    if (!node->children[innerIndex])
                    {
                        node->children[innerIndex] = new TrieNode;
                        node->children[innerIndex]->wordEnds++;
                        result++;
                    }
                    else
                    {
                        node->children[innerIndex]->wordEnds++;
                        result++;
                    }
                    node = node->children[innerIndex];
                }
                node = root;
            }
            subStringGen = "";
            startCounter++;
            node = root;
        }
    }
};

int main()
{
    Trie trie;
    string word = {"abc"};
    int result;
    trie.distinctSubstringGenerator(word, result);
    cout << result /*1 represents empty string */ << endl;
    return 0;
}