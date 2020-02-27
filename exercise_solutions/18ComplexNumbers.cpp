#include <iostream>
#include <ostream>
using namespace std;

class Complex {

    float real;
    float img;

public:
    Complex() {}
    Complex(float r, float i)
        : real(r)
        , img(i)
    {
    }

    Complex(const Complex& other)
    {
        real = other.real;
        img = other.img;
    }

    Complex& operator=(const Complex& other)
    {
        this->real = other.real;
        this->img = other.img;
        return *this;
    }

    Complex(Complex&& other)
    {
        this->real = other.real;
        this->img = other.img;
    }

    friend Complex operator+(Complex& first, Complex& second);
    friend Complex operator+(Complex& first, double val);
    friend Complex operator+(double val, Complex& second);
    friend bool operator==(Complex& first, Complex& second);
    friend ostream& operator<<(ostream& out, const Complex& obj);
};

ostream& operator<<(ostream& out, const Complex& obj)
{
    out << "(" << obj.real << "," << obj.img << ")" << endl;
    return out;
}

Complex operator+(Complex& first, Complex& second)
{
    Complex c3;
    c3.img = first.img + second.img;
    c3.real = first.real + second.real;
    return c3;
}

Complex operator+(Complex& first, double val)
{
    Complex c3;
    c3.img = first.img + val;
    c3.real = first.real + val;
    return c3;
}

Complex operator+(double val, Complex& second)
{
    Complex c3;
    c3.img = val + second.img;
    c3.real = val + second.real;
    return c3;
}

bool operator==(Complex& first, Complex& second)
{
    return first.img == second.img && first.real == second.real;
}

int main()
{
    Complex c1(10, 10);
    Complex c2(10, 10);
    cout << "c1:" << c1 << endl;
    cout << "c2:" << c2 << endl;
    cout << "Are they equal:" << (c1 == c2) << endl;
    c1 = c1 + 10;
    cout << "c1 = c1 + 10:" << c1 << endl;
    
    cout << "(c1 + c2) " << (c1 + c2) << endl;
    cout << "(c1 + 20) " << (c1 + 20) << endl;
    cout << "(30 + c2) " << (30 + c2) << endl;

    return 0;
}
