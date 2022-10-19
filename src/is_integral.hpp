#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include <type_traits>

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

	template <typename>
struct is_integral
    : public integral_false_type {};

template <>
struct is_integral<bool>
    : public integral_true_type {};

template <>
struct is_integral<char>
    : public integral_true_type {};

template <>
struct is_integral<unsigned short>
    : public integral_true_type {};

template <>
struct is_integral<unsigned int>
    : public integral_true_type {};

template <>
struct is_integral<wchar_t>
    : public integral_true_type {};

template <>
struct is_integral<signed char>
    : public integral_true_type {};

template <>
struct is_integral<short>
    : public integral_true_type {};

template <>
struct is_integral<int>
    : public integral_true_type {};

template <>
struct is_integral<long>
    : public integral_true_type {};

template <>
struct is_integral<unsigned char>
    : public integral_true_type {};

template <>
struct is_integral<unsigned long>
    : public integral_true_type {};

// const

template <>
struct is_integral<const bool>
    : public integral_true_type {};

template <>
struct is_integral<const char>
    : public integral_true_type {};

template <>
struct is_integral<const unsigned short>
    : public integral_true_type {};

template <>
struct is_integral<const unsigned int>
    : public integral_true_type {};

template <>
struct is_integral<const wchar_t>
    : public integral_true_type {};

template <>
struct is_integral<const signed char>
    : public integral_true_type {};

template <>
struct is_integral<const short>
    : public integral_true_type {};

template <>
struct is_integral<const int>
    : public integral_true_type {};

template <>
struct is_integral<const long>
    : public integral_true_type {};

template <>
struct is_integral<const unsigned char>
    : public integral_true_type {};

template <>
struct is_integral<const unsigned long>
    : public integral_true_type {};
}

#endif
