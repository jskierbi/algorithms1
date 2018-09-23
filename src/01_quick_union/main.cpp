#include "union_find.hpp"

int main() {
    union_find f(10);

//    f.print();
//    f.make_union(4, 3);
//    f.print();
//    f.make_union(3, 8);
//    f.print();
//    f.make_union(6, 5);
//    f.print();
//    f.make_union(9, 4);
//    f.print();
//    f.make_union(0, 5);
//    f.make_union(0, 4);
//    f.print();
//
//    f.make_union(1, 2);
//    f.make_union(1, 7);
//    f.make_union(1, 9);
//    f.print();

    f.make_union(0, 1);
    f.make_union(1, 2);
    f.make_union(2, 3);
    f.make_union(3, 4);
    f.make_union(4, 5);
    f.make_union(5, 6);
    f.make_union(6, 7);
    f.make_union(7, 8);
    f.make_union(8, 9);
    f.print();

    return 0;
}