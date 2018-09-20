#include <iostream>
#include "union_find.hpp"

using namespace std;

int main() {
    union_find f(10);

    cout << "connected(1,5): " << f.is_connected(1, 5) << endl;
    f.make_union(1,5);
    cout << "union made." << endl;
    cout << "connected(1,5): " << f.is_connected(1, 5) << endl;

    return 0;
}