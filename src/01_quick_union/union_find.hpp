//
// Created by jakub on 20.09.18.
//

#ifndef CPP_PLAYGROUND_UNION_FIND_HPP
#define CPP_PLAYGROUND_UNION_FIND_HPP

namespace std {
    template<class T, class P>
    class pair;
}

class union_find {
public:
    explicit union_find(int size);

    ~union_find();

    bool is_connected(int p, int q);

    void make_union(int p, int q);

    int find_root(int p);

    std::pair<int, int> find_roots_balanced(int p, int q);

    void print();

    int get_max_depth();

private:
    int *subtreeParent;
    int *subtreeDepth;
    int size;
    int maxDepth;
};


#endif //CPP_PLAYGROUND_UNION_FIND_HPP
