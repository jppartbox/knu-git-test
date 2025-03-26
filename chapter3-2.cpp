#include<iostream>
#include<string>
using namespace std;

class Date {
public:
	int year,y;
	int month,m;
	int day,d;
	Date(string r);
	Date(int a, int b, int c);
	void show();
	int getyear();
	int getmonth();
	int getday();
};

Date::Date(string r) {	
	int a1 = r.find('/');
	int a2 = r.find('/',a1 + 1);
	int num1 = stoi(r.substr(0, a1));
	int num2 = stoi(r.substr(a1+1, a2));
	int num3 = stoi(r.substr(a2 + 1));
	y = num1;
	m = num2;
	d = num3;
}
void Date::show() {
	cout << y << "³â" << m << "¿ù" << d << "ÀÏ" << endl;
}
Date::Date(int a, int b, int c) {
	year = a;
	month = b;
	day = c;
}

int Date::getyear() {
	return year;
}

int Date::getmonth() {
	return month;
}

int Date::getday() {
	return day;
}

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getyear() << ',' << birth.getmonth() << ',' << birth.getday()<<endl;
}