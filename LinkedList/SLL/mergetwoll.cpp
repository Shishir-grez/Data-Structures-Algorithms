#include <iostream>
#include <stdio.h>
#include <cassert>
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
    void insert(Node *&head, int data)
    {
        if (!head)
        {
            head = new Node;
            head->data = data;
        }
        else
        {
            assert(head != nullptr);

            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            assert(temp != nullptr);

            temp->next = new Node;
            temp = temp->next;
            temp->data = data;
        }
    }
    void print(Node *head)
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        assert(temp != nullptr);
        cout << temp->data << endl;
    }
    void deleteptr(Node *&head)
    {
        Node *temp = head;
        Node *nxt;

        while (temp != nullptr)
        {                     // Loop until temp is nullptr
            nxt = temp->next; // Save the next node
            delete temp;      // Delete the current node
            temp = nxt;       // Move to the next node
        }
        head = nullptr; // Set head to nullptr to avoid dangling pointer
    }
    void merge(Node *&head1, Node *&head2, Node *&head3)
    {
        Node *temp1 = head1;
        Node *temp2 = head2;
        Node *temp3;
        head3 = nullptr;
        assert((temp1 != nullptr) && (temp2 != nullptr) && (head3 == nullptr));

        while ((temp1 != nullptr) || (temp2 != nullptr))
        {
            if ((temp1 != nullptr) && (temp2 == nullptr))
            {
                assert(temp3 != nullptr);
                temp3->next = new Node;
                temp3 = temp3->next;

                temp3->data = temp1->data;
                temp1 = temp1->next;
            }
            else if ((temp2 != nullptr) && (temp1 == nullptr))
            {
                assert(temp3 != nullptr);
                {
                    temp3->next = new Node;
                    temp3 = temp3->next;

                    temp3->data = temp2->data;
                    temp2 = temp2->next;
                }
            }
            else
            {
                if (!head3)
                {
                    head3 = new Node;
                    temp3 = head3;
                    if (temp1->data > temp2->data)
                    {
                        temp3->data = temp2->data;
                        temp2 = temp2->next;
                    }
                    else if (temp1->data < temp2->data)
                    {
                        temp3->data = temp1->data;
                        temp1 = temp1->next;
                    }
                    else
                    {
                        temp3->data = temp1->data;
                        temp1 = temp1->next;
                        temp2 = temp2->next;
                    }
                }
                else
                {
                    assert(head3 != nullptr && temp3 != nullptr);
                    temp3->next = new Node;
                    temp3 = temp3->next;
                    if (temp1->data > temp2->data)
                    {
                        temp3->data = temp2->data;
                        temp2 = temp2->next;
                    }
                    else if (temp1->data < temp2->data)
                    {
                        temp3->data = temp1->data;
                        temp1 = temp1->next;
                    }
                    else
                    {
                        temp3->data = temp1->data;
                        temp1 = temp1->next;
                        temp2 = temp2->next;
                    }
                }
            }
        }
    }
};
int main()
{
    LinkedList A;
    Node *a, *b, *c;
    a = nullptr;
    b = nullptr;
    A.insert(a, 1);
    A.insert(a, 3);
    A.insert(a, 5);
    A.insert(a, 7);
    A.insert(a, 9);

    A.insert(b, 2);
    A.insert(b, 4);
    A.insert(b, 6);
    A.insert(b, 8);
    A.insert(b, 10);

    A.print(a);
    A.print(b);

    A.merge(a, b, c);
    A.print(c);

    A.deleteptr(a);
    A.deleteptr(b);
    A.deleteptr(c);

    return 0;
}