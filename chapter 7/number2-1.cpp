#include<iostream>
#include<string>
using namespace std;
class Book {
	string title;
	int price, pages;
	public:
		Book(string title = "", int price = 0, int pages = 0) { this->title = title; this->price = price; this->pages = pages; }
		void show() {
			cout<<title<<' '<<price<<"원 "<<pages<<" 페이지"<<endl;
		}
		string getTitle() { return title; }
		bool operator==(int x);
		bool operator==(string s);
		bool operator==(Book b) {
			if (this->title == b.title && this->price == b.price && this->pages == b.pages)
				return true;
			else
				return false;
		}
};
	bool Book::operator==(int x) {
		if (this->price == x)
		return true;
	}
	bool Book::operator==(string s) {
		if (this->title == s)
			return true;
	}
int main() {
	Book a("명품 C++",30000, 500), b("고품 C++", 30000, 500);
	if(a == 30000) cout << "정가 30000원" <<endl;
	if(a == "명품 C++") cout << "명품 C++입니다."<<endl;
	if (a == b) cout << "같은 책입니다."<<endl; 
}