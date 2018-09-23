//
// Created by jakub on 20.09.18.
//

#include "union_find.hpp"
#include <utility>
#include <iostream>
#include <cassert>

using namespace std;

union_find::union_find(int size) {
    this->parent = new int[size];
    this->treeSize = new int[size];
    this->size = size;
    for (auto i = 0; i < size; ++i) {
        parent[i] = i;
        treeSize[i] = 0;
    }
}

union_find::~union_find() {
    delete this->parent;
}

bool union_find::is_connected(int p, int q) {
    assert(p >= 0 && p < size);
    assert(q >= 0 && q < size);

    return find_root(p) == find_root(q);
}

void union_find::make_union(int p, int q) {
    cout << "==== union(" << p << "," << q << ")" << endl;
    assert(p >= 0 && p < size);
    assert(q >= 0 && q < size);

    auto roots = find_roots_balanced(p, q);
    if (roots.first == roots.second) return;

    cout << "= parent[" << roots.second << "]=" << roots.first << endl;
    parent[roots.second] = roots.first;
    if (treeSize[roots.first] == treeSize[roots.second]) {
        treeSize[roots.first] += 1;
    }
    cout << "====" << endl;
}

int union_find::find_root(int p) {
    assert(p >= 0 && p < size);
    for (; p != parent[p]; p = parent[p]);
    return p;
}

void union_find::print() {
    cout << "    ";
    for (auto i = 0; i < size; ++i) {
        cout << " " << i;
    }
    cout << endl << "id[]";
    for (auto i = 0; i < size; ++i) {
        cout << " " << parent[i];
    }
    cout << endl << "sz[]";
    for (auto i = 0; i < size; ++i) {
        cout << " " << treeSize[i];
    }
    cout << endl;

}

std::pair<int, int> union_find::find_roots_balanced(int p, int q) {
    int rootP = find_root(p);
    int rootQ = find_root(q);
    return treeSize[rootP] < treeSize[rootQ] ?
           std::pair<int, int>(rootQ, rootP) :
           std::pair<int, int>(rootP, rootQ);
}




