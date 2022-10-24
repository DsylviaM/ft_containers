#ifndef RB_TREE_ITERATOR_HPP
#define RB_TREE_ITERATOR_HPP

namespace ft{
    enum _Rb_tree_color { _S_red = false, _S_black = true };

   struct _Rb_tree_node_base
   {
     typedef _Rb_tree_node_base* _Base_ptr;
     typedef const _Rb_tree_node_base* _Const_Base_ptr;
 
     _Rb_tree_color  _M_color;
     _Base_ptr       _M_parent;
     _Base_ptr       _M_left;
     _Base_ptr       _M_right;
 
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
   _Rb_tree_decrement(const _Rb_tree_node_base* __x);
}


#endif