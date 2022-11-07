#ifndef NORMAL_ITERATOR_HPP
#define NORMAL_ITERATOR_HPP

#include "iterator.hpp"
#include "iterator_body.hpp"
#include "enable_if.hpp"

namespace ft {

    template <class T, class Container>
    class normal_iterator
    {
        typedef iterator_traits<T> _traits_type;

        protected:
            T _current;

        public:
            typedef typename _traits_type::pointer             pointer;
            typedef typename _traits_type::reference           reference;
            typedef typename _traits_type::value_type          value_type;
            typedef typename _traits_type::difference_type     difference_type;
            typedef ft::random_access_iterator_tag 		       iterator_category;

        normal_iterator(void) 
        : _current(T()) { }

		explicit
		normal_iterator(const T& ptr)
        : _current(ptr) { }
        
        // Allow iterator to const_iterator conversion
        template<typename Iter>
        normal_iterator(
            const normal_iterator<Iter, 
		            typename enable_if< 
                    (ft::is_same<Iter, typename _traits_type::pointer> ::value), 
                    Container>::type> &iter)
        : _current(iter.base()) { }
      /*  
        // Allow iterator to const_iterator conversion
         template<typename _Iter>
         __normal_iterator(const __normal_iterator<_Iter,
               typename __enable_if<
                (std::__are_same<_Iter, typename _Container::pointer>::__value),
               _Container>::__type>& __i)
         : _M_current(__i.base()) { }*/

        // Forward iterator requirements
        reference operator*() const {
            return *_current;
        }

        pointer operator->() const {
            return _current;
        }

        normal_iterator& operator++() {
            ++_current;
            return *this;
        }

        normal_iterator operator++(int) {
            return normal_iterator(_current++);
        }

        // Bidirectional iterator requirements
        normal_iterator& operator--() {
		    --_current;
            return *this;
        }

        normal_iterator operator--(int) {
            return normal_iterator(_current--);
	    }


        // Random access iterator requirements
        reference operator[](difference_type n) const {
            return _current[n];
        }

        normal_iterator& operator+=(difference_type n) {
            _current += n;
            return *this;
        }

        normal_iterator operator+(difference_type n) const {
            return normal_iterator(_current + n);
        }

        normal_iterator& operator-=(difference_type n) {
            _current -= n;
            return *this;
        }

        normal_iterator operator-(difference_type n) const {
            return normal_iterator(_current - n);
        }

        const T base() const {
            return _current;
        }
    };

    // Non-member comparison overloads    
    // Note: In what follows, the left- and right-hand-side iterators are
    // allowed to vary in types (conceptually in cv-qualification) so that
    // comparaison between cv-qualified and non-cv-qualified iterators be
    // valid.  However, the greedy and unfriendly operators in std::rel_ops
    // will make overload resolution ambiguous (when in scope) if we don't
    // provide overloads whose operands are of the same type.  Can someone
    // remind me what generic programming is about? -- Gaby

    // Forward iterator requirements
    template <typename IteratorL, typename IteratorR, typename Container>
    bool operator==( const normal_iterator<IteratorL, Container>& lhs,
                     const normal_iterator<IteratorR, Container>& rhs ) {
        return lhs.base() == rhs.base();
    }

        template <typename Iterator, typename Container>
    bool operator==( const normal_iterator<Iterator, Container>& lhs,
                     const normal_iterator<Iterator, Container>& rhs ) {
        return lhs.base() == rhs.base();
    }
    template <typename IteratorL, typename IteratorR, typename Container>
    bool operator!=( const normal_iterator<IteratorL, Container>& lhs,
                     const normal_iterator<IteratorR, Container>& rhs ) {
        return lhs.base() != rhs.base();
    }

        template <typename Iterator, typename Container>
    bool operator!=( const normal_iterator<Iterator, Container>& lhs,
                     const normal_iterator<Iterator, Container>& rhs ) {
        return lhs.base() != rhs.base();
    }

    // Random access iterator requirements
    template <typename IteratorL, typename IteratorR, typename Container>
    bool operator<( const normal_iterator<IteratorL, Container>& lhs,
                    const normal_iterator<IteratorR, Container>& rhs ) {
        return lhs.base() < rhs.base();
    }

        template <typename Iterator, typename Container>
    bool operator<( const normal_iterator<Iterator, Container>& lhs,
                    const normal_iterator<Iterator, Container>& rhs ) {
        return lhs.base() < rhs.base();
    }

        template <typename IteratorL, typename IteratorR, typename Container>
    bool operator>( const normal_iterator<IteratorL, Container>& lhs,
                    const normal_iterator<IteratorR, Container>& rhs ) {
        return lhs.base() > rhs.base();
    }

        template <typename Iterator, typename Container>
    bool operator>( const normal_iterator<Iterator, Container>& lhs,
                    const normal_iterator<Iterator, Container>& rhs ) {
        return lhs.base() > rhs.base();
    }

    template <typename IteratorL, typename IteratorR, typename Container>
    bool operator<=( const normal_iterator<IteratorL, Container>& lhs,
                     const normal_iterator<IteratorR, Container>& rhs ) {
        return lhs.base() <= rhs.base();
    }

        template <typename Iterator, typename Container>
    bool operator<=( const normal_iterator<Iterator, Container>& lhs,
                     const normal_iterator<Iterator, Container>& rhs ) {
        return lhs.base() <= rhs.base();
    }

    template <typename IteratorL, typename IteratorR, typename Container>
    bool operator>=( const normal_iterator<IteratorL, Container>& lhs,
                     const normal_iterator<IteratorR, Container>& rhs ) {
        return lhs.base() >= rhs.base();
    }

        template <typename Iterator, typename Container>
    bool operator>=( const normal_iterator<Iterator, Container>& lhs,
                     const normal_iterator<Iterator, Container>& rhs ) {
        return lhs.base() >= rhs.base();
    }

    // According to the resolution of DR179 not only the various comparison
    // operators but also operator- must accept mixed iterator/const_iterator
    // parameters.

	template<typename IteratorL, typename IteratorR, typename Container>
    inline typename normal_iterator<IteratorL, Container>::difference_type
    operator-( const normal_iterator<IteratorL, Container>& lhs,
	     	   const normal_iterator<IteratorR, Container>& rhs)
    { 
		return lhs.base() - rhs.base(); }

    template <typename Iterator, typename Container>
    inline typename normal_iterator<Iterator, Container>::difference_type
    operator-( const normal_iterator<Iterator, Container>& lhs, 
	           const normal_iterator<Iterator, Container>& rhs) {
        return lhs.base() - rhs.base();
    }

    template <typename Iterator, typename Container>
    inline normal_iterator<Iterator, Container>
    operator+( typename normal_iterator<Iterator, Container>::difference_type n,
               const normal_iterator<Iterator, Container>& i ) {
        return normal_iterator<Iterator, Container>(i.base() + n);
    }

}

#endif
