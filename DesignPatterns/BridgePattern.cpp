#include <QCoreApplication>
#include <qdebug.h>
#include <iostream>
#include <vector>
using namespace std;

class TimeImpl {
protected:
    int hr;
    int min;
public:
    TimeImpl(int h,int m):hr(h),min(m) {
    }
    virtual void tell() {
        qDebug() << "Hour:" <<hr<< " min:" <<min;
    }
};

class CivilTimeImp:public TimeImpl {
    char wh[3];
public:
    CivilTimeImp(int h,int m,bool am):TimeImpl(h,m) {
        if (am) {
            strcpy(wh,"AM");
        } else {
            strcpy(wh,"PM");
        }
    }
    void tell() {
        qDebug() << "Civil time Hour:" <<hr<< " min:" <<min << " " <<wh;
    }
};

class PublicTimeImpl:public TimeImpl {
    char wh[3];
public:
    PublicTimeImpl(int h,int m):TimeImpl(h,m) {

    }
    void tell() {
        qDebug() << "Public time Hour:" <<hr<< " min:" <<min;
    }
};

class Time {
protected:
    TimeImpl* imp;
public:
    Time() {}
    Time(int h,int m) {
        imp = new TimeImpl(h,m);
    }
    virtual void tell() {
        imp->tell();
    }
};

class CivilTime:public Time {
public:
    CivilTime(int h,int m,bool am) {
        imp = new CivilTimeImp(h,m,am);
    }
};

class PublicTime:public Time {
public:
    PublicTime(int h,int m) {
        imp = new PublicTimeImpl(h,m);
    }
};

int main()
{
    Time* times[3];
    times[0] = new Time(14,30);
    times[1] = new CivilTime(2,30,false);
    times[2] = new PublicTime(14,30);

    for(int i=0;i<3;i++){
        times[i]->tell();
    }
}
