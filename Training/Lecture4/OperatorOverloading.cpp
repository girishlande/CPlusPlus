
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Point2D {
    int x;
    int y;

public:
    Point2D(int x, int y) : x(x), y(y) {
    }


    void display() {
        cout << "\nPoint: x=" << x << " y=" << y;
    }

    friend ostream& operator<<(ostream& out, Point2D& ref);

    void operator++() {
        this->x = this->x + 1;
        this->y = this->y + 1;
    }

    void operator--() {
        this->x = this->x - 1;
        this->y = this->y - 1;
    }

    Point2D& operator+(const Point2D& ref) {
        Point2D* temp = new Point2D(this->x + ref.x, this->y + ref.y);
        return *temp;
    }

    Point2D& operator-(const Point2D& ref) {
        Point2D* temp = new Point2D(this->x - ref.x, this->y - ref.y);
        return *temp;
    }
};

ostream& operator<<(ostream& out, Point2D& ref) {
    out << "\nPoint (" << ref.x << "," << ref.y << ")";
    return out;
}


int main()
{
    Point2D p1(10, 20);
    cout << p1;

    ++p1;
    cout << p1;

    --p1;
    --p1;
    cout << p1;

    Point2D p2(20, 20);
    Point2D p3(10, 10);
    Point2D p4 = p2 + p3;
    cout << p4;

    Point2D p5 = p2 - p3;
    cout << p5;
}

