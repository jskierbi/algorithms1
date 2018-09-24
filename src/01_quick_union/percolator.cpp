//
// Created by jakub on 24.09.18.
//
#include "percolator.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

percolator::percolator(int width, int height) :
        uf(width * height + 2),
        uncovered(0),
        width(width),
        height(height),
        percSize(width * height),
        startNode(percSize),
        endNode(percSize + 1) {

    fields = new bool[percSize];
    for (auto i = 0; i < percSize; ++i) {
        fields[i] = false;
    }

    auto firstLine = 0;
    auto lastLine = percSize - width;
    for (auto i = 0; i < width; ++i) {
        uf.make_union(startNode, firstLine + i);
        uf.make_union(endNode, lastLine + i);
    }
}

percolator::~percolator() {
    delete fields;
}

void percolator::uncover_next() {
    auto element = rand() % percSize;
    while (fields[element] == true) {
        element = (element + 1) % percSize;
    }
    fields[element] = true;
    ++uncovered;

    // Make connections
    auto line = element / width;
    auto column = element % width;

    if (line != 0 && fields[element - width]) uf.make_union(element, element - width);
    if (line != height - 1 && fields[element + width]) uf.make_union(element, element + width);
    if (column != 0 && fields[element - 1]) uf.make_union(element, element - 1);
    if (column != width - 1 && fields[element + 1]) uf.make_union(element, element + 1);
}

bool percolator::is_percolated() {
    return uf.is_connected(startNode, endNode);
}

void percolator::print() {
    cout << "=========" << endl;
    auto el = 0;
    for (auto i = 0; i < height; ++i) {
        for (auto j = 0; j < width; ++j) {
            cout << (fields[el] ? " " : "#");
            ++el;
        }
        cout << endl;
    }
    cout << "=========" << endl;
}

float percolator::ratio() {
    return (float) uncovered / (float) percSize;
}
