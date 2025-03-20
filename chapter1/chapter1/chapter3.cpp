#include<iostream>
using namespace std;


class Circle {
public:
	int outer;
	int inner;
	int innerRadius();
	int outerRadius();
};

int Circle::innerRadius() {
	return 3.14 * inner * inner;
}
int Circle::outerRadius() {
	return 3.14 * outer * outer;
}

int main() {
	Circle donut_two;
	donut_two.inner = 2;
	donut_two.outer = 3;
	int wholearea = donut_two.outerRadius();
	int innerarea = donut_two.innerRadius();
	cout << "내부 원의 면적은" << innerarea << endl;
}