#include<string>
using namespace std;
class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) { 
		this->title = title; 
		this->price = price; 
		this->pages = pages; 
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	friend bool operator==(const Book& b, int x);
	friend bool operator==(const Book& b, const string& s);
	friend bool operator==(const Book& b1, const Book& b2);
};
bool operator==(const Book& b, int x) {
	return b.price == x;
}
bool operator==(const Book& b, const string& s) {
	return b.title == s;
}
bool operator==(const Book& b1, const Book& b2) {
	return (b1.title == b2.title && b1.price == b2.price && b1.pages == b2.pages);
}
int main() {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000) cout << "정가 30000원" << endl;
	if (a == "명품 C++") cout << "명품 C++입니다." << endl;
	if (a == b) cout << "같은 책입니다." << endl;
}