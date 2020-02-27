#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <sstream>
#include <thread>
#include <vector>
using namespace std;

class Node {
    int data;
    Node* next;

public:
    Node(int data)
        : data(data)
        , next(nullptr)
    {
    }

    void push(Node* node)
    {
        next = node;
    }

    void setNext(Node* node) {
        this->next = node;
    }

    Node* getNext()
    {
        return next;
    }

    int getData()
    {
        return data;
    }
};

void reverseDisplay(Node* node)
{
    if (node->getNext()) {
        reverseDisplay(node->getNext());
    }
    cout << node->getData() << "  ";
}

void createLinkedList(Node* head)
{
    Node* previous = head;
    for (int i = 1; i <= 10; i++) {
        Node* c = new Node(i * 10);
        previous->push(c);
        previous = c;
    }
}

void displayLinkedList(Node* head)
{
    Node* it = head->getNext();
    while (it) {
        cout << it->getData() << "  ";
        it = it->getNext();
    }
    cout << endl;
}

Node* reverseLinkedList(Node* head)
{
    Node* c = head;
    Node* n = c->getNext();
    Node* nn = nullptr;
    c->setNext(nullptr);
    if (n) {
        nn = n->getNext();
    }
    while (n) {
        n->setNext(c);
        c = n;
        n = nn;
        if (nn) {
           nn = nn->getNext();
        }
    }
    return c;
}

int main()
{
    Node* head = new Node(0);
    createLinkedList(head);

    // Original linked list
    cout << "Actual linked list:" << endl;
    displayLinkedList(head);

    // Display linked list in reverse order
    cout << "\nReverse display of linked list:" << endl;
    reverseDisplay(head->getNext());

    // Reverse actual linked list
    cout << "\n\nReversed linked list:" << endl;
    Node* newHead = reverseLinkedList(head);
    displayLinkedList(newHead);

    cout << endl;
    return 0;
}
