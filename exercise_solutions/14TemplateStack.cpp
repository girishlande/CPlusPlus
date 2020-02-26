#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack {
    vector<T> m_items;

public:
    void push(T obj)
    {
        m_items.push_back(obj);
    }
    T pop()
    {
        if (m_items.size()) {
            T obj = m_items.back();
            m_items.pop_back();
            return obj;
        }
        return T();
    }
    bool isEmpty()
    {
        return m_items.size() == 0;
    }
};

int main()
{
    Stack<int> s1;
    s1.push(11);
    s1.push(12);
    s1.push(13);
    s1.push(14);
    while (!s1.isEmpty()) {
        cout << s1.pop() << "\n";
    }
    return 0;
}
