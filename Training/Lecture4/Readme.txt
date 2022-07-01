

1. explain memory management using smart pointers
explain using following example. 

// auto_ptr
// unique_ptr
// shared_ptr

class Student {
    int roll;
    string name;
public:
    Student() {
        cout << "\nstudent constructor called!";
    }
    ~Student() {
        cout << "\nStdent destructor called!";
    }
};


void func() {
    Student* s1 = new Student();
    shared_ptr<Student> s2(new Student());

}

int main()
{
    func();
}

2. Features of Object oriented programming

We have seen what is Procedure oriented programming. (Basically calling functions to get the job done)
This approach is not very expandable and mainable in the long run and hence people prefer object oriented solutions to problems. 
What are the features of object Oriented Programming. 

Object, Class, Abstraction, Encapsulation,  Inheritance, Polymorphism, Dynamic binding, Message communication 

>Object is instance of the class. 
>Class is building block. It is user defined data type which holds its own data members and member functions. 
These data members and functions can be accessed by creating the instance of the class. Class is blueprint of the object. 
>Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation. We see this abstraction everywhere. We get only required controls to use any system, for e.g washing machine, Fridge, Oven, Fan. We don't need to understand details of machine i.e how it works internally. You just want to get the job done using machine. 
Similarly using classes and access specifiers (public, protected, private) we can decide which data members can be accessed from outiside and which can not. 
Abstraction using header files. We use many functions from math.h or algorithm.h We simply call those functions by passing the input data. How that function sorts or calculates we don't need to know. For us its a black box. 
>Encapsulation : wrapping of data and information in single unit. This leads to abstraction. To access the data User must have to use the provided interfaces only. So data can be accessed and modified using the given functions only. 

>Inheritance : Capability of class to derive properties and characteristic from another class is called inheritance. 
Sub class: The class that inherits the properties from another class 
super class : class whoes properties are inherited are called super class. 
Why do we use Inheritance. Do avoid duplication of code in similar classes. Hence chances of error and data redundancy. 

Show inheritance using example. 

// Base class
class Parent {
public:
    int id_p;
};
 
// Sub class inheriting from Base Class(Parent)
class Child : public Parent {
public:
    int id_c;
};
 
// main function
int main()
{
    Child obj1;
 
    // An object of class child has all data members
    // and member functions of class parent
    obj1.id_c = 7;
    obj1.id_p = 91;
    cout << "Child id is: " << obj1.id_c << '\n';
    cout << "Parent id is: " << obj1.id_p << '\n';
 
    return 0;
}


Modes of inheritance. public, protected and private. 

Polymorphism: ability to take multiple forms. 
Compile time => function overloading and operator overloading
and run time polymorphism  => virtual functions

Dynamic binding refers to linking a procedure call to code that will execute only once. 
The code associated with the procedure is not known until the program is executed, which is also known as late binding.
Explain with the concept of function pointer. 

//Dynamic Binding program in c++  
#include < iostream >   
using namespace std;  
int Square(int x) //Square is =x*x;  
{  
    return x * x;  
}  
int Cube(int x) // Cube is =x*x*x;  
{  
    return x * x * x;  
}  
main() {  
    int x = 100;  
    int choice;  
    do {  
        cout << "Enter 0 for Square value, 1 for Cube value :\n";  
        cin >> choice;  
    }  
    while (choice < 0 || choice > 1);  
    int( * ptr)(int);  
    switch (choice) {  
        case 0:  
            ptr = Square;  
            break;  
        case 1:  
            ptr = Cube;  
            break;  
    }  
    cout << "The result is :" << ptr(x);  
    return 0;  
}  


// ---------------------------------------------
// Classes and Objects
// -----------------------------
Show the use of class. 
Change access specifier and show how it gives error when trying to call protected methods. 

#include <iostream>
#include<string>
using namespace std;

class Student {
    int roll;
    string name;
public:
    Student(int r, string n):roll(r),name(n) {
        cout << "\n Student constructor called!";
    }
    ~Student() {
        cout << "\n Student destructor called!";
    }

    void displayStudent() {
        cout << "\nStudent information:";
        cout << "\nRoll:" << roll;
        cout << "\nName:" << name;
    } 
};


int main()
{
    Student s1(11, "Girish");
    s1.displayStudent();

}

Add a function outside of the class and show how declaration is separated from the definition. 


// ---------------------------------------------------------------------------------------
// Copy constructor use
// ---------------------------------------------------------------------------------------

class Student {
    int m_roll;
    char* m_name;
public:
    Student(int r, const char* name) {
        cout << "\nConstructor called!";
        size_t len = strlen(name);
        cout << "length:" << len;
        m_name = new char[len + 1];
        strcpy_s(m_name, len+1, name);
    }
    Student(const Student& ref) {
        cout << "\n copy constructor called!";
        size_t len = strlen(ref.m_name) + 1;
        this->m_name = new char[len];
        strcpy_s(this->m_name, len, ref.m_name);
    }
    void display() const {
        cout << "\nRoll: " << m_roll << " Name:" << m_name;
    }

    ~Student() {
        delete m_name;
    }
};
int main()
{
    Student s1(11, "Girish");
    s1.display();
    Student s2 = s1;
    s2.display();
}


// ---------------------------------------------
//  Overloading Pre and Post increment operators
// ---------------------------------------------

Show how to overload unary Pre and post increment and binary addition operator. 

 
class Point2d {
    int x;
    int y;
public:
    Point2d(int x, int y) : x(x), y(y) {

    }

    friend ostream& operator<<(ostream& out, const Point2d& point);

    const Point2d& operator++() {
        this->x = this->x + 1;
        this->y = this->y + 1;
        return *this;
    }

    Point2d& operator++(int) {
        this->x = this->x + 1;
        this->y = this->y + 1;
        return *this;
    }

    Point2d& operator+(const Point2d& point) {
        this->x = this->x + point.x;
        this->y = this->y + point.y;
        return *this;
    }

};

ostream& operator<<(ostream& out, const Point2d& point) {
    out << "\nX:" << point.x << " Y:" << point.y;
    return out;
}

int main()
{
    Point2d p1(10, 20);
    cout << p1;
    ++p1;
    p1++;
    cout << p1;

    Point2d p2(5, 10);
    Point2d p3 = p1 + p2;
    cout << p3;

}

