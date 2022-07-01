

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef struct node {
    int data;
    struct node* next;
}NODE;

class MyList
{
    NODE* head;
    NODE* last;
    int data;
public:
    MyList() {
        head = nullptr;
        last = nullptr;
    }
    void append(int data) {
        NODE* newnode = createNode(data);
        if (head == nullptr) {
            head = newnode;
        }
        else {
            last->next = newnode;
        }
        last = newnode;
    }

    void display() {
        NODE* temp = head;
        cout << "\nList content:";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

protected:
    NODE* createNode(int data) {
        NODE* node = new NODE();
        node->data = data;
        node->next = nullptr;
        return node;
    }
};

int main() {
    MyList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    list.display();

    return 0;
}