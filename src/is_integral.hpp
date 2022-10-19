#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

//#include <type_traits>

//https://runebook.dev/ru/docs/cpp/types/is_integral

namespace ft {

  template<typename _Tp, _Tp __v>
    struct integral_constant
    {
        static const _Tp                      value = __v;
        typedef _Tp                           value_type;
        typedef integral_constant<_Tp, __v>   type;
        operator _Tp() const { 
            return value; 
            }

    };
    
    // The type used as a compile-time boolean with true value.
    typedef integral_constant<bool, true>     integral_true_type;

    // The type used as a compile-time boolean with false value.
    typedef integral_constant<bool, false>    integral_false_type;

	template<typename>
	struct __is_integral__
	: public integral_false_type { };

	template<>
	struct __is_integral__<bool>
	: public integral_true_type { };

	template<>
	struct __is_integral__<char>
	: public integral_true_type { };

	template<>
	struct __is_integral__<signed char>
	: public integral_true_type { };

	template<>
	struct __is_integral__<unsigned char>
	: public integral_true_type { };

	template<>
	struct __is_integral__<short>
	: public integral_true_type { };

	template<>
	struct __is_integral__<unsigned short>
	: public integral_true_type { };

	template<>
	struct __is_integral__<wchar_t>
    : public integral_true_type {};

	template<>
	struct __is_integral__<int>
	: public integral_true_type { };

	template<>
	struct __is_integral__<unsigned int>
	: public integral_true_type { };

	template<>
	struct __is_integral__<long>
	: public integral_true_type { };

	template<>
	struct __is_integral__<unsigned long>
	: public integral_true_type { };

	template<>
	struct __is_integral__<long long>
	: public integral_true_type { };

	template<>
	struct __is_integral__<unsigned long long>
	: public integral_true_type { };

	template<typename T>
	struct is_integral
	: public __is_integral__<typename remove_cv<T>::type>::type
	{ };
}


#endif