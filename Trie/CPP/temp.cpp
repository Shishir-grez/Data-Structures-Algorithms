#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        next = nullptr;
    }
};

class LL
{
public:
    Node *root = nullptr;
    void insert(int data)
    {
        Node *node = root;
        Node *temp;
        if (!root)
        {
            root = new Node;
            root->data = data;
        }
        else
        {
            while (node->next != nullptr)
            {
                node = node->next;
            }
            temp = new Node;
            temp->data = data;
            node->next = temp;
        }
    }
    void print()
    {
        Node *node = root;
        while (node->next != nullptr)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << node->data << " ";
    }

    

};

int main()
{
    LL test;
    test.insert(1);
    test.insert(2);
    test.insert(3);
    test.insert(4);
    cout << endl;
    test.print();
    // test.reverse();
    return 0;
}