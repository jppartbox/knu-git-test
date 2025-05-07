#include <iostream>
using namespace std;

class Matrix {
	int a, b, c, d;
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	void show() {
		cout << "Matrix = { " << a << " " << b << " " << c << " " << d << " }" << endl;
	}

	friend int* operator<<(int arr[], const Matrix& m);
	friend int* operator>>(int arr[], Matrix& m);
};

int* operator<<(int arr[], const Matrix& m) {
	arr[0] = m.a;
	arr[1] = m.b;
	arr[2] = m.c;
	arr[3] = m.d;
	return arr;
}
int* operator>>(int arr[], Matrix& m) {
	m.a = arr[0];
	m.b = arr[1];
	m.c = arr[2];
	m.d = arr[3];
	return arr;
}
int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1, 2, 3, 4 };
	x << a;
	y >> b;  
	for (int i = 0; i < 4; i++) {
		cout << x[i] << " ";
	}
	cout << endl;

	b.show();
}
