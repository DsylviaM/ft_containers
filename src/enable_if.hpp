#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

#include  "is_integral.hpp"

//  enable_if
// https://runebook.dev/ru/docs/cpp/types/is_same

namespace ft {

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

template<class T, class U>
struct is_same : integral_false_type {};
 
template<class T>
struct is_same<T, T> : integral_true_type {};

template <class T1, class T2>
bool
    is_same_f(T1 , T2 ) {
        return (false);
    }

template <class T1>
bool
    is_same_f(T1 , T1 ) {
        return (true);
    }
} 

#endif
