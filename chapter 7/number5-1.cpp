#include<iostream>
#include<string>
using namespace std;
class Color {
	string title;
	int a,b,c;
public:
	Color(int a = 0, int b = 0, int c=0) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	void show() {
		cout << " " << a << " " << b << " " << c << endl;
	}
	bool operator==(Color bora) {
		if (a == bora.a && b == bora.b && c == bora.c)
			return true;
		else
			return false;
	}
	Color operator+(Color color) {
		Color temp;
		temp.a = a + color.a;
		temp.b = b + color.b;
		temp.c = c + color.c;
		return temp;
	}
};
	int main() {
		Color red(255, 0, 0), blue(0, 0, 255), c;
		c = red + blue;
		c.show();
		Color fuchsia(255, 0, 255);
		if (c == fuchsia)
			cout << "보라색 맞음";
		else
			cout << "보라색 아님";
	}
