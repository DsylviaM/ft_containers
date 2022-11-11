#include <iostream>
#include <iomanip>
#include <cassert>
#include <utility.hpp>
#include "Rb_tree_node_base.hpp"
#include "iterator.hpp"

#include <tree.hpp>
#include <set.hpp>
#include <set_it.hpp>
#include <set>


void    testSet_copy_insert();
void    testSet_lookup();
void    testSet_erase();
void    testSet_swap();
void    testSet_non_members();


void    fill_set(ft::set<int>* my_set, std::set<int>* std_set);
void    tree_picture(ft::set<int> &my_set);
template <typename T>
    void print_int_key_node(ft::rbt_node<T > *node);
void    print_int(const int& n);
template<class Iter >
    void for_each_ft(Iter begin, Iter end, void(*op)(const int& ));


void    fill_set(ft::set<int> * my_tree, std::set<int>* std_tree) {
    if (my_tree != NULL) {
        my_tree->insert(80  );
        my_tree->insert(40  );
        my_tree->insert(150 );
        my_tree->insert(60  );
        my_tree->insert(20  );
        my_tree->insert(10  );
        my_tree->insert(170 );
        my_tree->insert(140 );
        my_tree->insert(120 );
        my_tree->insert(0   );
        my_tree->insert(-10 );
        my_tree->insert(130 );
        my_tree->insert(110 );
        my_tree->insert(122 );
        my_tree->insert(100 );
        my_tree->insert(90  );
        my_tree->insert(85  );
    }

    if (std_tree != NULL) {
        std_tree->insert(80  );
        std_tree->insert(40  );
        std_tree->insert(150 );
        std_tree->insert(60  );
        std_tree->insert(20  );
        std_tree->insert(10  );
        std_tree->insert(170 );
        std_tree->insert(140 );
        std_tree->insert(120 );
        std_tree->insert(0   );
        std_tree->insert(-10 );
        std_tree->insert(130 );
        std_tree->insert(110 );
        std_tree->insert(122 );
        std_tree->insert(100 );
        std_tree->insert(90  );
        std_tree->insert(85  );
    }
}

void    print_int(const int& n) { 
    std::cout << " " << n; 
}

template<class Iter >
void
for_each_ft(Iter begin, Iter end, void(*op)(const int& )) {
    for ( ; begin != end ; ++begin ) {
        op(*begin);
    }
}


void testSet_non_members() {

    std::cout << std::endl << "\033[35m" << "CHECK testSet NON-MEMBER FUNCTIONS " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____31_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 31) template< class Key, class Compare, class Alloc > \n"
                               "\t\t void swap( std::set<Key,Compare,Alloc>& lhs, \n"
                               "\t\t std::set<Key,Compare,Alloc>& rhs ); "
              << "\033[0m" << std::endl;

    ft::set<int> alice;
    alice.insert( 1 );
    alice.insert( 2 );
    alice.insert( 3 );

    ft::set<int> bob;
    bob.insert( 7  );
    bob.insert( 8  );
    bob.insert( 9  );
    bob.insert( 10 );
 
    // Print state before swap
    std::cout << "alice:";
    for_each_ft(alice.begin(), alice.end(), print_int);
    std::cout << "\n" "bob  :";
    for_each_ft(bob.begin(), bob.end(), print_int);
    std::cout << '\n';
 
    std::cout << "-- SWAP\n";
    ft::swap(alice, bob);
 
    // Print state after swap
    std::cout << "alice:";
    for_each_ft(alice.begin(), alice.end(), print_int);
    std::cout << "\n" "bob  :";
    for_each_ft(bob.begin(), bob.end(), print_int);
    std::cout << std::endl;

    std::cout << std::endl << "\033[33m" << "_____25-30_____" << "\033[0m" << std::endl;
    std::cout << "\033[35m" << 
                 "\t operator== \n"
                 "\t operator!= \n" 
                 "\t operator< \n" 
                 "\t operator<= \n"
                 "\t operator> \n"
                 "\t operator>= "
                 "\033[0m" << std::endl;

    ft::set<int> eve(alice);
 
    std::cout << std::boolalpha;
 
    // Compare non equal containers
    std::cout << "\n\033[36m" << "\t\t alice > bob " << "\033[0m"  << std::endl;
    std::cout << "alice == bob returns " << (alice == bob) << std::endl;
    std::cout << "alice != bob returns " << (alice != bob) << std::endl;
    std::cout << "alice <  bob returns " << (alice < bob) <<  std::endl;
    std::cout << "alice <= bob returns " << (alice <= bob) << std::endl;
    std::cout << "alice >  bob returns " << (alice > bob) <<  std::endl;
    std::cout << "alice >= bob returns " << (alice >= bob) << std::endl;

 
    // Compare equal containers
    std::cout << "\n\033[36m" << "\t\t alice == eve " << "\033[0m"  << std::endl;
    std::cout << "alice == eve returns " << (alice == eve) << std::endl;
    std::cout << "alice != eve returns " << (alice != eve) << std::endl;
    std::cout << "alice <  eve returns " << (alice < eve) <<  std::endl;
    std::cout << "alice <= eve returns " << (alice <= eve) << std::endl;
    std::cout << "alice >  eve returns " << (alice > eve) <<  std::endl;
    std::cout << "alice >= eve returns " << (alice >= eve) << std::endl;

    std::cout << std::endl;
}

void    testSet_swap() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet Modifiers " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____17_____" << "\033[0m" << std::endl;
    
    ft::set<int>   my_tree1;
    my_tree1.insert(25);
    my_tree1.insert(15);
    ft::set<int>::iterator    iter_my_tree1 = my_tree1.begin();

    std::set<int>   std_tree1;
    std_tree1.insert(25);
    std_tree1.insert(15);
    std::set<int>::iterator   iter_std_tree1 = std_tree1.begin();

    ft::set<int>   my_tree2;
    my_tree2.insert(5);
    ft::set<int>::iterator    iter_my_tree2 = my_tree2.begin();

    std::set<int>   std_tree2;
    std_tree2.insert(5);
    std::set<int>::iterator   iter_std_tree2 = std_tree2.begin();

    std::cout << "\n\033[36m" << "\t\t befor swap: " << "\033[0m"  << std::endl;

    std::cout << std::setw(11) << std::left << "my_tree1" << std::setw(11) << "std_tree1" 
              << std::setw(11) << "my_tree2" << std::setw(11) << "std_tree2 " << std::endl;
    while ( iter_my_tree1 != my_tree1.end() ||
            iter_std_tree1 != std_tree1.end() ||
            iter_my_tree2 != my_tree2.end() ||
            iter_std_tree2 != std_tree2.end() ) {
        if ( iter_my_tree1 != my_tree1.end() ) {
            std::cout << std::setw(11) << *iter_my_tree1;
            ++iter_my_tree1;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_std_tree1 != std_tree1.end() ) {
            std::cout << std::setw(11) << *iter_std_tree1;
            ++iter_std_tree1;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_my_tree2 != my_tree2.end() ) {
            std::cout << std::setw(11) << *iter_my_tree2;
            ++iter_my_tree2;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_std_tree2 != std_tree2.end() ) {
            std::cout << *iter_std_tree2 ;
            ++iter_std_tree2;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    my_tree1.swap(my_tree2);
    std_tree1.swap(std_tree2);
    iter_my_tree1 = my_tree1.begin();
    iter_std_tree1 = std_tree1.begin();
    iter_my_tree2 = my_tree2.begin();
    iter_std_tree2 = std_tree2.begin();

    std::cout << "\n\033[36m" << "\t\t after swap: " << "\033[0m"  << std::endl;

    std::cout << std::setw(11) << std::left << "my_tree1" << std::setw(11) << "std_tree1" 
              << std::setw(11) << "my_tree2" << std::setw(11) << "std_tree2 " << std::endl;
    while ( iter_my_tree1 != my_tree1.end() ||
            iter_std_tree1 != std_tree1.end() ||
            iter_my_tree2 != my_tree2.end() ||
            iter_std_tree2 != std_tree2.end() ) {
        if ( iter_my_tree1 != my_tree1.end() ) {
            std::cout << std::setw(11) << *iter_my_tree1;
            ++iter_my_tree1;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_std_tree1 != std_tree1.end() ) {
            std::cout << std::setw(11) << *iter_std_tree1;
            ++iter_std_tree1;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_my_tree2 != my_tree2.end() ) {
            std::cout << std::setw(11) << *iter_my_tree2;
            ++iter_my_tree2;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_std_tree2 != std_tree2.end() ) {
            std::cout << *iter_std_tree2;
            ++iter_std_tree2;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "\033[33m" << "__1.3)___3_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 3) operator=; "
              << "\033[0m" << std::endl;

    ft::set<int>   my_tree3(my_tree1);
    std::cout << "ft::set<int>   my_tree3(my_tree1);" << std::endl;
    std::cout << "\n\033[36m" << "\t\t cout: " << "\033[0m"  << std::endl;
    for ( iter_my_tree1 = my_tree3.begin() ; iter_my_tree1 != my_tree3.end(); ++iter_my_tree1 ) {
        std::cout << *iter_my_tree1 << std::endl;
    }

    std::cout << std::endl << "\033[33m" << "_____15.3_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 15.3) insert(InIter first, InIter last); "
              << "\033[0m" << std::endl;
    my_tree3.insert(my_tree2.begin(), my_tree2.end());
    std::cout << "my_tree3.insert(my_tree2.begin(), my_tree2.end());" << std::endl;
    std::cout << "\n\033[36m" << "\t\t cout: " << "\033[0m"  << std::endl;
    for ( iter_my_tree1 = my_tree3.begin() ; iter_my_tree1 != my_tree3.end(); ++iter_my_tree1 ) {
        std::cout << *iter_my_tree1 << std::endl;
    }
}

void    testSet_erase() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet Modifiers " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____16_____" << "\033[0m" << std::endl;
    ft::set<int>   my_tree;
    std::set<int>   std_tree;
    ft::set<int>::iterator    iter_my_tree;
    std::set<int>::iterator   iter_std_tree;
    fill_set(&my_tree, &std_tree);
    std_tree.insert( 112 );
    my_tree.insert( 112 );
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;
    std::cout << "\033[34m" << "\t 16.1) void      erase( iterator pos ); \n"
              << "\033[0m" << std::endl;
    std::cout << "\n\033[36m" << "\t\t 1st case. Delete (D) without childs (begin, 110): " << "\033[0m"  << std::endl;
    std_tree.erase( std_tree.begin() );
    std_tree.erase( std_tree.find(110) );
    my_tree.erase( my_tree.begin() );
    my_tree.erase( my_tree.find(110) );

    std::cout << "\n\033[36m" << "\t\t 2st case. Delete (D) with one child (0 with child -10): " << "\033[0m"  << std::endl;
    std_tree.insert( -10 );
    my_tree.insert( -10 );
    std_tree.erase( std_tree.find(0) );
    my_tree.erase( my_tree.find(0) );

    std::cout << "\n\033[36m" << "\t\t 1st case. Delete (D) with both childs: " << "\033[0m"  << std::endl;
    std_tree.insert( 91 );
    my_tree.insert( 91 );
    std_tree.erase( std_tree.find(120) );
    my_tree.erase( my_tree.find(120) );
    std_tree.erase( std_tree.find(91) );
    my_tree.erase( my_tree.find(91) );

    std::cout << " std      | my " << std::endl;
    iter_my_tree = my_tree.begin();
    for (iter_std_tree = std_tree.begin(); iter_std_tree != std_tree.end(); ++iter_std_tree, ++iter_my_tree) {
        std::cout << *iter_std_tree << "\t\t"
                  << *iter_my_tree 
                  << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\033[34m" << "\t 16.2) size_type erase( const Key& key ); \n"
              << "\033[0m" << std::endl;

    std::cout << "                \t std | my " << std::endl;
    std::cout << "tree.erase( 60 ) \t = " << std_tree.erase( 60 ) << " | " << my_tree.erase( 60 ) << std::endl;
    std::cout << "tree.erase( 122 ) \t = " << std_tree.erase( 122 ) << " | " << my_tree.erase( 122 ) << std::endl;
    std::cout << "tree.erase( 61 ) \t = " << std_tree.erase( 61 ) << " | " << my_tree.erase( 61 ) << std::endl;
    std::cout << "tree.erase( 6100 ) \t = " << std_tree.erase( 6100 ) << " | " << my_tree.erase( 6100 ) << std::endl;
    std::cout << "tree.erase( 170 ) \t = " << std_tree.erase( 170 ) << " | " << my_tree.erase( 170 ) << std::endl;

    std::cout << std::endl;
    std::cout << " std      | my " << std::endl;
    iter_my_tree = my_tree.begin();
    for (iter_std_tree = std_tree.begin(); iter_std_tree != std_tree.end(); ++iter_std_tree, ++iter_my_tree) {
        std::cout << *iter_std_tree << "\t\t"
                  << *iter_my_tree 
                  << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\033[34m" << "\t 16.3) void      erase( iterator first, iterator last ); \n"
              << "\033[0m" << std::endl;
    std::cout << "tree.erase( find(40), find(90) ) " << std::endl;
    std_tree.erase( std_tree.find(40), std_tree.find(90) );
    my_tree.erase( my_tree.find(40), my_tree.find(90) );
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;
    
    std::cout << " std      | my " << std::endl;
    iter_my_tree = my_tree.begin();
    for (iter_std_tree = std_tree.begin(); iter_std_tree != std_tree.end(); ++iter_std_tree, ++iter_my_tree) {
        std::cout << *iter_std_tree << "\t\t"
                  << *iter_my_tree 
                  << std::endl;
    }
    std::cout << std::endl;

}

void    testSet_lookup() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet lookup " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____19_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 19) iterator       find( const Key& key ); \n"
                               "\t     const_iterator find( const Key& key ) const; \n\n"
                               "\t     size_type      count( const Key& key ) const; "
              << "\033[0m" << std::endl;

    ft::set<int>   my_tree;
    std::set<int>   std_tree;
    fill_set(&my_tree, &std_tree);
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;

    ft::set<int>::iterator   iter_my_tree1;
    std::set<int>::iterator  iter_std_tree1;

    iter_my_tree1 = my_tree.find(80);
    iter_std_tree1 = std_tree.find(80);

    if (iter_std_tree1 == std_tree.end()) {
        std::cout << "STD_SET: Fix find() parametres for std::set. " << std::endl;
    } else {
        std::cout << "STD_SET find: Very good: " << *iter_std_tree1 
                  << " |  std_tree.count(80) = " << std_tree.count(80)
                  << " | *std_tree.lower_bound(80) = " << *std_tree.lower_bound(80)
                  << " | *std_tree.upper_bound(80) = " << *std_tree.upper_bound(80)
                  << std::endl;
    }

    if (iter_my_tree1 == my_tree.end()) {
        std::cout << " FT_SET: Fix your find() in ft::set. " << std::endl;
    } else {
        std::cout << " FT_SET find: Very good: " << *iter_my_tree1 
                  << " |   my_tree.count(80) = " << my_tree.count(80)
                  << " |  *my_tree.lower_bound(80) = " << *my_tree.lower_bound(80)
                  << " |  *my_tree.upper_bound(80) = " << *my_tree.upper_bound(80)
                  << std::endl;
    }
    std::cout << std::endl;

    iter_my_tree1 = my_tree.find(11280);
    iter_std_tree1 = std_tree.find(11280);

    if (iter_std_tree1 == std_tree.end() && 
        std_tree.lower_bound(11280) == std_tree.end() &&
        std_tree.upper_bound(11280) == std_tree.end()) {
        std::cout << "STD_SET find: Very good!!! "
                  << "std_tree.count(11280) = " << std_tree.count(11280)
                  << std::endl;

    } else {
        std::cout << "STD_SET: Fix find() parametres for std::set. " << std::endl;
    }

    if (iter_my_tree1 == my_tree.end() && 
        my_tree.lower_bound(11280) == my_tree.end() &&
        my_tree.upper_bound(11280) == my_tree.end()) {
        std::cout << " FT_SET find: Very good!!! "
                  << " my_tree.count(11280) = " << my_tree.count(11280)
                  << std::endl;
    } else {
        std::cout << " FT_SET: Fix your find() in ft::set. " << std::endl;
    }
    std::cout << std::endl;

    std::cout << "std_tree.equal_range(80): "
              << *std_tree.equal_range(80).first
              << std::endl;

    std::cout << " my_tree.equal_range(80): "
              << *my_tree.equal_range(80).first
              << std::endl;
}

void    testSet_insert() {
    std::cout << std::endl << "\033[35m" << "CHECK SET: modifiers" << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____15_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t15.1) std::pair<iterator, bool> insert( const value_type& value ); " << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t15.2) iterator insert( iterator hint, const value_type& value ); " << "\033[0m" << std::endl;

    ft::set<int>   my_tree;
    ft::pair<ft::set<int>::iterator, bool> insert_pair;
    insert_pair = my_tree.insert(80);
    std::cout << "\n\033[36m" << "\t\t 1st insert. (80) \033[0m\n"
              << "\t insert_pair.first = (iter to: (\033[33m"
              << *(insert_pair.first)
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;

    // std::set<int>   std_tree;
    // std::pair<std::set<int>::iterator, bool> insert_pair_std;
    // insert_pair_std = std_tree.insert(80);
    // std::cout << "\n\033[36m" << "\t\t 1st insert. (80) \033[0m\n"
    //           << "\t insert_pair_std.first = (iter to: (\033[33m"
    //           << *(insert_pair_std.first)
    //           << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair_std.second << "\033[0m) "
    //           << std::endl;

    insert_pair = my_tree.insert(40);
    std::cout << "\n\033[36m" << "\t\t     insert. (40) \033[0m\n"
              << "\t insert_pair.first = (iter to: (\033[33m"
              << *(insert_pair.first)
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;

    ft::set<int>::iterator iter_insert = 
    my_tree.insert(insert_pair.first, 150);
    std::cout << "\n\033[36m" << "\t\t     insert. (iterator, 150) \033[0m\n"
              << "\t iter_insert = (\033[33m"
              << *(iter_insert)
              << "\033[0m) "
              << std::endl;

    my_tree.insert(60);
    my_tree.insert(20);
    insert_pair = my_tree.insert(10);
    std::cout << "\n\033[36m" << "\t\t     insert. (10) \033[0m\n"
              << "\t insert_pair.first = (iter to: (\033[33m"
              << *(insert_pair.first)
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;
}

void    testSet_copy_insert() {
    std::cout << std::endl << "\033[35m" << "CHECK SET copy " << "\033[0m" << std::endl;

    ft::set<int> my_tree;
    std::set<int> std_tree;

    fill_set(&my_tree, &std_tree);
    ft::set<int> my_tree_copy = my_tree;
    std::set<int> std_tree_copy = std_tree;

    // tree_picture(my_tree);
    //tree_picture(my_tree_copy);

}

int main() {

    testSet_non_members();// 25-31
    testSet_copy_insert();
    testSet_insert();// 15
    testSet_swap();// 17
    testSet_erase();// 16
    testSet_lookup();// 19

    return (0);
}
