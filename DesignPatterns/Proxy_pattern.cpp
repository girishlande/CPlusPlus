#include <QCoreApplication>
#include <qdebug.h>
#include <iostream>
#include <vector>
using namespace std;

class RealImage {
    int id;
public:
    RealImage(int v) :id(v) {
        cout << "\n Real Image constructor:" << id;
    }
    ~RealImage() {
        cout << "\n Real Image destructor!"<<id;
    }
};

class Image {
    RealImage* m_real_image{0};
    static int counter;
    int m_id;
public:
    Image() {
        m_id = counter++;
        cout<< "\n Image constructor:"<<m_id;
    }

    void draw() {
        if (!m_real_image) {
            m_real_image = new RealImage(m_id);
        }
    }

    ~Image() {
        cout<< "\n Image destructor:" <<m_id;
    }

};

int Image::counter=1;
int main()
{
    Image image[5];
    for(int i;true;) {
        cout<< "\n 0:exit [1-5]:";
        cin>>i;
        if(i==0) {
            break;
        }
        image[i-1].draw();
    }
    cout << "\n\n\n";
}
