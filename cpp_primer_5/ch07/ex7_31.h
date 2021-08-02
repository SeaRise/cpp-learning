//
// Created by searise on 7/29/21.
//

#ifndef CPP_LEARNING_EX7_31_H
#define CPP_LEARNING_EX7_31_H


class Y;

class X {
    // Y被声明后，可以持有对Y的指针
    Y *y;
};

class Y {
    // X被定义后，才可以持有X实例.
    X x;
};

#endif //CPP_LEARNING_EX7_31_H
