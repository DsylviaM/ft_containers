#ifndef RB_TREE_ITERATOR_HPP
#define RB_TREE_ITERATOR_HPP

#include <memory>
#include <utility.hpp>
#include <cstddef>

namespace ft{

  typedef enum _Rb_tree_color { _red, _black};

   template<class T>
   struct _Rb_tree_node_base
   {
      public:
            typedef T                          data_type;
            typedef _Rb_tree_node_base*        _Base_ptr;
            typedef const _Rb_tree_node_base*  _Const_Base_ptr;

     _Rb_tree_color  _M_color;
     _Base_ptr       _M_parent;
     _Base_ptr       _M_left;
     _Base_ptr       _M_right;

     data_type       data;
     bool             _is_empty;
      
     _Rb_tree_node_base() : 
         data(),
         _M_color(_black),
         _M_parent(0),
         _M_left(0),
         _M_right(0),
         _is_empty(true) { }
        
     _Rb_tree_node_base(data_type d, _Rb_tree_color clr, _Base_ptr prnt, _Base_ptr lft, _Base_ptr rht) : 
         data(d),
         _M_color(clr),
         _M_parent(prnt),
         _M_left(lft),
         _M_right(rht),
         _is_empty(false) { }
        
     _Rb_tree_node_base(data_type d) : 
         data(d),
         _M_color(_red),
         _M_parent(NULL),
         _M_left(NULL),
         _M_right(NULL),
         _is_empty(false) { }

     ~_Rb_tree_node_base() {}

        bool is_empty() const {
            return (_is_empty);
        }

        data_type & operator*() {
            return (data);
        }

        data_type * operator->() {
            return (&data);
        }

};

template < 
    class T, 
    class Allocator >
void    delete_node( _Rb_tree_node_base<T> *node, Allocator alloc = Allocator() ) {
    alloc.destroy(node);
    alloc.deallocate(node, 1);
}

template< class T >
bool operator==( const _Rb_tree_node_base<T> & lhs,
                 const _Rb_tree_node_base<T> & rhs ) {
    return (lhs.data == rhs.data);
}

template< class T >
bool operator==( const _Rb_tree_node_base<T> & lhs,
                 const T & data ) {
    return (lhs.data == data);
}

template< class T >
bool operator==( const T & data,
                 const _Rb_tree_node_base<T> & rhs ) {
    return (rhs == data);
}

template< class T >
bool operator<( const _Rb_tree_node_base<T>& lhs,
                 const _Rb_tree_node_base<T>& rhs ) {
    return (lhs.data < rhs.data);
}

template< class T >
bool operator<( const _Rb_tree_node_base<T> & lhs,
                 const T & data ) {
    return (lhs.data < data);
}

template< class T >
bool operator<( const T & data,
                 const _Rb_tree_node_base<T> & rhs ) {
    return (data < rhs.data);
}

template< class T >
bool operator<=( const _Rb_tree_node_base<T>& lhs,
                 const _Rb_tree_node_base<T>& rhs ) {
    return (lhs.data <= rhs.data);
}

template< class T >
bool operator<=( const _Rb_tree_node_base<T> & lhs,
                 const T & data ) {
    return (lhs.data <= data);
}

template< class T >
bool operator<=( const T & data,
                 const _Rb_tree_node_base<T> & rhs ) {
    return (data <= rhs.data);
}

template< class T >
bool operator>( const _Rb_tree_node_base<T>& lhs,
                 const _Rb_tree_node_base<T>& rhs ) {
    return (lhs.data > rhs.data);
}

template< class T >
bool operator>( const _Rb_tree_node_base<T> & lhs,
                 const T & data ) {
    return (lhs.data > data);
}

template< class T >
bool operator>( const T & data,
                 const _Rb_tree_node_base<T> & rhs ) {
    return (rhs.data > data);
}

template< class T >
bool operator>=( const _Rb_tree_node_base<T>& lhs,
                 const _Rb_tree_node_base<T>& rhs ) {
    return (lhs.data >= rhs.data);
}

template< class T >
bool operator>=( const _Rb_tree_node_base<T> & lhs,
                 const T & data ) {
    return (lhs.data >= data);
}

template< class T >
bool operator>=( const T & data,
                 const _Rb_tree_node_base<T> & rhs ) {
    return (rhs.data >= data);
}

// pair

template< class T1, class T2 >
bool operator==( const _Rb_tree_node_base<pair<T1, T2> > & lhs,
                 const _Rb_tree_node_base<pair<T1, T2> > & rhs ) {
    return (lhs.data.first == rhs.data.first);
}

template< class T1, class T2 >
bool operator==( const _Rb_tree_node_base<pair<T1, T2> > & lhs,
                 const pair<T1, T2> & data ) {
    return (lhs.data.first == data.first);
}

template< class T1, class T2 >
bool operator==( const pair<T1, T2> & data,
                 const _Rb_tree_node_base<pair<T1, T2> > & rhs ) {
    return (data.first == rhs.data.first);
}

template< class T1, class T2 >
bool operator<( const _Rb_tree_node_base<pair<T1, T2> >& lhs,
                 const _Rb_tree_node_base<pair<T1, T2> >& rhs ) {
    return (lhs.data.first < rhs.data.first);
}

template< class T1, class T2 >
bool operator<( const _Rb_tree_node_base<pair<T1, T2> > & lhs,
                 const pair<T1, T2> & data ) {
    return (lhs.data.first < data.first);
}

template< class T1, class T2 >
bool operator<( const pair<T1, T2> & data,
                 const _Rb_tree_node_base<pair<T1, T2> > & rhs ) {
    return (data.first < rhs.data.first);
}

template< class T1, class T2 >
bool operator<=( const _Rb_tree_node_base<pair<T1, T2> >& lhs,
                 const _Rb_tree_node_base<pair<T1, T2> >& rhs ) {
    return (lhs.data.first <= rhs.data.first);
}

template< class T1, class T2 >
bool operator<=( const _Rb_tree_node_base<pair<T1, T2> > & lhs,
                 const pair<T1, T2> & data ) {
    return (lhs.data.first <= data.first);
}

template< class T1, class T2 >
bool operator<=( const pair<T1, T2> & data,
                 const _Rb_tree_node_base<pair<T1, T2> > & rhs ) {
    return (data.first <= rhs.data.first);
}

template< class T1, class T2 >
bool operator>( const _Rb_tree_node_base<pair<T1, T2> >& lhs,
                 const _Rb_tree_node_base<pair<T1, T2> >& rhs ) {
    return (lhs.data.first > rhs.data.first);
}

template< class T1, class T2 >
bool operator>( const _Rb_tree_node_base<pair<T1, T2> > & lhs,
                 const pair<T1, T2> & data ) {
    return (lhs.data.first > data.first);
}

template< class T1, class T2 >
bool operator>( const pair<T1, T2> & data,
                 const _Rb_tree_node_base<pair<T1, T2> > & rhs ) {
    return (data.first > rhs.data.first);
}

template< class T1, class T2 >
bool operator>=( const _Rb_tree_node_base<pair<T1, T2> >& lhs,
                 const _Rb_tree_node_base<pair<T1, T2> >& rhs ) {
    return (lhs.data.first >= rhs.data.first);
}

template< class T1, class T2 >
bool operator>=( const _Rb_tree_node_base<pair<T1, T2> > & lhs,
                 const pair<T1, T2> & data ) {
    return (lhs.data.first >= data.first);
}

template< class T1, class T2 >
bool operator>=( const pair<T1, T2> & data,
                 const _Rb_tree_node_base<pair<T1, T2> > & rhs ) {
    return (data.first >= rhs.data.first);
}


 /*
     static _Base_ptr
     _S_minimum(_Base_ptr __x)
     {
       while (__x->_M_left != 0) __x = __x->_M_left;
       return __x;
     }

     static _Const_Base_ptr
     _S_minimum(_Const_Base_ptr __x)
     {
       while (__x->_M_left != 0) __x = __x->_M_left;
       return __x;
     }
 
     static _Base_ptr
     _S_maximum(_Base_ptr __x)
     {
       while (__x->_M_right != 0) __x = __x->_M_right;
       return __x;
     }
 
     static _Const_Base_ptr
     _S_maximum(_Const_Base_ptr __x)
     {
       while (__x->_M_right != 0) __x = __x->_M_right;
       return __x;
     }
   };
 
   template<typename _Val>
     struct _Rb_tree_node : public _Rb_tree_node_base
     {
       typedef _Rb_tree_node<_Val>* _Link_type;
       _Val _M_value_field;
     };
 
   _Rb_tree_node_base*
   _Rb_tree_increment(_Rb_tree_node_base* __x);
 
   const _Rb_tree_node_base*
   _Rb_tree_increment(const _Rb_tree_node_base* __x);
 
   _Rb_tree_node_base*
   _Rb_tree_decrement(_Rb_tree_node_base* __x);
 
   const _Rb_tree_node_base*
   _Rb_tree_decrement(const _Rb_tree_node_base* __x);*/
}

#endif
