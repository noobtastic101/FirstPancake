/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 */

#ifndef INC_1_PAIR_H
#define INC_1_PAIR_H


template <class T> class Pair {
public:
    T left;
    T right;

    Pair(T left, T right) : left(left), right(right) {}

    Pair() {}
};


#endif //INC_1_PAIR_H
