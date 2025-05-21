#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;

public:
    Printer(string model, string manufacturer, int availableCount)
        : model(model), manufacturer(manufacturer), availableCount(availableCount), printedCount(0) {}

    virtual void print(int pages) = 0; 
    virtual void show() = 0;           
    virtual ~Printer() {}
};

class InkJetPrinter : public Printer {
    int availableInk;

public:
    InkJetPrinter(string model, string manufacturer, int availableCount, int ink)
        : Printer(model, manufacturer, availableCount), availableInk(ink) {}

    void print(int pages) override {
        if (availableCount >= pages && availableInk >= pages) {
            availableCount -= pages;
            availableInk -= pages;
            printedCount += pages;
            cout << "프린트하였습니다.\n";
        }
        else {
            cout << "용지가 부족하여 프린트할 수 없습니다.\n";
        }
    }

    void show() override {
        cout << "\n잉크젯 : " << model << ", " << manufacturer
            << ", 남은 종이 " << availableCount << "장, 남은 잉크 " << availableInk << endl;
    }
};

class LaserPrinter : public Printer {
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int availableCount, int toner)
        : Printer(model, manufacturer, availableCount), availableToner(toner) {}

    void print(int pages) override {
        if (availableCount >= pages && availableToner >= pages) {
            availableCount -= pages;
            availableToner -= pages;
            printedCount += pages;
            cout << "프린트하였습니다.\n";
        }
        else {
            cout << "용지가 부족하여 프린트할 수 없습니다.\n";
        }
    }

    void show() override {
        cout << "레이저 : " << model << ", " << manufacturer
            << ", 남은 종이 " << availableCount << "장, 남은 토너 " << availableToner << endl;
    }
};

int main() {
    Printer* printers[2];
    printers[0] = new InkJetPrinter("Officejet V40", "HP", 5, 10);
    printers[1] = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

    cout<<"현재 작동중인 2대의 프린터는 아래와 같다.\n";
    char cont = 'y';
    while (cont == 'y') {
        for (int i = 0; i < 2; i++)
            printers[i]->show();

        int choice, pages;
        cout << "\n프린터(1:잉크젯, 2:레이저)와 매수 입력>> ";
        cin >> choice >> pages;

        if (choice == 1 || choice == 2)
            printers[choice - 1]->print(pages);
        else
            cout << "잘못된 선택입니다.\n";

        for (int i = 0; i < 2; i++)
            printers[i]->show();

        cout << "계속 프린트 하시겠습니까(y/n)>> ";
        cin >> cont;
    }

    delete printers[0];
    delete printers[1];
    return 0;
}