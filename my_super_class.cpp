//
// Created by jakub on 19.09.18.
//

#include "my_super_class.hpp"
#include <iostream>

using namespace std;

my_super_class::my_super_class() = default;

void my_super_class::doSomething(const int &number1, const char *string) {
    cout << "Number: " << number1 << " and a string: " << string << endl;
    cout << "Calling calculate: " << calculate() << endl;
}

int my_super_class::calculate() {
    static int value = 0;
    return ++value;
}
