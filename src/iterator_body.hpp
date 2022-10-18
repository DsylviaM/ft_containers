#ifndef ITERATOR_BADY_HPP
#define ITERATOR_BADY_HPP

#include <cstddef>
#include "iterator.hpp"
//#include <iterator_traits.hpp>

// template struct iterator
namespace ft {
template <
    typename iterTag,
    typename T,
    typename Dist = std::ptrdiff_t,
    typename Pt = T*,
    typename Rt = T&>
struct iterator_base {
    public:
    typedef iterTag   iterator_category;
    typedef T         value_type;
    typedef Dist      difference_type;
    typedef Rt        reference;
    typedef Pt        pointer;
};


// output_iterator_tag

struct Outit : public iterator_base < ::ft::output_iterator_tag, void, void, void,void> {};
   
// bidirectional_iterator_tag
template <
    typename iterTag,
    typename T,
    typename Dist = std::ptrdiff_t,
    typename Pt = T*,
    typename Rt = T&>
struct bidirIt : public iterator_base< ::ft::bidirectional_iterator_tag, T, Dist, Pt, Rt> {};

// random_access_iterator_tag
template <
    typename iterTag,
    typename T,
    typename Dist = std::ptrdiff_t,
    typename Pt = T*,
    typename Rt = T&>
struct RandomIt : public iterator_base< ::ft::random_access_iterator_tag, T, Dist, Pt, Rt> {};
} 

#endif
