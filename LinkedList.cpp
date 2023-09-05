#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *previous;
    Node(int value) : data(value), next(nullptr), previous(nullptr) {}
};

int main()
{
    Node *head = new Node(1);

    Node *node1 = new Node(2);

    Node *node2 = new Node(3);

    Node *node3 = new Node(4);

    head->next = node1;
    head->previous = nullptr;

    node1->next = node2;
    node2->previous = node1;

    node2->next = node3;
    node3->previous = node3;

    node3->next = nullptr;

    return 0;
}