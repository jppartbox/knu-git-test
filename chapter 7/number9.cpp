#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius=0) {
		this->radius = radius;
	}
	void show() {
		cout << "radius = " << radius << "인 원" << endl;
	}
	Circle operator+(int r) {
		Circle temp;
		temp.radius = radius + r;
		return temp;
	}
	Circle operator++(int a) {
		Circle temp = *this;
		radius++;
		return temp;
	}
	Circle& operator++() {
		radius++;
		return *this;
	}
};

int main() {
	Circle a(5), b(4);
	b = a+1;
	a.show();
	b.show();
}