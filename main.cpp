#include <iostream>
#include "my_super_class.hpp"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    my_super_class a;
    a.doSomething(1, "this is a string!");
    return 0;
}