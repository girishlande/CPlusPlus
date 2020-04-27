
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

class Observer {
protected:
	Subject* _model;
	int _value;
public:
	Observer(Subject* s, int v) :_model(s),_value(v) {
		s->attach(this);
	}
	virtual void update() = 0;
};


class DivObserver : public Observer {
public:
	DivObserver(Subject* s,int v) :Observer(s,v) {}
	virtual void update() {
		cout << "Divobserve update()" << endl;
		cout << "answer:" << _model->getValue() / _value << endl;
	}
};

class MultObserver : public Observer {
public:
	MultObserver(Subject* s, int v) :Observer(s, v) {}
	virtual void update() {
		cout << "MultObserver update()" << endl;
		cout << "answer:" << _model->getValue() * _value << endl;
	}
};

void main() {
cout << "Hello Girish" << endl;
	Subject sub;
	DivObserver d(&sub,2);
	MultObserver m(&sub, 2);
	sub.updateValue(10);
	sub.updateValue(20);
}