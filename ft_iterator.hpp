#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <cstddef>

namespace ft{
    template <typename C, typename T, typename Dist = std::ptrdiff_t, typename Pt = T*, typename Rf = T&>
    struct iterator {
        typedef C iterator_category;
        typedef T value_type;
        typedef Dist difference_type;
        typedef Pt pointer;
        typedef Rf reference;
    };

    //iteratot teg
    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag 
         : public input_iterator_tag { };
    struct bidirectional_iterator_tag 
        : public forward_iterator_tag { };
    struct random_access_iterator_tag 
         : public bidirectional_iterator_tag { };
    struct int_iterator_tag;
    
    // Iterator traits
    template <class Iterator>
    struct iterator_traits {
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::difference_type   difference_type;
        typedef typename Iterator::iterator_category iterator_category;
	};

    template <class T>
    struct iterator_traits<T*> {
        typedef T*                             pointer;
        typedef T&                             reference;
        typedef T                              value_type;
        typedef ptrdiff_t                      difference_type;
        typedef ft::random_access_iterator_tag iterator_category;
    };

    template <class T>
    struct iterator_traits<const T*> {
        typedef const T*                       pointer;
        typedef const T&                       reference;
        typedef T                              value_type;
        typedef ptrdiff_t                      difference_type;
        typedef ft::random_access_iterator_tag iterator_category;
    };
}
#endif