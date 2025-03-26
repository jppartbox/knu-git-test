#include <iostream>
using namespace std;

#include "Ram.h"

Ram::Ram() {
    for (int i = 0; i < 100 * 1024; i++) {
        mem[i] = 0;
    }
    size = 100 * 1024;
}

Ram::~Ram() {
    cout << "메모리 제거됨" << endl;
}

char Ram::read(int address) {
    if (address >= 0 && address < size) {
        return mem[address];
    }
    return 0;
}

void Ram::write(int address, char value) {
    if (address >= 0 && address < size) {
        mem[address] = value;
    }
}