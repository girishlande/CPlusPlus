
class Subject {
	int _value;
	vector<Observer*> _observers;
public:
	void attach(Observer* o) {
		_observers.push_back(o);
	}
	void detach(Observer* o) {
	}
	int getValue() {
		return _value;
	}
	void updateValue(int v) {
		_value = v;
		notify();
	}
	void notify() {
		for (auto a : _observers) {
			a->update();
		}
	}
};


// -------------------
The observer pattern 
// ------------------
is a software design pattern in which an object, called the subject, maintains a list of its dependents, called observers, and notifies them automatically of any state changes, usually by calling one of their methods.

#include <iostream>
#include "Subject.h"
#include "Observer.h"

class MailObserver : public Observer {
public:
    MailObserver(Subject* s) :Observer(s) {}
    void notify(const string& message) {
        cout << "\n Mail Observer notified : " << message;
    }
};

class SMSObserver : public Observer {
public:
    SMSObserver(Subject* s) :Observer(s) {}
    void notify(const string& message) {
        cout << "\n SMS Observer notified : " << message;
    }
};


int main()
{
    Subject sub;
    MailObserver mob(&sub);
    SMSObserver sms(&sub);

    sub.update(string("Indian Won match"));
    sub.update(string("Russia-Ukrain war"));


}


