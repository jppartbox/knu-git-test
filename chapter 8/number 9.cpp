#include <iostream>
#include <string>
using namespace std;
class Seat {
    string name;
public:
    Seat() : name("----") {}
    bool isEmpty() { return name == "----"; }
    void reserve(string name) { this->name = name; }
    void cancel() { this->name = "----"; }
    void show() { cout << name << "\t"; }
    string getName() { return name; }
};
class Schedule {
    string time;
    Seat seats[8];
public:
    Schedule(string t) : time(t) {}
    void show() {
        cout << time << "시: ";
        for (int i = 0; i < 8; i++) {
            seats[i].show();
        }
        cout << endl;
    }
    bool reserve(int seatNum, string name) {
        if (seatNum < 0 || seatNum >= 8 || !seats[seatNum].isEmpty()) return false;
        seats[seatNum].reserve(name);
        return true;
    }
    bool cancel(int seatNum, string name) {
        if (seatNum < 0 || seatNum >= 8) return false;
        if (seats[seatNum].getName() == name) {
            seats[seatNum].cancel();
            return true;
        }
        return false;
    }
    string getTime() { return time; }
};
class Console {
public:
    static int selectMenu() {
        cout << "예약:1, 취소:2, 보기:3, 끝내기:4>>";
        int menu;
        cin >> menu;
        return menu;
    }
    static int selectTime() {
        cout << "07시:1 12시:2 17시:3>> ";
        int sel;
        cin >> sel;
        return sel - 1;
    }
    static int getSeatNumber() {
        int num;
        cout << "좌석 번호>> ";
        cin >> num;
        return num - 1;
    }
    static string getName() {
        string name;
        cout << "이름 입력>> ";
        cin >> name;
        return name;
    }
};
class AirlineBook {
    Schedule* schedules[3];
public:
    AirlineBook() {
        schedules[0] = new Schedule("07");
        schedules[1] = new Schedule("12");
        schedules[2] = new Schedule("17");
    }
    ~AirlineBook() {
        for (int i = 0; i < 3; i++) delete schedules[i];
    }
    void showAll() {
        for (int i = 0; i < 3; i++) schedules[i]->show();
    }
    void reserve() {
        int time = Console::selectTime();
        int seat = Console::getSeatNumber();
        string name = Console::getName();
        if (time < 0 || time >= 3) {
            cout << "잘못된 시간 선택입니다.\n";
            return;
        }
        if (schedules[time]->reserve(seat, name)) {
            cout << "예약이 완료되었습니다.\n";
        } else {
            cout << "예약에 실패했습니다. 좌석이 이미 예약되었거나 잘못된 좌석 번호입니다.\n";
        }
    }
    void cancel() {
        int time = Console::selectTime();
        int seat = Console::getSeatNumber();
        string name = Console::getName();
        if (time < 0 || time >= 3) {
            cout << "잘못된 시간 선택입니다.\n";
            return;
        }
        if (schedules[time]->cancel(seat, name)) {
            cout << "예약이 취소되었습니다.\n";
        } else {
            cout << "취소에 실패했습니다. 이름이 일치하지 않거나 잘못된 좌석 번호입니다.\n";
        }
    }
    void run() {
        while (true) {
            int menu = Console::selectMenu();
            switch (menu) {
            case 1: reserve(); break;
            case 2: cancel(); break;
            case 3: showAll(); break;
            case 4: cout << "예약 시스템을 종료합니다..\n"; return;
            default: cout << "잘못된 메뉴입니다.\n"; break;
            }
        }
    }
};
int main() {
    AirlineBook book;
    cout << "****** 한성항공에 오신것을 환영합니다 ******\n\n";
    book.run();
    return 0;
}