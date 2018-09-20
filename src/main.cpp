#include <iostream>
#include "linked_list.hpp"

using namespace std;

int main() {
    linked_list<int> list;

    auto node1 = linked_node<int>(10);
    auto node2 = linked_node<int>(20);
    auto node3 = linked_node<int>(30);
    auto node4 = linked_node<int>(40);
    list.append(&node1);
    cout << "Added element1" << endl;
    list.append(&node2);
    cout << "Added element2" << endl;
    list.append(&node3);
    cout << "Added element3" << endl;
    list.append(&node4);
    cout << "Added element4" << endl;

    for (auto node = list.first(); node != nullptr; node = list.next()) {
        cout << "Element: " << node->value << endl;
    }
    cout << "First element: " << list.first()->value << endl;
    cout << "Last element: " << list.last()->value << endl;

    cout << "[]Remove element 3" << endl;
    list.remove(&node3);
    for (auto node = list.first(); node != nullptr; node = list.next()) {
        cout << "Element: " << node->value << endl;
    }
    cout << "First element: " << list.first()->value << endl;
    cout << "Last element: " << list.last()->value << endl;

    cout << "[]Remove element 1" << endl;
    list.remove(&node1);
    for (auto node = list.first(); node != nullptr; node = list.next()) {
        cout << "Element: " << node->value << endl;
    }
    cout << "First element: " << list.first()->value << endl;
    cout << "Last element: " << list.last()->value << endl;

    cout << "[]Remove element 4" << endl;
    list.remove(&node4);
    for (auto node = list.first(); node != nullptr; node = list.next()) {
        cout << "Element: " << node->value << endl;
    }
    cout << "First element: " << list.first()->value << endl;
    cout << "Last element: " << list.last()->value << endl;

    cout << "[]Remove element 2" << endl;
    list.remove(&node2);
    for (auto node = list.first(); node != nullptr; node = list.next()) {
        cout << "Element: " << node->value << endl;
    }
    cout << "First element: " << list.first()->value << endl;
    cout << "Last element: " << list.last()->value << endl;

    return 0;
}