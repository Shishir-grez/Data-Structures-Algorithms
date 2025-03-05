#include <iostream>
using namespace std;

class TrieNode{
    public:
        TrieNode *children[26]; // A child of type TrieNode for each alphabet
        bool isEndsWith; // To check if the word end at the current child ?
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                this->children[i] = nullptr;
            }
        }
};

class Trie{
    private:
        TrieNode *root;

    public:
        Trie()
        {
            root = new TrieNode;
        }

};

int main(){
    
    return 0;
}