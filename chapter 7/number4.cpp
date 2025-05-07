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
		bool operator<(string s);
};
	bool Book::operator<(string s) {
		if (s < this->title)
			return true;
	}
	int main() {
		Book a("청춘", 20000, 500);
		string b;
		cout << "책 제목을 입력하세요: ";
		getline(cin, b);
		if (a < b)
			cout <<a.getTitle()<<"이 " <<b<<"보다 뒤에 있구나!"<< endl;
	}