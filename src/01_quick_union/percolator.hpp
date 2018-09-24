//
// Created by jakub on 24.09.18.
//

#ifndef ALGORITHMS1_PERCOLATOR_HPP
#define ALGORITHMS1_PERCOLATOR_HPP

#import "union_find.hpp"

class percolator {
public:
    percolator(int width, int height);

    ~percolator();

    void uncover_next();

    bool is_percolated();

    void print();

    float ratio();

private:
    union_find uf;
    bool* fields;
    int uncovered;
    int width;
    int height;
    const int percSize;
    const int startNode;
    const int endNode;

};


#endif //ALGORITHMS1_PERCOLATOR_HPP
