#ifndef LESS_HPP
#define LESS_HPP

//https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.2/stl__function_8h-source.html

namespace ft {

template<typename _Arg1, typename _Arg2, typename _Result>
struct binary_function {

    typedef _Arg1 	    first_argument_type; 
    typedef _Arg2 	    second_argument_type;
    typedef _Result 	result_type;
};

template<typename _Tp>
struct less : public ::ft::binary_function<_Tp, _Tp, bool> {
bool    operator()(const _Tp& _x, const _Tp& _y) const { 
    return ( _x < _y ); 
}

};

template<typename arg, typename result>
    struct unary_function
    {
		typedef arg		argument_type;
		typedef result	result_type;  
    };

template<typename T>
    struct identity : public unary_function<T, T>
    {
		T& operator()(T& x) const { return x; }
		const T& operator()(const T& x) const { return x; }
    };

	
	template<typename Pair>
    struct select1st : public unary_function<Pair, typename Pair::first_type>
    {
		typename Pair::first_type& 
		operator()(Pair& x) const { return x.first; }

		const typename Pair::first_type&
		operator()(const Pair& x) const { return x.first; }
	};

}

#endif
