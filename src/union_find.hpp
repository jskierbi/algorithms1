//
// Created by jakub on 20.09.18.
//

#ifndef CPP_PLAYGROUND_UNION_FIND_HPP
#define CPP_PLAYGROUND_UNION_FIND_HPP


class union_find {
public:
    explicit union_find(int size);

    ~union_find();

    bool is_connected(int p, int q);

    void make_union(int p, int q);

    int find_root(int p);

private:
    int *parent;
    int size;
};


#endif //CPP_PLAYGROUND_UNION_FIND_HPP
