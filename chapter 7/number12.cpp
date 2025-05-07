#include <iostream>
#include <algorithm>
using namespace std;
class SortedArray {
    int size; 
    int* p;  
    void sort() {
        std::sort(p, p + size);
    }
public:
    SortedArray() : size(0), p(nullptr) {}
    SortedArray(SortedArray& src) : size(src.size) {
        p = new int[size];
        for (int i = 0; i < size; i++) {
            p[i] = src.p[i];
        }
    }
    SortedArray(int arr[], int size) : size(size) {
        p = new int[size];
        for (int i = 0; i < size; i++) {
            p[i] = arr[i];
        }
        sort();
    }
    ~SortedArray() {
        delete[] p;
    }
    SortedArray& operator=(const SortedArray& src) {
        delete[] p;
        size = src.size;
        p = new int[size];
        for (int i = 0; i < size; i++) {
            p[i] = src.p[i];
        }
        return *this;
    }
    SortedArray operator+(SortedArray& op2) {
        int newSize = size + op2.size;
        int* newArray = new int[newSize];
        for (int i = 0; i < size; i++) {
            newArray[i] = p[i];
        }
        for (int i = 0; i < op2.size; i++) {
            newArray[size + i] = op2.p[i];
        }
        SortedArray temp(newArray, newSize);
        delete[] newArray;
        return temp;
    }
    void show() {
        cout << "배열 출력 : ";
        for (int i = 0; i < size; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int n[] = { 2, 20, 6 };
    int m[] = { 10, 7, 8, 30 };
    SortedArray a(n, 3), b(m, 4), c;
    c = a+b;
    a.show();
    b.show();
    c.show();
}