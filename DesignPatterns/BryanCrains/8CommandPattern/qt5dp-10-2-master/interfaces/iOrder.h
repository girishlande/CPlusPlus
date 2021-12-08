#ifndef IORDER_H
#define IORDER_H

class iOrder {
public:

    virtual void execute() = 0;
    virtual ~iOrder() {} //This will make people mad
};

#endif // IORDER_H
