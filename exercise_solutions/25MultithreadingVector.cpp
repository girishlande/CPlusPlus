#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

vector<int> vec;
mutex m;

void push()
{
    for (int i = 0; i < 10; i++) {
        m.lock();
        vec.push_back(i);
        cout << "Push: " << i << endl
             << flush;
        m.unlock();
        std::chrono::milliseconds timespan(rand() % 500 + 100); // or whatever
        std::this_thread::sleep_for(timespan);
    }
}

void pop()
{
    for (int i = 0; i < 10; i++) {
        m.lock();
        if (vec.size()) {
            vec.pop_back();
        }
        else {
            i--;
            m.unlock();
            continue;
        }

        cout << "Pop: " << i << endl
             << flush;
        m.unlock();
        std::chrono::milliseconds timespan(rand()%500 + 300); // or whatever
        std::this_thread::sleep_for(timespan);
    }
}

int main()
{
    thread t1(push);
    thread t2(pop);
    cout << "main thread executing" << endl;

    t1.join();
    t2.join();

    cout << "End of main thread" << endl;

    return 0;
}
