#ifndef IANIMAL_H
#define IANIMAL_H

class iAnimal {
public:
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual void move() = 0;
    virtual ~iAnimal() {}; //we are going to make some people mad... but we need to free the memory
};



#endif // IANIMAL_H
