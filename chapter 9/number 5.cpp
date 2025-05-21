#include <iostream>
#include <string>
using namespace std;
class AbstractGate {
protected:
    bool x, y;
public:
    void set(bool x, bool y) {
		this->x = x;
		this->y = y;
	}
	virtual bool operation() = 0;
};
class AndGate : public AbstractGate {
public:
	bool operation() {
		return x && y;
	}
};
class OrGate : public AbstractGate {
public:
	bool operation() override{
		return x || y;
	}
};
class XORGate : public AbstractGate {
public:
	bool operation() override{
		return (x && !y) || (!x && y);
	}
};
int main() {
	AndGate andGate;
	OrGate orGate;
	XORGate xorGate;
	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);
	cout.setf(ios::boolalpha);
	cout << "AND Gate: " << andGate.operation() << endl;
	cout << "OR Gate: " << orGate.operation() << endl;
	cout << "XOR Gate: " << xorGate.operation() << endl;
	return 0;	
}