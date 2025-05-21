#include <iostream>
#include <string>
using namespace std;
class Shape {
protected:
    string name;
    double a, b;
public:
    Shape(string n, double a, double b) : name(n), a(a), b(b) {}
	virtual double getArea() = 0;
	string getName() { return name; }
};
class Oval : public Shape {
protected:
    public:
        Oval(string n, double a, double b) : Shape(n, a, b) {
        }
        double getArea() {
		return 3.14 * a * b;
	}
};
class Rect : public Shape {
    public:
        Rect(string n, double a, double b) : Shape(n, a, b) {
        }
        double getArea() override{
		return a * b;
	}
};
class Triangular : public Shape {
	public:
        Triangular(string n, double a, double b) : Shape(n, a, b) {
        }
        double getArea() override{
		return a * b / 2;
	}
};
int main() {
    Shape* p[3];
    p[0] = new Oval("빈대떡",10,20);
    p[1] = new Rect("찰떡", 30, 40);
    p[2] = new Triangular("토스트", 30,40);
    for (int i = 0; i < 3; i++) {
		cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;
	}
    for (int i = 0; i < 3; i++) {
		delete p[i];
	}
	return 0;
}