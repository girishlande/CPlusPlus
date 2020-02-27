/*
Suppose there is a stream of emails which we are fetching from a mail server. We need to do some processing on these emails and print the output in the same order in which we received the emails.
If we fetch emails in the order M1, M2, M3, M4, our output should be in the same order, that is, P1, P2, P3, P4. Here P1 refers to the processed output of M1.. and so on.
Design this system using multithreading.

*/
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <sstream>
#include <thread>
#include <vector>
using namespace std;

string decompressString(string in)
{
    string de;
    int i = 0;
    stringstream output;
    while (i < in.length()) {
        char c = in[i];
        int j = i + 1;
        stringstream stream;
        while (j < in.length() && in[j] >= '0' && in[j] <= '9') {
            stream << in[j];
            j++;
        }
        int num = 0;
        stream >> num;
        cout << c << " times " << num << endl;
        output << string(num, c);
        i=j;
    }
    return output.str();

}

int main()
{
    cout << endl << "output:" << decompressString("a3d5w3b10c20d30") <<endl<<endl;
    return 0;
}
