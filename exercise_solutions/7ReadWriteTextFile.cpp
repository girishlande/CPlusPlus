#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    fstream stream;
    stream.open("abc.txt", ios::out);
    if (stream.is_open()) {
        cout << "File is opened for write" << endl;
        stream << "Hi This is one line \nThis is second line" << endl;
        stream.close();
    } else {
        cout << "failed to open a stream.";
    }

    stream.open("abc.txt", ios ::in);
    if (stream.is_open()) {
        cout << "File is opened for read:" << endl;
        string str;
        while (stream) {
            stream >> str;
            cout << str << " ";
        }
        cout << "\n";
        stream.close();
    }

    return 0;
}
