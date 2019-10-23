#include <iostream>
#include <list>
#include <map>
#include <thread>
#include <vector>

using namespace std;

void ThrdFunc1()
{
    cout << "Local thread id: " << this_thread::get_id() << " started" << endl;
    cout << "This is thread function " << endl;
    for (int i = 0; i < 5; i++) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Thread id:" << this_thread::get_id() << endl;
    }
    
    cout << "Local thread id: " << this_thread::get_id() << " finished" << endl;
}

void ThrdFunc2()
{
    cout << "Local thread id: " << this_thread::get_id() << " started" << endl;
    cout << "This is thread function " << endl;
    for (int i = 0; i < 5; i++) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Thread id:" << this_thread::get_id() << endl;
    }

    cout << "Local thread id: " << this_thread::get_id() << " finished" << endl;
}

int main()
{
    cout << "Main thread id: " << this_thread::get_id() <<endl;

    thread t1 { ThrdFunc1 };
    this_thread::sleep_for(chrono::milliseconds(500));
    thread t2 { ThrdFunc2 };
    t1.join();
    t2.join();

    cout << "Main thread id: " << this_thread::get_id() << " finished " << endl;
    return 0;
}