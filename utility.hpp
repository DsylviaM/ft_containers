//utility standart header
#ifndef UTILITY_HPP
#define UTILITY_HPP
//#include <iosfwd>

namespace ft {
    //template struct pair
template<class T1, class T2> struct pair {
    typedef T1 first_type;
    typedef T2 second_type;
    pair () : first(first_type()), second(second_type()) {}
    pair (const T1& V1, const T2& V2) : first(V1), second(V2) {}

    template<class U1, class U2>
        pair (const pair <U1, U2>& X)
        : first (X.first), second (X.second) {}

    T1 first;
    T2 second;

    pair& operator=( const pair& other ) {
        first = other.first;
        second = other.second;
        return (*this);
        }
};

    //pair TEMPLATE OPERATORS
    template<class T1, class T2> inline
        bool operator ==(const pair<T1, T2>& X,
            const pair<T1, T2>& Y)
            {return (X.first == Y.first && X.second == Y.second); }

    template<class T1, class T2> inline
        bool operator!=(const pair<T1, T2>& X,
            const pair<T1, T2>& Y)
            {return (!(X == Y)); }

    template<class T1, class T2> inline
        bool operator <(const pair<T1, T2>& X,
            const pair<T1, T2>& Y)
            {return (X.first < Y.first ||
                !(Y.first < X. first) && X.second < Y.second); }

    template<class T1, class T2> inline
        bool operator >( const pair<T1, T2>& X,
            const pair<T1, T2>& Y) 
            {return (Y < X); }

    template<class T1, class T2> inline
        bool operator<=(const pair<T1, T2>& X,
            const pair<T1, T2>& Y)
            {return (!(Y < X)); }

    template<class T1, class T2> inline
        bool operator>=(const pair<T1, T2>& X,
            const pair <T1, T2>& Y)
            {return (!(X < Y)); }

    template<class T1, class T2> inline
        pair<T1, T2> make_pair(const T1& X, const T2& Y)
        {return (pair<T1, T2>(X, Y)); 
};
}

#endif
