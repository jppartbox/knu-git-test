#include<iostream>
#include<string>
using namespace std;
class Matrix {
	int a,b,c,d;
public:
	Matrix(int a = 0, int b = 0, int c=0, int d=0) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	void show() {
		cout << "Matrix = { " << a << " " << b << " " << c << " " << d << " }" << endl;
	}
	Matrix operator+(Matrix bora) {
		Matrix temp;
		temp.a = a + bora.a;
		temp.b = b + bora.b;
		temp.c = c + bora.c;
		temp.d = d + bora.d;
		return temp;
	}
	Matrix operator+=(Matrix bora) {
		a= a + bora.a;
		b= b + bora.b;
		c= c + bora.c;
		d= d + bora.d;
			return *this;
	}
	bool operator==(Matrix color) {
		if(a == color.a && b == color.b && c == color.c && d == color.d)
			return true;
		else
			return false;
	}
};
	int main() {
		Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
		c = a + b;
		a += b;
		a.show(); b.show(); c.show();
		if(a==c)
			cout <<"a and c are same"<<endl;
	}
