#include <iostream>
#include <vector>

using namespace std;

template <class T>
class MStack {
    vector<T> m_items;

public:
    void push(T obj)
    {
        m_items.push_back(obj);
    }
    T pop()
    {
        T item = m_items.back();
        m_items.pop_back();
        return item;
    }
    bool isEmpty()
    {
        return !m_items.size();
    }
};

int main()
{
    MStack<int> mstack;
    cout << "Is Initially empty ? " << mstack.isEmpty() << endl;

    // Add some elements in stack.
    cout << "Integer stack contents" << endl;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);
    while (!mstack.isEmpty()) {
        cout << mstack.pop() << endl;
    }

    cout << "\nString stack contents" << endl;
    MStack<string> stringstack;
    stringstack.push("Girish");
    stringstack.push("Ajit");
    stringstack.push("Suhas");
    stringstack.push("Sameer");
    while (!stringstack.isEmpty()) {
        cout << stringstack.pop() << endl;
    }

    return 0;
}
