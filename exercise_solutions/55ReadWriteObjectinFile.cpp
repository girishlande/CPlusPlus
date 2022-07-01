#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {
    int roll;
    string name;
public:
    Student() {
        roll = 11;
        name = "Girish";
    }

    Student(int r, string n) : roll(r), name(n) {}
    int getRoll() { return roll; }
    string getName() { return name;  }
};

int main()
{
    fstream fout("test.bin", ios::binary | ios::out);
    for (int i = 0; i < 10; i++) {
        Student s(i + 1, "Girish" + to_string(i + 1));
        fout.write((char*)& s, sizeof(Student));
    }
    fout.close();

    fstream fin("test.bin", ios::binary | ios::in);

    if (!fin.is_open()) {
        cout << "\n failed to open";
    }
    else {
        Student s;
        while (fin.read((char*)& s, sizeof(Student))) {
            cout << "\nStudent: Roll:" << s.getRoll() << " Name:" << s.getName();
        }
        fin.close();
    }
}

