#include "union_find.hpp"
#include "percolator.hpp"
#include <iostream>

using namespace std;

int main() {
    percolator p(10000, 10000);
    auto ops = 0;
    while (p.is_percolated() == false) {
        p.uncover_next();
        ++ops;
    }
    cout << "Ratio: " << p.ratio() << " ops: " << ops << endl;

    return 0;
}