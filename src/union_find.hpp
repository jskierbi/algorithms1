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

private:
    int* fields;
    int size;
};


#endif //CPP_PLAYGROUND_UNION_FIND_HPP
