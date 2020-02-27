#include <iostream>
#include <vector>
using namespace std;

template <class T>
class MyQue {
    vector<T> items;

public:
    void pushIn(T item)
    {
        items.push_back(item);
    }

    T popOut()
    {
        T item = items.front();
        items.erase(items.begin());
        return item;
    }

    size_t size()
    {
        return items.size();
    }
};

int main()
{
    cout << "Queue of integers:" << endl;
    MyQue<int> q;
    q.pushIn(10);
    q.pushIn(20);
    q.pushIn(30);
    q.pushIn(40);
    while (q.size()) {
        cout << q.popOut() << endl;
    }

    cout << "\n\nQueue of strings:" << endl;
    MyQue<string> qs;
    qs.pushIn("Girish");
    qs.pushIn("Ajit");
    qs.pushIn("Ganesh");
    qs.pushIn("Prashant");
    while (qs.size()) {
        cout << qs.popOut() << endl;
    }

    cout << endl;
    cout << endl;

    return 0;
}
