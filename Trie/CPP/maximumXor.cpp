#include <iostream>
#include <cmath>
using namespace std;

class TreeNode
{
public:
    TreeNode *children[2];
    int numEnds;
    TreeNode()
    {
        for (int i = 0; i < 2; i++)
        {
            this->children[i] = nullptr;
            this->numEnds = 0;
        }
    }
};

class Tree
{
public:
    TreeNode *root;
    Tree()
    {
        root = new TreeNode;
    }
    // Lets use 8 bit representation for this question

    // Insert single element using Insert function
    void insert(const int &element)
    {
        TreeNode *node = root;
        int totalBits = sizeof(int) * 8; // This right here is 32 bytes
        bool currElementInBits[32];

        // Convert element in bit representation
        for (int i = totalBits - 1; i >= 0; i--)
        {
            if (((element >> i) & 1) == 0)
            {
                currElementInBits[i] = false;
            }
            else
            {
                currElementInBits[i] = true;
            }
        }
        for (int i = totalBits - 1; i >= 0; i--)
        {
            bool currValue;
            if (currElementInBits[i] == false)
            {
                currValue = false;
            }
            else
            {
                currValue = true;
            }

            if (currValue) // true condition
            {
                if (!node->children[1])
                {
                    node->children[1] = new TreeNode;
                }
                node = node->children[1];
            }
            else
            {
                if (!node->children[0])
                {
                    node->children[0] = new TreeNode;
                }
                node = node->children[0];
            }
        }
        node->numEnds++;
    }

    void print()
    {
        TreeNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            if (node->children[0])
            {
                cout << 0 << " ";
                node = node->children[0];
            }
            if (node->children[1])
            {
                cout << 1 << " ";
                node = node->children[1];
            }
        }
    }

    void calculateMaxXor(const int &elementFromArray, int &maxXorValue)
    {
        TreeNode *node = root;
        int numBits = sizeof(int) * 8;
        bool currElementInBits[32];
        bool bestXorBuddy[32];
        // Convert element in bit representation
        for (int i = numBits - 1; i >= 0; i--)
        {
            if (((elementFromArray >> i) & 1) == 0)
            {
                currElementInBits[i] = false;
            }
            else
            {
                currElementInBits[i] = true;
            }
        }

        for (int i = 31; i >= 0; i--)
        {
            if (currElementInBits[i] == false) // if Bit is zero
            {
                if (node->children[1])
                {
                    bestXorBuddy[i] = true;
                    node = node->children[1];
                }
                else
                {
                    bestXorBuddy[i] = false;
                    node = node->children[0];
                }
            }
            else // if bit is one
            {
                if (node->children[0])
                {
                    bestXorBuddy[i] = false;
                    node = node->children[0];
                }
                else
                {
                    bestXorBuddy[i] = true;
                    node = node->children[1];
                }
            }
        }

        // We do the xor of currElementInBits and bestXorBuddy
        bool xorValueBits[32];

        for (int i = 31; i >= 0; i--)
        {
            xorValueBits[i] = currElementInBits[i] ^ bestXorBuddy[i];
        }

        // Convert the bits value to integer

        int tempXorMax = 0;

        for (int i = 31; i >= 0; i--)
        {
            if (xorValueBits[i] == true)
            {
                tempXorMax += pow(2, i);
            }
        }

        if (tempXorMax > maxXorValue)
        {
            maxXorValue = tempXorMax;
        }
    }
};

int main()
{
    Tree tree;
    int maxXor = 0;
    int testArray[5] = {1024, 2048, 4096, 8192};

    for (int i = 0; i < 5; i++)
    {
        tree.insert(testArray[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        tree.calculateMaxXor(testArray[i], maxXor);
    }

    cout << maxXor << " ";

    return 0;
}