#ifndef RB_TREE_CONST_ITERATOR_HPP
#define RB_TREE_CONST_ITERATOR_HPP



namespace ft{
template<typename _Tp>
     struct _Rb_tree_const_iterator
     {
       typedef _Tp        value_type;
       typedef const _Tp& reference;
       typedef const _Tp* pointer;
 
       typedef _Rb_tree_iterator<_Tp> iterator;
 
       typedef bidirectional_iterator_tag iterator_category;
       typedef ptrdiff_t                  difference_type;
 
       typedef _Rb_tree_const_iterator<_Tp>        _Self;
       typedef _Rb_tree_node_base::_Const_Base_ptr _Base_ptr;
       typedef const _Rb_tree_node<_Tp>*           _Link_type;
 
       _Rb_tree_const_iterator()
       : _M_node() { }
 
       explicit
       _Rb_tree_const_iterator(_Link_type __x)
       : _M_node(__x) { }
 
       _Rb_tree_const_iterator(const iterator& __it)
       : _M_node(__it._M_node) { }
 
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
