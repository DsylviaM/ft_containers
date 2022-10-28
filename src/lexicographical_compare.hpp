#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

//https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
namespace ft {
template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2) {
    for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 ) {
        if (*first1 < *first2) return true;
        if (*first2 < *first1) return false;
    }
    return ((first1 == last1) && (first2 != last2));
}

template<class InputIt1, class InputIt2, class Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2,
                             Compare comp)
{
    for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
        if (comp(*first1, *first2)) return true;
        if (comp(*first2, *first1)) return false;
    }
    return (first1 == last1) && (first2 != last2);
}

//equal
    template<class InputIt1, class InputIt2>
	bool
    equal(InputIt1 beg1, InputIt1 end1, InputIt2 beg2)	{
		
        for (; beg1 != end1; ++beg1, ++beg2) {
            if (*beg1 != *beg2) {
				return false;
            }
        }
		return true;
	}

	template<class InputIt1, class InputIt2, class BinPredicate>
	bool
    equal(InputIt1 beg1, InputIt1 end1, InputIt2 beg2, BinPredicate pred) {
		
        for (; beg1 != end1; ++beg1, ++beg2) {	
            if (!pred(*beg1, *beg2)) {
				return false;
            }
        }
		return true;
	}

}

#endif
