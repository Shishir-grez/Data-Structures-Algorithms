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
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }

    void reverse()
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next = nullptr;

        while (curr!= nullptr)
        {
            next = curr->next; // easily understandble using diagram
            curr->next = prev; // Flip current node
            prev = curr; // Next position pe move kro
            curr = next;
        }

        head = prev;
        Node *temp = new Node;
        temp = head;

        while(temp->next != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data;
    }


};

int main()
{
    LinkedList a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.print();
    a.reverse();
    return 0;
}