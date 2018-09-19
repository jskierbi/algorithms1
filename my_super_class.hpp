//
// Created by jakub on 19.09.18.
//

#ifndef CPP_PLAYGROUND_MY_SUPER_CLASS_HPP
#define CPP_PLAYGROUND_MY_SUPER_CLASS_HPP


class my_super_class {
public:
    my_super_class();

    void doSomething(const int& number1, const char* string);

private:
    int number;
    char* string;

    int calculate();
};


#endif //CPP_PLAYGROUND_MY_SUPER_CLASS_HPP
