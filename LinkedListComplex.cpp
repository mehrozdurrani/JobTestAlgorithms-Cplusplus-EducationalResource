#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *previous;
    Node(int value) : data(value), next(nullptr), previous(nullptr) {}
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length = 0;

    void DeleteNodefromLinkedList(Node *node)
    {
        if (node == head)
        {
            head = head->next;
            delete node;
            length--;
        }
        else if (node == tail)
        {
            tail = tail->previous;
            delete node;
            length--;
        }
        else
        {
            node->previous->next = node->next;
            node->next->previous = node->previous;
            delete node;
            length--;
        }
    }

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void AddNewValue(int value)
    {
        Node *newNode = new Node(value);
        length++;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    void FindAndDeleteValue(int value)
    {
        Node *tempPtr = head;

        while (tempPtr != tail)
        {
            if (tempPtr->data == value)
            {
                DeleteNodefromLinkedList(tempPtr);
                break;
            }
            else
                tempPtr = tempPtr->next;
        }
    }

    Node *GetHead()
    {
        return head;
    }
    Node *GetTail()
    {
        return tail;
    }
};

int main()
{
    LinkedList *linkList = new LinkedList();

    linkList->AddNewValue(1);
    linkList->AddNewValue(2);
    linkList->AddNewValue(3);
    linkList->AddNewValue(4);
    linkList->AddNewValue(5);

    linkList->FindAndDeleteValue(4);

    return 0;
}