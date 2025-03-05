#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Create / Insert operations
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAfter(Node *prevNode, int val)
    {
        if (prevNode == nullptr)
            return;
        Node *newNode = new Node(val);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode->next != nullptr)
        {
            prevNode->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        prevNode->next = newNode;
    }

    // Read / Traversal operation
    void printList() const
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Update operation
    void updateNode(int oldVal, int newVal)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data != oldVal)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            temp->data = newVal;
        }
    }

    // Delete operations
    void deleteAtBeginning()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }

    void deleteAtEnd()
    {
        if (tail == nullptr)
            return;
        Node *temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
    }

    void deleteNode(int val)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data != val)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
            return;
        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next;
        }
        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }
        else
        {
            tail = temp->prev;
        }
        delete temp;
    }

    // Destructor to free memory
    ~DoublyLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(20);
    // list.insertAfter(list.head->next, 15);
    cout << "Doubly Linked List after insertions: ";
    list.printList();

    list.updateNode(15, 17);
    cout << "Doubly Linked List after update: ";
    list.printList();

    list.deleteAtBeginning();
    list.deleteAtEnd();
    list.deleteNode(10);
    cout << "Doubly Linked List after deletions: ";
    list.printList();

    return 0;
}
