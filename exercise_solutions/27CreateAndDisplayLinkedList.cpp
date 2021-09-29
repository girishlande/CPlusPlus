// Program to create and display a linked list 
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
    Node(int data):data(data),next(nullptr) {
    }
    void push(Node* node) {
        this->next = node;
    }
    Node* getNext() {
        return next;
    }
    void print() {
        cout << "data:" << data << endl;
    }
};


int main()
{
    Node* head = new Node(0);
    Node* previous = head;
    for (int i = 1; i <= 10; i++) {
        Node* current = new Node(i * 10);
        previous->push(current);
        previous = current;
    }

    while (head->getNext()) {
        head->print();
        head = head->getNext();
    }
    return 0;
}
