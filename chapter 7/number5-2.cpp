#include<iostream>
#include<string>
using namespace std;

class Color {
    int a, b, c;
public:
    Color(int a = 0, int b = 0, int c = 0) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void show() {
        cout << " " << a << " " << b << " " << c << endl;
    }

    // friend 함수로 선언
    friend bool operator==(Color c1, Color c2);
    friend Color operator+(Color c1, Color c2);
};

// friend 함수 정의
bool operator==(Color c1, Color c2) {
    return (c1.a == c2.a && c1.b == c2.b && c1.c == c2.c);
}

Color operator+(Color c1, Color c2) {
    return Color(c1.a + c2.a, c1.b + c2.b, c1.c + c2.c);
}

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