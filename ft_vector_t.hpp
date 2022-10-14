#ifndef FT_VECTOR_T_HPP
#define FT_VECTOR_T_HPP

#include <cmath>
#include <memory>
#include <iostream>
#include <sstream>

//#include "is_integral.hpp"
//#include "normal_iterator.hpp"
#include "ft_revers_it.hpp"
#include "ft_lexicographical_compare.hpp"

namespace ft {
template<
    class T,
    class Allocator = std::allocator<T>
> class vector{
    public
    public:
    typedef typename Allocator::pointer          			pointer;
    typedef typename Allocator::const_pointer    			const_pointer;
    typedef typename Allocator::reference        			reference;
    typedef typename Allocator::const_reference  			const_reference;

    typedef ft::normal_iterator<pointer, vector>        iterator;
    typedef ft::normal_iterator<const_pointer, vector>  const_iterator;
    typedef ft::reverse_iterator<iterator>       		reverse_iterator;
    typedef ft::reverse_iterator<const_iterator> 		const_reverse_iterator;

    typedef T                                       	value_type;
    typedef std::size_t                                 size_type;
    typedef Allocator                                   	allocator_type;
    typedef typename iterator::difference_type      	difference_type;

private:
    allocator_type     _alloc;
    pointer            _beg;
    pointer            _data_end;
    pointer            _storage_end;
};
}
#endif