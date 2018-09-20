//
// Created by jakub on 20.09.18.
//

#include "union_find.hpp"
#include <cassert>

union_find::union_find(int size) {
    this->parent = new int[size];
    this->size = size;
    for (auto i = 0; i < size; ++i) {
        parent[i] = i;
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
    assert(p >= 0 && p < size);
    assert(q >= 0 && q < size);
    auto rootP = find_root(p);
    auto rootQ = find_root(q);
    parent[rootP] = rootQ;
}

int union_find::find_root(int p) {
    assert(p >= 0 && p < size);
    for (; p != parent[p]; p = parent[p]);
    return p;
}




