//
// Created by jakub on 20.09.18.
//
#include "union_find.hpp"
#include <utility>
#include <iostream>
#include <cassert>

using namespace std;

union_find::union_find(int size) {
    this->subtreeParent = new int[size];
    this->subtreeDepth = new int[size];
    this->size = size;
    for (auto i = 0; i < size; ++i) {
        subtreeParent[i] = i;
        subtreeDepth[i] = 0;
    }
}

union_find::~union_find() {
    delete this->subtreeParent;
}

bool union_find::is_connected(int p, int q) {
    assert(p >= 0 && p < size);
    assert(q >= 0 && q < size);

    return find_root(p) == find_root(q);
}

void union_find::make_union(int p, int q) {
    assert(p >= 0 && p < size);
    assert(q >= 0 && q < size);

    auto roots = find_roots_balanced(p, q);
    if (roots.first == roots.second) return;

    subtreeParent[roots.second] = roots.first;
    if (subtreeDepth[roots.first] == subtreeDepth[roots.second]) {
        subtreeDepth[roots.first] += 1;
        maxDepth = subtreeDepth[roots.first];
    }
}

int union_find::find_root(int p) {
    assert(p >= 0 && p < size);
    for (; p != subtreeParent[p]; p = subtreeParent[p]) {
        subtreeParent[p] = subtreeParent[subtreeParent[p]]; // path compression
    }
    return p;
}

void union_find::print() {
    cout << "    ";
    for (auto i = 0; i < size; ++i) {
        cout << " " << i;
    }
    cout << endl << "id[]";
    for (auto i = 0; i < size; ++i) {
        cout << " " << subtreeParent[i];
    }
    cout << endl << "sz[]";
    for (auto i = 0; i < size; ++i) {
        cout << " " << subtreeDepth[i];
    }
    cout << endl;

}

std::pair<int, int> union_find::find_roots_balanced(int p, int q) {
    int rootP = find_root(p);
    int rootQ = find_root(q);
    return subtreeDepth[rootP] < subtreeDepth[rootQ] ?
           std::pair<int, int>(rootQ, rootP) :
           std::pair<int, int>(rootP, rootQ);
}

int union_find::get_max_depth() {
    return maxDepth;
}




