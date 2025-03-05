#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    int wordsEnd;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = nullptr;
            this->wordsEnd = 0;
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

    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (!node->children[index])
            {
                node->children[index] = new TrieNode;
            }
            node = node->children[index];
        }
        node->wordsEnd++;
    }

    bool completeStringCheck(const string &word)
    {
        TrieNode *node = root;
        bool completeStringCheck;
        string check_prefix = "";
        int temp_counter = 0;
        for (char c : word)
        {
            check_prefix += c;
            for (int i = 0; i < check_prefix.length(); i++)
            {
                char curr_char = check_prefix[i];
                int index = curr_char - 'a';
                if (!node->children[index])
                {
                    return false;
                }
                else
                {
                    if (!(node->children[index]->wordsEnd > 0))
                    {
                        return false;
                    }
                    completeStringCheck = true;
                }
                node = node->children[index];
            }
            node = root; // Most important bit , set the node to root again
        }
        return completeStringCheck;
    }

    void arrayForCompleteStrings(vector<string> input, vector<string> &output, string &result)
    {
        vector<string>::iterator i;
        vector<string> temp; // For filtering using maxLength

        int maxLength = 0;
        int tempLength = 0;

        // Check for complete string and add to temp array
        for (i = input.begin(); i < input.end(); i++)
        {
            if (completeStringCheck(*i))
            {
                temp.push_back(*i);
            }
        }

        // Check for maxLength
        for (i = temp.begin(); i < temp.end(); i++)
        {

            tempLength = (*i).length();
            if (tempLength > maxLength)
            {
                maxLength = tempLength;
            }
        }

        // Sorting using maxLength
        for (i = temp.begin(); i < temp.end(); i++)
        {

            if ((*i).length() == maxLength)
            {
                output.push_back(*i);
            }
        }

        // Lexographical Sorting
        int minLexIndex = 0;
        int tempIndex = 0;
        for (i = output.begin(); i < output.end(); i++)
        {
            if ((*i) < output[minLexIndex])
            {

                minLexIndex = tempIndex;
            }
            tempIndex++;
        }
        result = output[minLexIndex];
    }   
};

int main()
{
    Trie trie;
    vector<string> words = {"a", "ab", "ac", "abc", "acd"};
    int input_length = words.size();
    vector<string> completeWords = {};
    string result;

    for (const string &word : words)
    {
        trie.insert(word);
    }
    trie.arrayForCompleteStrings(words, completeWords, result);

    cout << result;
    return 0;
}