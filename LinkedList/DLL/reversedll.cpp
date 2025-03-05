#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *front;
    Node *back;
    Node()
    {
        front = nullptr;
        back = nullptr;
    }
};

class LL
{
public:
    Node *root = nullptr;

    void insert(int data)
    {
        Node *node = root;
        if (root == nullptr)
        {
            root = new Node;
            root->data = data;
            root->back = nullptr;
            root->front = nullptr;
        }
        else
        {
            while (node->front != nullptr)
            {
                node = node->front;
            }
            node->front = new Node;
            node->front->data = data;
            node->front->front = nullptr;
            node->front->back = node;
        }
    }

    void print()
    {
        Node *node = root;
        while (node!=nullptr)
        {
            cout << node->data << " ";
            node = node->front;
        }
    }

    void reverse()
    {
        Node *node;

        // Insert a dummy Node at the start
        Node *temp_node = new Node;
        temp_node->data = -1;
        temp_node->front = root;
        temp_node->back = nullptr;
        node = temp_node;

        while(node->front!=nullptr)
        {
            node->front->back = node->front->front;
            node->front->front = node;
            node = node->front;
        }
        node->front = node->back;
        node->back = nullptr;

        while(node->data != -1)
        {
            cout << node->data << " ";
            node = node->front;
        }
    }
};

int main()
{
    LL list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.print();
    list.reverse();
    return 0;
}