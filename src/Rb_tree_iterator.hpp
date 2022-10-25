#ifndef RB_TR_ITERATOR_HPP
#define RB_TR_ITERATOR_HPP

#include "iterator.hpp"
#include "Rb_tree_node_base.hpp"
#include "tree.hpp"

namespace ft{
    
    template<typename T,
              typename Tree = _Rb_tree<T> >
     struct _Rb_tree_iterator
     {
       typedef _Tp  value_type;
       typedef _Tp& reference;
       typedef _Tp* pointer;
 
       typedef bidirectional_iterator_tag iterator_category;
       typedef ptrdiff_t                  difference_type;
 
       typedef _Rb_tree_iterator<_Tp>        _Self;
       typedef _Rb_tree_node_base::_Base_ptr _Base_ptr;
       typedef _Rb_tree_node<_Tp>*           _Link_type;
 
       _Rb_tree_iterator()
       : _M_node() { }
 
       explicit
       _Rb_tree_iterator(_Link_type __x)
       : _M_node(__x) { }
 
       reference
       operator*() const
       { return static_cast<_Link_type>(_M_node)->_M_value_field; }
 
       pointer
       operator->() const
       { return &static_cast<_Link_type>(_M_node)->_M_value_field; }
 
       _Self&
       operator++()
       {
     _M_node = _Rb_tree_increment(_M_node);
     return *this;
       }
 
       _Self
       operator++(int)
       {
     _Self __tmp = *this;
     _M_node = _Rb_tree_increment(_M_node);
     return __tmp;
       }
 
       _Self&
       operator--()
       {
     _M_node = _Rb_tree_decrement(_M_node);
     return *this;
       }
 
       _Self
       operator--(int)
       {
     _Self __tmp = *this;
     _M_node = _Rb_tree_decrement(_M_node);
     return __tmp;
       }
 
       bool
       operator==(const _Self& __x) const
       { return _M_node == __x._M_node; }
 
       bool
       operator!=(const _Self& __x) const
       { return _M_node != __x._M_node; }
 
       _Base_ptr _M_node;
   };
 



}


#endif
