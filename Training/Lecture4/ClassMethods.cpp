
#include <iostream>
#include <vector>

using namespace std;

class Student {
    int roll;
    string name;
public:

    Student() {

    }

    Student(int r, string n) {
        roll = r;
        name = n;
    }

    void setRoll(int r);
    int Roll();

    void setName(string n) {
        this->name = n;
    }

    string Name() {
        return this->name;
    }

    void display() {
        cout << "\n Student info:" << this->roll << " " << this->name;
    }
};

void Student::setRoll(int r) {
    roll = r;
}

int Student::Roll() {
    return roll;
}


class Institute {
    vector<Student> students;

public:
    void registerStudent(Student& student) {
        students.push_back(student);
    }

    void displayStudents() {
        for (auto& a : students) {
            a.display();
        }
    }
};

int main()
{
    Student s1;
    s1.setName("Girish");
    s1.setRoll(11);
    
    Student s2;
    s2.setName("Ajit");
    s2.setRoll(21);

    Student s3;
    s3.setName("Suhas");
    s3.setRoll(31);

    Institute inst;
    inst.registerStudent(s1);
    inst.registerStudent(s2);
    inst.registerStudent(s3);

    inst.displayStudents();

}

