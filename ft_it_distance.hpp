#ifndef IT_DISTANCE_HPP
#define IT_DISTANCE_HPP

#include "ft_iterator_body.hpp"
#include "ft_iterator.hpp"
#include "ft_iterator_cat.hpp"

//page 118 book "The C++ Standart Template Library"

namespace ft {

template< class InIt >
typename iterator_traits<InIt>::difference_type
    distance( InIt first, InIt last ) {
        typename iterator_traits<InIt>::difference_type  dist = 0;
        distance_catigory(first, last, dist, Iter_cat(first));
        return (dist);
    }
template< class InIt, class D >
void
    distance_catigory( InIt
 first, InIt
 last, D& dist, ::ft::input_iterator_tag ) {
        for (; first != last; ++first) {
            ++dist;
        }
    }

template< class InIt, class D >
void
    distance_catigory( InIt
 first, InIt
 last, D& dist, ::ft::forward_iterator_tag ) {
        for (; first != last; ++first) {
            ++dist;
        }
    }

template< class InIt, class D >
void
    distance_catigory( InIt
 first, InIt
 last, D& dist, ::ft::bidirectional_iterator_tag ) {
        for (; first != last; ++first) {
            ++dist;
        }
    }

template< class InIt, class D >
void
    distance_catigory( InIt
 first, InIt
 last, D& dist, ::ft::random_access_iterator_tag ) {
        dist += last - first;
    }

}


#endif