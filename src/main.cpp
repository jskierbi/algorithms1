#include <iostream>
#include <cassert>
#include "union_find.hpp"

using namespace std;

int main() {
    union_find f(10);

    f.make_union(1, 5);
    f.make_union(5, 6);
    f.make_union(6, 7);

    assert(f.is_connected(1, 7));
    assert(f.is_connected(1, 1));

    return 0;
}