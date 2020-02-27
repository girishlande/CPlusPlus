#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <sstream>
#include <thread>
#include <vector>
using namespace std;

shared_mutex m1, m2, m3;

string durationToString(std::chrono::milliseconds duration)
{
    ostringstream out;
    out << duration.count();
    string s = out.str();
    return s;
}

void p1()
{
    std::chrono::milliseconds timespan(rand() % 100 + 1000); // or whatever
    cout << " \nP1: Time required to finish:" << durationToString(timespan) << endl;
    std::this_thread::sleep_for(timespan);
    cout << " \nP1 finished" << endl
         << endl;
    m1.unlock();
}

void p2()
{
    m1.lock();
    std::chrono::milliseconds timespan(rand() % 200 + 1000); // or whatever
    cout << " \n P2: Time required to finish:" << durationToString(timespan) << endl;
    std::this_thread::sleep_for(timespan);
    cout << " \nP2 finished" << endl
         << endl;
    m2.unlock();
}

void p3()
{
    m2.lock();
    std::chrono::milliseconds timespan(rand() % 300 + 1000); // or whatever
    cout << "  \nP3: Time required to finish:" << durationToString(timespan) << endl;
    std::this_thread::sleep_for(timespan);
    cout << " \nP3 finished" << endl
         << endl;
    m3.unlock();
}

void p4()
{
    m3.lock();
    std::chrono::milliseconds timespan(rand() % 400 + 1000); // or whatever
    cout << "  \n P4: Time required to finish:" << durationToString(timespan) << endl;
    std::this_thread::sleep_for(timespan);
    cout << "\nP4 finished" << endl
         << endl;
}

int main()
{
    m1.lock();
    m2.lock();
    m3.lock();

    thread t1(p1);
    thread t2(p2);
    thread t3(p3);
    thread t4(p4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << "End of main thread" << endl;

    return 0;
}
