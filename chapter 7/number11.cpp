#include <iostream>
using namespace std;

class Stack {
    int data[100]; 
    int top;      
public:
    Stack() : top(-1) {}
    Stack& operator<<(int value) {
            data[++top] = value;
        return *this;
    }
    Stack& operator>>(int& value) {
            value = data[top--];
        return *this;
    }
    bool operator!() const {
        return top == -1;
    }
};

int main() {
    Stack stack;
    stack << 3 << 5 << 10;
    while (true) {
        if (!stack) break;
        int x;
        stack >> x;
        cout<< x << " ";
    }
    cout << endl;
}