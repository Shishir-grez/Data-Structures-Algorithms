#include <iostream>
using namespace std;

// Definition for a single node in the linked list
class Node
{
public:
    int data;
    Node *next;
    // Constructor to initialize node
    Node(int val)
    { 
        data = val;
        next = nullptr;
    }
};

// Linked List class with basic operations
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Traversing the list and printing its elements
    void traverse()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Insert at the beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a given position (0-based index)
    void insertAtPosition(int value, int position)
    {
        if (position == 0)
        {
            insertAtBeginning(value);
            return;
        }
        Node *newNode = new Node(value);
        Node *temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; ++i)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Position out of bounds" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from the beginning
    void deleteFromBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete from a specific position (0-based index)
    void deleteFromPosition(int position)
    {
        if (position == 0)
        {
            deleteFromBeginning();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; ++i)
        {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Search for a value in the list
    bool search(int value)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Find the length of the list
    int getLength()
    {
        int length = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            ++length;
            temp = temp->next;
        }
        return length;
    }

    // Reverse the linked list
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

// Main function to demonstrate the operations
int main()
{
    LinkedList list;

    // Inserting elements
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.traverse(); // 1 -> 2 -> 3 -> NULL

    // Inserting at beginning
    list.insertAtBeginning(0);
    list.traverse(); // 0 -> 1 -> 2 -> 3 -> NULL

    // Inserting at position
    list.insertAtPosition(5, 2);
    list.traverse(); // 0 -> 1 -> 5 -> 2 -> 3 -> NULL

    // Deleting elements
    list.deleteFromBeginning();
    list.traverse(); // 1 -> 5 -> 2 -> 3 -> NULL

    list.deleteFromEnd();
    list.traverse(); // 1 -> 5 -> 2 -> NULL

    list.deleteFromPosition(1);
    list.traverse(); // 1 -> 2 -> NULL

    // Searching for an element
    cout << (list.search(2) ? "Found" : "Not Found") << endl; // Found

    // Reversing the list
    list.reverse();
    list.traverse(); // 2 -> 1 -> NULL

    return 0;
}
