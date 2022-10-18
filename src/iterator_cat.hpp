#ifndef ITERATOR_CAT_HPP
#define ITERATOR_CAT_HPP

#include "iterator.hpp"
#include "iterator_body.hpp"
#include <iostream>

//TEMPLATE FUNCTION Iter_cat (шаблонная функция Iter_cat)
//iterator+iterator_trains from iterator
//page 116 book "The C++ Standart Template Library"

namespace ft {

template <
    typename iterTag,
    typename T,
    typename Dist,
    typename Pt,
    typename Rt>
    iterTag    Iter_cat(const iterator_base< iterTag, T, Dist, Pt, Rt> &) {
    // std::cout << "_iterTag Iter_cat\n";
    iterTag object;
    return (object);
}

template < class T >
::ft::random_access_iterator_tag
    Iter_cat(const T *) {
    // std::cout << "rand Iter_cat\n";
    ::ft::random_access_iterator_tag object;
    return (object);
}

template < class T >
ft::input_iterator_tag
    Iter_cat(const T ) {
    // std::cout << "std_input_iterator_tag Iter_cat\n";
    ft::input_iterator_tag object;
    return (object);
}

//INTEGER FUNCTION Iter_cat 

 int_iterator_tag    Iter_cat(bool) {
    int_iterator_tag object;
    return (object);
}

int_iterator_tag    Iter_cat(char) {
    int_iterator_tag object;
    return (object);
}

int_iterator_tag    Iter_cat(signed char) {
    int_iterator_tag object;
    return (object);
}

int_iterator_tag    Iter_cat(unsigned char) {
    int_iterator_tag object;
    return (object);
}

int_iterator_tag    Iter_cat(wchar_t) {
    int_iterator_tag object;
    return (object);
}

int_iterator_tag    Iter_cat(short) {
    int_iterator_tag object;
    return (object);
}

int_iterator_tag    Iter_cat(unsigned short) {
    int_iterator_tag object;
    return (object);
}

int_iterator_tag    Iter_cat(int) {
    int_iterator_tag object;
        // std::cout << "int Iter_cat\n";
    return (object);
}

int_iterator_tag    Iter_cat(unsigned int) {
    int_iterator_tag object;
    return (object);
}

int_iterator_tag    Iter_cat(long) {
    int_iterator_tag object;
    return (object);
}

int_iterator_tag    Iter_cat(unsigned long) {
    int_iterator_tag object;
    return (object);
}

}

#endif
