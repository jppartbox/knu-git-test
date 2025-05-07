#include <iostream>
using namespace std;

class Statistics {
    int data[100];
    int size;      
public:
    Statistics() : size(0) {} 
    bool operator!() const {
        return size == 0;
    }
    Statistics& operator<<(int value) {
        data[size++] = value;
        return *this;
    }
    void operator~() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    Statistics& operator>>(int& avg) {
        if (size == 0) {
            avg = 0;
        }
        else {
            int sum = 0;
            for (int i = 0; i < size; i++) {
                sum += data[i];
            }
            avg = sum / size;
        }
        return *this;
    }
};

int main() {
	Statistics stat;
	if (!stat)cout << "현재 통계 데이터가 없습니다." << endl;
	int x[5];
	cout<<"정수 5개를 입력해라>> ";
	for (int i = 0; i < 5; i++) cin >> x[i];
	for (int i = 0; i < 5; i++) stat << x[i];
	stat << 100 << 200;
	~stat;
	int avg;
	stat >> avg;
	cout << "입력한 정수의 평균은 " << avg << "입니다." << endl;
}