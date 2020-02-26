#include <fstream>
#include <iostream>

using namespace std;

struct Student {
    int roll;
    string name;
};

int main()
{
    Student s1({ 11, "GirishParshuramLande" });
    fstream stream;
    stream.open("xyz.dat", ios::binary | ios::out);
    if (stream.is_open()) {
        cout << "opened file for write: " << sizeof(s1) << endl;
        stream.write((char*)&s1, sizeof(s1));
    } else {
        cout << "failed to open file for write operation" << endl;
    }
    stream.close();

    stream.open("xyz.dat", ios::binary | ios::in);
    if (stream.is_open()) {
        Student s2;
        stream.read((char*)&s2, sizeof(s2));
        cout << s2.roll << " " << s2.name << endl;
        stream.close();
    }

    return 0;
}
