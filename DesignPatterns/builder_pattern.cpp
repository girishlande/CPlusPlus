#include <QCoreApplication>
#include <qdebug.h>
enum PersistenceType {
    File,
    Queue,
    Pathway
};

struct PersistenceAttribute {
    PersistenceType type;
    char value[30];
};

class DistrWorkPackage {
    char desc[200];
    char temp[80];
public:
    DistrWorkPackage(char* type) {
        sprintf(desc,"Distribution work package for:%s",type);
    }
    void setFile(char* f, char* v) {
        sprintf(temp,"\n File (%s):%s",f,v);
        strcat(desc,temp);
    }
    void setQueue(char* q,char* v) {
        sprintf(temp,"\n Queue(%s):%s",q,v);
        strcat(desc,temp);
    }
    void setPathway(char* p,char* v) {
        sprintf(temp,"\n Pathway (%s):%s",p,v);
        strcat(desc,temp);
    }
    const char* getstate() {
        return desc;
    }
};

class Builder  {
public:
    virtual void configureFile(char*)=0;
    virtual void configureQueue(char*)=0;
    virtual void configurePathway(char*)=0;
    DistrWorkPackage* getResult() {
        return result;
    }
protected:
    DistrWorkPackage* result;
};

class UnixBuilder:public Builder {
public:
    UnixBuilder() {
        result = new DistrWorkPackage("Unix");
    }
    void configureFile(char* file) {
        result->setFile("flatfile",file);
    }
    void configureQueue(char* queue) {
        result->setQueue("FIFO",queue);
    }
    void configurePathway(char* pathway) {
        result->setPathway("Threat",pathway);
    }
};

class WindowBuilder:public Builder {
public:
    WindowBuilder() {
        result = new DistrWorkPackage("Windows");
    }
    void configureFile(char* file) {
        result->setFile("ISM",file);
    }
    void configureQueue(char* queue) {
        result->setQueue("Priority",queue);
    }
    void configurePathway(char* pathway) {
        result->setPathway("LWP",pathway);
    }
};


class Reader {
    Builder* builder;
public:
    void SetBuilder(Builder* b) {
        builder = b;
    }
    void construct(PersistenceAttribute list[],int num) {
        for(int i=0;i<num;++i) {
            if (list[i].type==File) {
                builder->configureFile(list[i].value);
            } else if (list[i].type==Pathway) {
                builder->configurePathway(list[i].value);
            } else if (list[i].type==Queue){
                builder->configureQueue(list[i].value);
            }
        }
    }
};

PersistenceAttribute list[] = {
    {File,"state.dat"},
    {File,"config.dat"},
    {Pathway,"Compute"},
    {Pathway,"Log"},
    {Queue,"authentication"},
    {Queue,"Error processing"}
};

int main()
{

    UnixBuilder ubuilder;
    WindowBuilder wbuilder;
    Reader reader;
    reader.SetBuilder(&ubuilder);
    reader.construct(list,6);
    qDebug() << " \n builder:" << ubuilder.getResult()->getstate();

    reader.SetBuilder(&wbuilder);
    reader.construct(list,6);
    qDebug() << " \n\ builder:" << wbuilder.getResult()->getstate();

}
