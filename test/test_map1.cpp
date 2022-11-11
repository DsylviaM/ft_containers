#include <iostream>
#include <string>

#include "../src/map.hpp"
#include <map>
#include "../src/utility.hpp"

typedef ft::pair<int, std::string> pair;

template <typename Iter>
void
print_map_content(Iter first, Iter last) {
	std::cout << " content  : [";
	for (; first != last; ++first) {
		std::cout << " ("<< (*first).first << "; " << (*first).second << ")";
	}
	std::cout << " ]" << std::endl;
}

template <typename Key, typename Val>
void
print_map(const ft::map<Key, Val>& map) {
	std::cout << " empty : " << map.empty() << std::endl; 
	std::cout << " size  : " << map.size() << std::endl;
	std::cout << " max_size : " << map.max_size() << std::endl;
	print_map_content(map.begin(), map.end());
}


/*
void    insert_val_map(ft::map<int, std::string> &my_tree, std::map<int, std::string>* std_tree) {
    
    my_tree.insert(ft::make_pair(80, "At "));
    my_tree.insert(ft::make_pair(40, "the "));
    my_tree.insert(ft::make_pair(150, "Mountains "));
    my_tree.insert(ft::make_pair(60, "of "));
    my_tree.insert(ft::make_pair(20, "Madness "));
    my_tree.insert(ft::make_pair(10, "... "));
    my_tree.insert(ft::make_pair(170, "..170.. "));
    my_tree.insert(ft::make_pair(140, "..140.. "));
    my_tree.insert(ft::make_pair(120, "..120.. "));
    my_tree.insert(ft::make_pair(0, "..0.. "));
    
    my_tree.insert(ft::make_pair(3, "..-10.. "));
    my_tree.insert(ft::make_pair(130, "..130.. "));
    my_tree.insert(ft::make_pair(110, "..110.. "));
    my_tree.insert(ft::make_pair(122, "..122.. "));
    my_tree.insert(ft::make_pair(100, "..100.. "));
    my_tree.insert(ft::make_pair(90, "..90.. "));
    my_tree.insert(ft::make_pair(85, "..85.. "));

    if (std_tree != NULL) {
        std_tree->insert(std::make_pair(80, "At "));
        std_tree->insert(std::make_pair(40, "the "));
        std_tree->insert(std::make_pair(150, "Mountains "));
        std_tree->insert(std::make_pair(60, "of "));
        std_tree->insert(std::make_pair(20, "Madness "));
        std_tree->insert(std::make_pair(10, "... "));
        std_tree->insert(std::make_pair(170, "..170.. "));
        std_tree->insert(std::make_pair(140, "..140.. "));
        std_tree->insert(std::make_pair(120, "..120.. "));
        std_tree->insert(std::make_pair(0, "..0.. "));
        std_tree->insert(std::make_pair(-10, "..-10.. "));
        std_tree->insert(std::make_pair(130, "..130.. "));
        std_tree->insert(std::make_pair(110, "..110.. "));
        std_tree->insert(std::make_pair(122, "..122.. "));
        std_tree->insert(std::make_pair(100, "..100.. "));
        std_tree->insert(std::make_pair(90, "..90.. "));
        std_tree->insert(std::make_pair(85, "..85.. "));
    }
}
*/
template <typename T>
void print_int_key_node(ft::rbt_node<ft::pair<const int, T> > *node) {
    if ( node->_is_empty == false ) {
        if ( node->color == 0 ) {
            std::cout << "\033[30;41m" << std::setw(5) << node->data.first << "\033[0m";
        } else {
            std::cout << "\033[37;40m" << std::setw(5) << node->data.first << "\033[0m";
        }
    } else {
        std::cout << "\033[37;40m" " NIL " "\033[0m" ;
    }
}

void tree_picture(ft::map<int, std::string> &my_tree) {
    
    if ( my_tree.empty() ) {
        std::cout << "Tree is empty. " << std::endl;
        return ;
    }
    // 80
    std::cout << "                                            ________";
    print_int_key_node( my_tree._tree.root().base() );
    std::cout << "_________" << std::endl;

    std::cout << "                           ________________/                      \\_______________" << std::endl;
    // 10 120 // 2h
    std::cout << "                        ";
    print_int_key_node( my_tree._tree.root().base()->left ); // 2h-1w pos
    std::cout << "                                                   ";
    print_int_key_node( my_tree._tree.root().base()->right ); // 2h-2w pos
    if ( my_tree._tree.root().base()->left->_is_empty == false && my_tree._tree.root().base()->right->_is_empty == false) {
        std::cout << std::endl << "              _________/      \\_________                              _________/      \\_________" << std::endl;
    } else if ( my_tree._tree.root().base()->left->_is_empty == false && my_tree._tree.root().base()->right->_is_empty == true ) {
        std::cout << std::endl << "              _________/      \\_________" << std::endl;
    } else if (my_tree._tree.root().base()->left->_is_empty == true && my_tree._tree.root().base()->right->_is_empty == false) {
        std::cout << std::endl << "                                                                      _________/      \\_________" << std::endl;
    } else {
        std::cout << std::endl;
        return ;
    }
    // 0 40 100 140 // 3h
    if ( my_tree._tree.root().base()->left->_is_empty == false ) {
        std::cout << "           ";
        print_int_key_node( my_tree._tree.root().base()->left->left ); // 3h-1w pos // 0
        std::cout << "                      ";
        print_int_key_node( my_tree._tree.root().base()->left->right ); // 3h-2w pos // 40
        std::cout << "                        ";
    } else {
        std::cout << "         "
                     "      " // 3h-1w pos
                     "                     "
                     "      " // 3h-2w pos
                     "                         ";
    }
    if ( my_tree._tree.root().base()->right->_is_empty == false ) {
        print_int_key_node( my_tree._tree.root().base()->right->left ); // 3h-3w pos // 100
        std::cout << "                      ";
        print_int_key_node( my_tree._tree.root().base()->right->right ); // 3h-4w pos // 140
    }
    
    std::cout << std::endl;
    if ( my_tree._tree.root().base()->left->_is_empty == false &&
         my_tree._tree.root().base()->left->left->_is_empty == false ) {
        std::cout << "        __/     \\__"; // 4h-1,2w pos
    } else {
        std::cout << "                   "; // 4h-1,2w pos
    }
    if ( my_tree._tree.root().base()->left->_is_empty == false &&
         my_tree._tree.root().base()->left->right->_is_empty == false ) {
        std::cout << "                __/      \\__"; // 4h-3,4w pos
    } else {
        std::cout << "                            "; // 4h-3,4w pos
    }
    if ( my_tree._tree.root().base()->right->_is_empty == false &&
         my_tree._tree.root().base()->right->left->_is_empty == false ) {
        std::cout << "                __/      \\__"; // 4h-5,6w pos
    } else {
        std::cout << "                            "; // 4h-5,6w pos
    }
    if ( my_tree._tree.root().base()->right->_is_empty == false &&
         my_tree._tree.root().base()->right->right->_is_empty == false ) {
        std::cout << "                __/      \\__"; // 4h-7,8w pos
    }
    std::cout << std::endl;
    // -10 NIL 20 NIL 90 110 130 150
    if ( ( my_tree._tree.root().base()->left->_is_empty && 
           my_tree._tree.root().base()->right->_is_empty ) ||
         ( my_tree._tree.root().base()->left->_is_empty == false &&
           my_tree._tree.root().base()->left->left->_is_empty && 
           my_tree._tree.root().base()->left->right->_is_empty && 
           my_tree._tree.root().base()->right->_is_empty ) ||
         ( my_tree._tree.root().base()->right->_is_empty == false &&
           my_tree._tree.root().base()->right->left->_is_empty && 
           my_tree._tree.root().base()->right->right->_is_empty && 
           my_tree._tree.root().base()->left->_is_empty )
       ) {
           return ;
    }

    if ( my_tree._tree.root().base()->left->_is_empty ) {
        std::cout << "                                                          ";
    } else {
        if (my_tree._tree.root().base()->left->left->_is_empty == false) {
            std::cout << "     ";
            print_int_key_node( my_tree._tree.root().base()->left->left->left ); // 4h-1w pos // -10
            std::cout << "       ";
            print_int_key_node( my_tree._tree.root().base()->left->left->right ); // 4h-2w pos // NIL
            std::cout << "          ";
        } else {
            std::cout << "                                ";
        }
        if (my_tree._tree.root().base()->left->right->_is_empty == false) {
            print_int_key_node( my_tree._tree.root().base()->left->right->left ); // 4h-3w pos // 20
            std::cout << "        ";
            print_int_key_node( my_tree._tree.root().base()->left->right->right ); // 4h-4w pos // NIL
            std::cout << "          ";
        } else {
            std::cout << "                            ";
        }
    }
    if ( my_tree._tree.root().base()->right->_is_empty == false ) {
        if (my_tree._tree.root().base()->right->left->_is_empty == false) {
            print_int_key_node( my_tree._tree.root().base()->right->left->left ); // 4h-5w pos // 90
            std::cout << "        ";
            print_int_key_node( my_tree._tree.root().base()->right->left->right ); // 4h-6w pos // 110
            std::cout << "          ";
        } else {
            std::cout << "                            ";
        }
        if (my_tree._tree.root().base()->right->right->_is_empty == false) {
            print_int_key_node( my_tree._tree.root().base()->right->right->left ); // 4h-7w pos // 130
            std::cout << "        ";
            print_int_key_node( my_tree._tree.root().base()->right->right->right ); // 4h-8w pos // 150
        }
    }
    std::cout << std::endl;
    if ( my_tree._tree.root().base()->left->_is_empty == false &&
         my_tree._tree.root().base()->left->left->_is_empty == false &&
         my_tree._tree.root().base()->left->left->left->_is_empty == false ) {
        std::cout << "     /  \\    " ; // 5h-1,2w pos
    } else {
        std::cout << "             " ; // 5h-1w pos

    }
    if ( my_tree._tree.root().base()->left->_is_empty == false &&
         my_tree._tree.root().base()->left->left->_is_empty == false &&
         my_tree._tree.root().base()->left->left->right->_is_empty == false) {
        std::cout << "     /  \\" ; // 5h-3,4w pos
    } else {
        std::cout << "         " ; // 5h-3,4w pos
    }
    if ( my_tree._tree.root().base()->left->_is_empty == false &&
         my_tree._tree.root().base()->left->right->_is_empty == false &&
         my_tree._tree.root().base()->left->right->left->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-5,6w pos
    } else {
        std::cout << "              " ; // 5h-5,6w pos
    }
    if ( my_tree._tree.root().base()->left->_is_empty == false &&
         my_tree._tree.root().base()->left->right->_is_empty == false &&
         my_tree._tree.root().base()->left->right->right->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-7,8w pos
    } else {
        std::cout << "              " ; // 5h-7,8w pos
    }


    if ( my_tree._tree.root().base()->right->_is_empty == false &&
         my_tree._tree.root().base()->right->left->_is_empty == false &&
         my_tree._tree.root().base()->right->left->left->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-9,10w pos
    } else {
        std::cout << "              " ; // 5h-9,10w pos
    }
    if ( my_tree._tree.root().base()->right->_is_empty == false &&
         my_tree._tree.root().base()->right->left->_is_empty == false &&
         my_tree._tree.root().base()->right->left->right->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-11,12w pos
    } else {
        std::cout << "              " ; // 5h-11,12w pos
    }
    if ( my_tree._tree.root().base()->right->_is_empty == false &&
         my_tree._tree.root().base()->right->right->_is_empty == false &&
         my_tree._tree.root().base()->right->right->left->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-13,14w pos
    } else {
        std::cout << "              " ; // 5h-13,14w pos
    }
    if ( my_tree._tree.root().base()->right->_is_empty == false &&
         my_tree._tree.root().base()->right->right->_is_empty == false &&
         my_tree._tree.root().base()->right->right->right->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-15,16w pos
    } else {
        std::cout << "              " ; // 5h-15,16w pos
    }

    std::cout << std::endl;
    
    if ( my_tree._tree.root().base()->left->_is_empty == false &&
         my_tree._tree.root().base()->left->left->_is_empty == false &&
         my_tree._tree.root().base()->left->left->left->_is_empty == false) {
        print_int_key_node( my_tree._tree.root().base()->left->left->left->left ); // 5h-1w pos
        std::cout << "  " ;
        print_int_key_node( my_tree._tree.root().base()->left->left->left->right ); // 5h-2w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree._tree.root().base()->left->_is_empty == false &&
         my_tree._tree.root().base()->left->left->_is_empty == false &&
         my_tree._tree.root().base()->left->left->right->_is_empty == false) {
        print_int_key_node( my_tree._tree.root().base()->left->left->right->left ); // 5h-3w pos
        std::cout << "  " ;
        print_int_key_node( my_tree._tree.root().base()->left->left->right->right ); // 5h-4w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree._tree.root().base()->left->_is_empty == false &&
         my_tree._tree.root().base()->left->right->_is_empty == false &&
         my_tree._tree.root().base()->left->right->left->_is_empty == false) {
        print_int_key_node( my_tree._tree.root().base()->left->right->left->left ); // 5h-5w pos
        std::cout << "  " ;
        print_int_key_node( my_tree._tree.root().base()->left->right->left->right ); // 5h-6w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree._tree.root().base()->left->_is_empty == false &&
         my_tree._tree.root().base()->left->right->_is_empty == false &&
         my_tree._tree.root().base()->left->right->right->_is_empty == false) {
        print_int_key_node( my_tree._tree.root().base()->left->right->right->left ); // 5h-7w pos
        std::cout << "  " ;
        print_int_key_node( my_tree._tree.root().base()->left->right->right->right ); // 5h-8w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree._tree.root().base()->right->_is_empty == false &&
         my_tree._tree.root().base()->right->left->_is_empty == false &&
         my_tree._tree.root().base()->right->left->left->_is_empty == false) {
        print_int_key_node( my_tree._tree.root().base()->right->left->left->left ); // 5h-9w pos
        std::cout << "  " ;
        print_int_key_node( my_tree._tree.root().base()->right->left->left->right ); // 5h-10w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree._tree.root().base()->right->_is_empty == false &&
         my_tree._tree.root().base()->right->left->_is_empty == false &&
         my_tree._tree.root().base()->right->left->right->_is_empty == false) {
        print_int_key_node( my_tree._tree.root().base()->right->left->right->left ); // 5h-11w pos
        std::cout << "  " ;
        print_int_key_node( my_tree._tree.root().base()->right->left->right->right ); // 5h-12w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree._tree.root().base()->right->_is_empty == false &&
         my_tree._tree.root().base()->right->right->_is_empty == false &&
         my_tree._tree.root().base()->right->right->left->_is_empty == false) {
        print_int_key_node( my_tree._tree.root().base()->right->right->left->left ); // 5h-13w pos
        std::cout << "  " ;
        print_int_key_node( my_tree._tree.root().base()->right->right->left->right ); // 5h-14w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree._tree.root().base()->right->_is_empty == false &&
         my_tree._tree.root().base()->right->right->_is_empty == false &&
         my_tree._tree.root().base()->right->right->right->_is_empty == false) {
        print_int_key_node( my_tree._tree.root().base()->right->right->right->left ); // 5h-15w pos
        std::cout << "  " ;
        print_int_key_node( my_tree._tree.root().base()->right->right->right->right ); // 5h-16w pos
        std::cout << "  " ;
    }
    std::cout << std::endl;
    std::cout << "\n\033[36m" << " only for 5 lvls " << "\033[0m"  << std::endl;

}


int main(){

    //copy
    std::cout << std::endl << "\033[35m" << " MAP copy " << "\033[0m" << std::endl;

    //  ft::map<int, std::string> my_tree1;
    //  insert_val_map(my_tree1, NULL);
    //ft::map<int, std::string> my_tree_copy = my_tree1;

 
    /// 
    /// 
    pair::first_type key1[] = { 1, 2, 3, 6, 5, 4, 4 };
	const pair::first_type size1 = sizeof(key1) / sizeof(key1[0]);
	pair::second_type val1[size1] = { "ichi", "ni", "san", "roku", "go", "yon", "shiranai" };
	pair p1[size1];
	for (size_t i = 0; i < size1; i++) {
		p1[i] = ft::make_pair(key1[i], val1[i]);
	}
    pair::first_type key2[] = { 21, 42, 84, 168, 336, 672 };
	const pair::first_type size2 = sizeof(key2) / sizeof(key2[0]);
	pair::second_type val2[size2] = { "nijuuichi", "yonjuuni", "hachijuuyon", "hyakurokujuuhachi", "sambyakusanjuuroku", "roppyakunanajuuni" };
	pair p2[size2];
	for (size_t i = 0; i < size2; i++) {
		p2[i] = ft::make_pair(key2[i], val2[i]);
	}


    {
    std::cout << " constructor(default):" << std::endl;
	ft::map<pair::first_type, pair::second_type> map;

    print_map(map);
    }
    std::cout << " ______________________" << std::endl;

    ft::map<int, std::string>   my_tree;

    my_tree.insert(ft::make_pair(84, "At "));
    tree_picture(my_tree);
/*
    my_tree.insert(ft::make_pair(171, "At "));
    tree_picture(my_tree);

    my_tree.insert(ft::make_pair(42, "At "));
    tree_picture(my_tree);
    
    my_tree.insert(ft::make_pair(164, "At "));
    tree_picture(my_tree);    
    
    my_tree.insert(ft::make_pair(118, "At "));
    tree_picture(my_tree);    
    
    my_tree.insert(ft::make_pair(135, "At "));
    tree_picture(my_tree);    
    
    my_tree.insert(ft::make_pair(110, "At "));
    tree_picture(my_tree);    
    
    my_tree.insert(ft::make_pair(196, "At "));
    tree_picture(my_tree);

    my_tree.insert(ft::make_pair(154, "At "));
    tree_picture(my_tree);

    my_tree.insert(ft::make_pair(130, "At "));
    tree_picture(my_tree);

    my_tree.insert(ft::make_pair(52, "At "));
    tree_picture(my_tree);

    my_tree.insert(ft::make_pair(172, "At "));
    tree_picture(my_tree);

    my_tree.insert(ft::make_pair(86, "At "));
    tree_picture(my_tree);

    my_tree.insert(ft::make_pair(23, "At "));
    tree_picture(my_tree);

    my_tree.insert(ft::make_pair(46, "At "));
    tree_picture(my_tree);

    my_tree.insert(ft::make_pair(180, "At "));
    tree_picture(my_tree);


    //print_map(my_tree);

    std::cout << " ______________________" << std::endl;

    {
        std::cout << " constructor(default):" << std::endl;

	ft::map<pair::first_type, pair::second_type> map(p1, p1 + size1);

    print_map(map);
    }

    {
        std::cout << "\033[34m" << "\t test without rotate " << "\033[0m" << std::endl;
        // test without rotate

        std::cout << (*my_tree._tree.root()).first << " " << std::endl;
        std::cout << (my_tree._tree.root())->first << " " << (my_tree._tree.root())->second << std::endl;

        my_tree.insert(ft::make_pair(80, "At "));
        std::cout << (my_tree._tree.root())->first << " " << (my_tree._tree.root())->second << std::endl;

        my_tree.insert(ft::make_pair(40, "the "));
        std::cout << my_tree._tree.root()->first << " " << my_tree._tree.root()->second << " " << my_tree._tree.root().base()->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->data.first << " " << my_tree._tree.root().base()->left->data.second << " " << my_tree._tree.root().base()->left->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(150, "Mountains "));
        std::cout << my_tree._tree.root()->first << " " << my_tree._tree.root()->second << " " << my_tree._tree.root().base()->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->data.first << " " << my_tree._tree.root().base()->left->data.second << " " << my_tree._tree.root().base()->left->color << std::endl;
        std::cout << my_tree._tree.root().base()->right->data.first << " " << my_tree._tree.root().base()->right->data.second << " " << my_tree._tree.root().base()->right->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(60, "of "));
        std::cout << my_tree._tree.root()->first << " " << my_tree._tree.root()->second << " " << my_tree._tree.root().base()->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->data.first << " " << my_tree._tree.root().base()->left->data.second << " " << my_tree._tree.root().base()->left->color << std::endl;
        std::cout << my_tree._tree.root().base()->right->data.first << " " << my_tree._tree.root().base()->right->data.second << " " << my_tree._tree.root().base()->right->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->right->data.first << " " << my_tree._tree.root().base()->left->right->data.second << " " << my_tree._tree.root().base()->left->right->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(20, "Madness "));
        std::cout << my_tree._tree.root()->first << " " << my_tree._tree.root()->second << " " << my_tree._tree.root().base()->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->data.first << " " << my_tree._tree.root().base()->left->data.second << " " << my_tree._tree.root().base()->left->color << std::endl;
        std::cout << my_tree._tree.root().base()->right->data.first << " " << my_tree._tree.root().base()->right->data.second << " " << my_tree._tree.root().base()->right->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->right->data.first << " " << my_tree._tree.root().base()->left->right->data.second << " " << my_tree._tree.root().base()->left->right->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->left->data.first << " " << my_tree._tree.root().base()->left->left->data.second << " " << my_tree._tree.root().base()->left->left->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(10, "... "));
        std::cout << my_tree._tree.root()->first << " " << my_tree._tree.root()->second << " " << my_tree._tree.root().base()->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->data.first << " " << my_tree._tree.root().base()->left->data.second << " " << my_tree._tree.root().base()->left->color << std::endl;
        std::cout << my_tree._tree.root().base()->right->data.first << " " << my_tree._tree.root().base()->right->data.second << " " << my_tree._tree.root().base()->right->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->right->data.first << " " << my_tree._tree.root().base()->left->right->data.second << " " << my_tree._tree.root().base()->left->right->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->left->data.first << " " << my_tree._tree.root().base()->left->left->data.second << " " << my_tree._tree.root().base()->left->left->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->left->left->data.first << " " << my_tree._tree.root().base()->left->left->left->data.second << " " << my_tree._tree.root().base()->left->left->left->color << std::endl;
        std::cout << std::endl;

        my_tree.insert(ft::make_pair(170, "..170.. "));
        my_tree.insert(ft::make_pair(140, "..140.. "));
        my_tree.insert(ft::make_pair(120, "..120.. "));
        std::cout << my_tree._tree.root()->first << " " << my_tree._tree.root()->second << " " << my_tree._tree.root().base()->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->data.first << " " << my_tree._tree.root().base()->left->data.second << " " << my_tree._tree.root().base()->left->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->right->data.first << " " << my_tree._tree.root().base()->left->right->data.second << " " << my_tree._tree.root().base()->left->right->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->left->data.first << " " << my_tree._tree.root().base()->left->left->data.second << " " << my_tree._tree.root().base()->left->left->color << std::endl;
        std::cout << my_tree._tree.root().base()->left->left->left->data.first << " " << my_tree._tree.root().base()->left->left->left->data.second << " " << my_tree._tree.root().base()->left->left->left->color << std::endl;
        std::cout << my_tree._tree.root().base()->right->data.first << " " << my_tree._tree.root().base()->right->data.second << " " << my_tree._tree.root().base()->right->color << std::endl;
        std::cout << my_tree._tree.root().base()->right->left->data.first << " " << my_tree._tree.root().base()->right->left->data.second << " " << my_tree._tree.root().base()->right->left->color << std::endl;
        std::cout << my_tree._tree.root().base()->right->right->data.first << " " << my_tree._tree.root().base()->right->right->data.second << " " << my_tree._tree.root().base()->right->right->color << std::endl;
        std::cout << my_tree._tree.root().base()->right->left->left->data.first << " " << my_tree._tree.root().base()->right->left->left->data.second << " " << my_tree._tree.root().base()->right->left->left->color << std::endl;
        std::cout << std::endl;
    }
    tree_picture( my_tree );*/
}
