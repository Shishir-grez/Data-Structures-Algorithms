#include <iostream>
#include <stdio.h>
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

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int data)
    {
        if (!head)
        {
            head = new Node;
            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node;
            temp = temp->next;
            temp->data = data;
            temp->next = nullptr;
        }
    }

    int findmiddle()
    {
        Node *first = head;
        Node *second = head;

        while (second->next != nullptr)
        {
            if (second->next->next == nullptr)
            {
                return first->next->data;
            }
            second = second->next->next;
            first = first->next;
        }
        return first->data;
    }
};
int main()
{
    LinkedList a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    // a.insert(6);

    cout << a.findmiddle();

    return 0;
}