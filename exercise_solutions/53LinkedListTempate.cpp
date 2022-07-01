

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template<class T>
class MyList
{
    typedef struct node {
        T data;
        struct node* next;
    }NODE;

    NODE* head;
    NODE* last;
    T data;
public:
    MyList() {
        head = nullptr;
        last = nullptr;
    }
    void append(T data) {
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
    NODE* createNode(T data) {
        NODE* node = new NODE();
        node->data = data;
        node->next = nullptr;
        return node;
    }
};

int main() {
    MyList<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    list.display();

    MyList<string> slist;
    slist.append("Girish");
    slist.append("Ajit");
    slist.append("Sameer");
    slist.append("Suhas");
    slist.display();

    return 0;
}