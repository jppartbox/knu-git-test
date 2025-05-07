#include<iostream>
#include<string>
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

	// 프렌드 함수 선언
	friend Matrix operator+(Matrix m1, Matrix m2);
	friend Matrix& operator+=(Matrix& m1, Matrix m2);
	friend bool operator==(Matrix m1, Matrix m2);
};

// 프렌드 함수 정의
Matrix operator+(Matrix m1, Matrix m2) {
	return Matrix(m1.a + m2.a, m1.b + m2.b, m1.c + m2.c, m1.d + m2.d);
}

Matrix& operator+=(Matrix& m1, Matrix m2) {
	m1.a += m2.a;
	m1.b += m2.b;
	m1.c += m2.c;
	m1.d += m2.d;
	return m1;
}

bool operator==(Matrix m1, Matrix m2) {
	return (m1.a == m2.a && m1.b == m2.b && m1.c == m2.c && m1.d == m2.d);
}

int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are same" << endl;
}