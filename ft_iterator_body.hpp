#ifndef ITERATOR_BADY_HPP
#define ITERATOR_BADY_HPP

#include <cstddef>
#include <ft_iterator.hpp>
//#include <iterator_traits.hpp>


namespace ft {
// template struct iterator (for inheritance)
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

// OUTPUT iterator
struct OutIt : public iterator_base< ::ft::output_iterator_tag, void, void, void, void> {};
//
//
// BIDIRECTIONAL iterator
template <
    typename _iterTag,
    typename _T,
    typename _Dist = std::ptrdiff_t,
    typename _Pt = _T*,
    typename _Rt = _T&>
struct bidirIt : public iterator_base< ::std::bidirectional_iterator_tag, _T, _Dist, _Pt, _Rt> {};
//
//
// RANDOM access iterator
template <
    typename _iterTag,
    typename _T,
    typename _Dist = std::ptrdiff_t,
    typename _Pt = _T*,
    typename _Rt = _T&>
struct RandomIt : public iterator_base< ::std::random_access_iterator_tag, _T, _Dist, _Pt, _Rt> {};
} // namespace ft

#endif