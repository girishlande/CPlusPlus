// template1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class MStack {

public:
    MStack()
    {
        cout << "Default constructor" << endl;
    }
    void push(T item)
    {
        items.push_back(item);
    }
    T pop()
    {
        int index = items.size();
        if (index) {
            T item = items[index - 1];
            items.pop_back();
            return item;
        }
        return T();
    }
    bool isEmpty()
    {
        return items.size() == 0;
    }

private:
    vector<T> items;
};
int main()
{
    std::cout << "Hello World!\n";
    MStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    cout << "Displaying stack content:" << endl;
    while (!stack.isEmpty())
        cout << stack.pop() << endl;

    MStack<string> sstack;
    sstack.push("Ajit");
    sstack.push("Girish");
    sstack.push("Suhas");
    sstack.push("Sameer");
    cout << "\nDisplaying stack content:" << endl;
    while (!sstack.isEmpty())
        cout << sstack.pop() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
