//
// Created by jakub on 20.09.18.
//

#include "union_find.hpp"
#include <cassert>

union_find::union_find(int size) {
    this->fields = new int[size];
    this->size = size;
    for (auto i = 0; i < size; ++i) {
        fields[i] = i;
    }
}

union_find::~union_find() {
    delete this->fields;
}

bool union_find::is_connected(int p, int q) {
    assert(p >= 0 && p < size);
    assert(q >= 0 && q < size);
    return fields[p] == fields[q];
}

void union_find::make_union(int p, int q) {
    assert(p >= 0 && p < size);
    assert(q >= 0 && q < size);

    auto pid = fields[p];
    auto qid = fields[q];
    for (auto i = 0; i < size; ++i) {
        if (fields[i] == pid) fields[i] = qid;
    }
}




