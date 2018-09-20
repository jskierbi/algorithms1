//
// Created by jakub on 20.09.18.
//

#ifndef CPP_PLAYGROUND_LINKED_LIST_HPP
#define CPP_PLAYGROUND_LINKED_LIST_HPP

template<class T>
class linked_node;

template<class T>
class linked_list {
public:
    linked_list() {
        _first = nullptr;
        _last = nullptr;
        _curr = nullptr;
    }

    linked_node<T> *next() {
        _curr = _curr == nullptr ? _first : _curr->next;
        return _curr;
    }

    linked_node<T> *prev() {
        _curr = _curr == nullptr ? nullptr : _curr->prev;
        return _curr;
    }

    linked_node<T> *last() {
        return _last;
    }

    linked_node<T> *first() {
        _curr = _first;
        return _first;
    }

    linked_node<T> *append(linked_node<T> *element) {
        element->prev = _last;
        element->next = nullptr;
        if (_first == nullptr) _first = element;
        if (_last != nullptr) _last->next = element;
        _last = element;
        return element;
    }

    void remove(linked_node<T> *element) {
        // This is double linked list, we can use linkage from node
        if (element->prev != nullptr) element->prev->next = element->next;
        if (element->next != nullptr) element->next->prev = element->prev;

        if (element == _first) _first = element->next;
        if (element == _last) _last = element->prev;
        if (element == _curr) _curr = nullptr;

        // Alternate implementations (for single linked queue)
        // I could use:
        //      a) reference to an object cointaining next pointer (not covering edge cases then!)
        //      b) pointer to an object containing next pointer
        //      c) pointer to a next pointer - then I don't need to keep address of an object at all!
        // Code below works only for single linked list

        //    auto indirectFwd = &_first;
        //
        //    while ((*indirectFwd) != element && (*indirectFwd) != nullptr) {
        //        indirectFwd = &(*indirectFwd)->next;
        //    }
        //
        //    if (*indirectFwd != nullptr) {
        //        *indirectFwd = element->next;
        //    }

        //    auto fwd = _first;
        //    while (fwd->next != element && fwd->next != nullptr) {
        //        fwd = fwd->next;
        //    }
        //
        //    if (fwd != nullptr) {
        //        fwd->next = element->next;
        //    }
    }

private:
    linked_node<T> *_first;
    linked_node<T> *_last;
    linked_node<T> *_curr;  // this is "kind" of iterator inside linked_list class
    // Not sure if this is a good pattern
};

template<class T>
class linked_node {
public:
    explicit linked_node(T value) {
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }

    T value;

    linked_node<T> *next;
    linked_node<T> *prev;
};

#endif //CPP_PLAYGROUND_LINKED_LIST_HPP
