#include <algorithm>
#include <iostream>
#include <ostream>
using namespace std;

class Student {
    int m_roll;
    string m_name;

public:
    Student() {}

    Student(int roll, string name)
        : m_roll(roll)
        , m_name(name)
    {
    }

    Student(const Student& s) {
        cout << "copy constructor called\n";
        m_name = s.m_name;
        m_roll = s.m_roll;
    }

    void print()
    {
        cout << "roll:" << m_roll << " name:" << m_name << endl;
    }

    Student& operator=(const Student& other) {
        cout << "=operator called\n";
        m_roll = other.m_roll;
        m_name = other.m_name;
        return *this;
    }

    friend ostream& operator << (ostream& out, const Student& other);
};

ostream& operator<<(ostream& out, const Student& other)
{
    out << "Student roll:" << other.m_roll << "name:" << other.m_name;
    return out;
}

int main()
{
    Student s1(11, "Girish");
    Student s2(12, "Suhas");
    Student s3 = s1 = s2;

    cout << s1 << endl
         << s2 << endl
         << s3 << endl;

    return 0;
}


//Operator overloading using friend function 
// There are different types of operators such as unary operator and binary operator.
#include <iostream>
#include<string>
#include<vector>

using namespace std;

class Point2D
{
    int x;
    int y;
public:
    Point2D(int x, int y) : x(x), y(y) {
    }

    void display() {
        cout << "\n X:" << x << " Y:" << y;
    }

    friend const Point2D& operator+(const Point2D& p1, const Point2D& p2);
    friend ostream& operator<<(ostream& out, const Point2D& point);
};

const Point2D& operator+(const Point2D& p1, const Point2D& p2) {
    Point2D p3(p1.x + p2.x, p1.y + p2.y);
    return p3;
}

ostream& operator<<(ostream& out, const Point2D& point) {
    out << "\n(X:" << point.x << " Y:" << point.y << ")";
    return out;
}

int main()
{
    Point2D p1(10, 20);
    p1.display();

    Point2D p2(10, 20);
    p2.display();

    Point2D p3 = p1 + p2;
    p3.display();

    cout << p1;
}


// Explain constructors.
default constructor
overloaded constructor
parameterized constructors.

// Show the use of static members, counter as static data member and some utility functions as min and max
class Math {
public:
    static int max(int x, int y) {
        return x > y ? x : y;
    }

    static int min(int x, int y) {
        return x < y ? x : y;
    }
};

int main()
{
    cout << "\nMax: " << Math::max(10, 20);
    cout << "\nMin: " << Math::min(10, 20);

}





