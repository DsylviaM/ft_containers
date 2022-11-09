#include <iostream>
#include <vector>
#include <vector.hpp>

void    check_constructor();
void    check_asisgn();
void    check_Element_access_and_iterators();
void    check_capacity();
void    check_clear(); 
void    check_insert_erase_21_4_and_22_2();
void    check_insert_erase_21_1_3_and_22_1();
void    check_insert_iter();
void    check_push_back_pop_back();
void    check_resize();
void    check_swap();
void    check_non_member_functions();

template < class T>
void print_vector(T & characters);

template < class T>
void print_vector(T & characters) {
    for (typename T::iterator iter = characters.begin();
         iter != characters.end(); ++iter) {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;  
}

void    check_constructor() {
    std::cout << std::endl << "\033[35m" << "CHECK CONSTRUCTORS " << "\033[0m" << std::endl;
    std::cout << "\033[35m" << "with capacity, size \n"
                 "\t(constructor)\n"
                 "\t(destructor)\n" 
                 "\toperator=\n" 
                 "\tassign\n" 
                 "\tget_allocator\n" 
                 "\033[0m" << std::endl;
    {
        std::cout << std::endl << "\033[33m" << "*****1.1*****" << "\033[0m" << std::endl;
        std::cout << std::endl << "\033[33m" << "*************" << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t1) vector(); " << "\033[0m" << std::endl;
        std::vector<int> std_vec_int;
        ft::vector<int>  ft_vec_int;

    }

    {
        std::cout << std::endl << "\033[33m" << "*****1.2*****" << "\033[0m" << std::endl;
        std::cout << std::endl << "\033[33m" << "*************" << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t2) explicit vector( const Allocator& alloc ); " << "\033[0m" << std::endl;
        std::allocator<int> alloc;
        std::vector<int> std_vec_int(alloc);
        std::allocator<int> alloc1;
        ft::vector<int>  ft_vec_int(alloc1);
        std_vec_int.push_back(5);
        ft_vec_int.push_back(5);
        for (int i=0; i<100; i++) std_vec_int.push_back(i);
        for (int i=0; i<100; i++) ft_vec_int.push_back(i);
       
        std::cout << "**************** capacity STL: " << std_vec_int.capacity()  << std::endl;
       
        std::cout << "**************** capacity FT: " << ft_vec_int.capacity() << std::endl;

        std::cout << std_vec_int[0] << "    |  " << ft_vec_int[0] << std::endl;
        std::cout << "\n\033[36m" << "\t\tpush_back(5) " << "\033[0m"  << std::endl;
        std::cout << "std  |  ft " << std::endl;
        
        
        std::cout << std_vec_int[0] << "    |  " << ft_vec_int[0] << std::endl;
        std::cout << "capacity: " << std_vec_int.capacity() << "   *   " << ft_vec_int.capacity() << std::endl;
        std::cout << "    size: " << std_vec_int.size() << "   *   " << ft_vec_int.size() << std::endl;
    }

    {
        std::cout << std::endl << "\033[33m" << "*****1.3*****" << "\033[0m" << std::endl;
        std::cout << std::endl << "\033[33m" << "*************" << "\033[0m" << std::endl;

        std::cout << "\n\033[34m" << "\t3) explicit vector( size_type count,\n"
                 "\t\t\t    const T& value = T(),\n"
                 "\t\t\t    const Allocator& alloc = Allocator());" 
                 "\n\t5 elements " << "\033[0m" << std::endl;
        std::vector<int> std_vec_int;
        std_vec_int.push_back(5);
        std_vec_int.push_back(1);

        ft::vector<int> ft_vec_int;
        ft_vec_int.push_back(5);
        ft_vec_int.push_back(1);

        std::cout << "         std  |  ft " << std::endl;
        std::cout << "capacity: " << std_vec_int.capacity() << "   |   " << ft_vec_int.capacity() << std::endl;
        std::cout << "size:     " << std_vec_int.size() << "   |   " << ft_vec_int.size() << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "\n\033[34m" << "\t3) for int\n"
                 "\n\t        ft::vector<int> data(5, 5); " << "\033[0m" << std::endl;
        std::cout << "\n\033[36m" << "\t\tcout " << "\033[0m"  << std::endl;
    
        ft::vector<int> data(5, 5);
        for (int i = 0; i < 5; ++i) {
            std::cout << data[i];
        }
        std::cout << std::endl;
    }

    {
        std::cout << "\n\033[34m" << "\t5 elements, std::string \"hello word!\" " << "\033[0m" << std::endl;
        int size = 5;
        std::vector<std::string> std_vec_str(size, "hello word! ");
        ft::vector<std::string>  ft_vec_str(size, "hello word! ");
    
        std::cout << "         std  |  ft " << std::endl;
        std::cout << "capacity: " << std_vec_str.capacity() << "   |   " << ft_vec_str.capacity() << std::endl;
        std::cout << "size:     " << std_vec_str.size() << "   |   " << ft_vec_str.size() << std::endl;
        std::cout << "\n\033[36m" << "\t\tcout " << "\033[0m"  << std::endl;
        std::cout << "         std  |  ft " << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << std_vec_str[i] << "  |  " << ft_vec_str[i] << std::endl;
    
        }
        std::cout << std::endl;
    }

    {
        std::cout << "\n\033[34m" << "\t5 elements, std::string \"hello \", allocator " << "\033[0m" << std::endl;
        int size = 5;
        std::allocator<std::string> alloc;
        std::vector<std::string> std_vec_str(size, "hello ", alloc);
        ft::vector<std::string>  ft_vec_str(size, "hello ", alloc);
    
        std::cout << "         std  |  ft " << std::endl;
        std::cout << "capacity: " << std_vec_str.capacity() << "   |   " << ft_vec_str.capacity() << std::endl;
        std::cout << "size:     " << std_vec_str.size() << "   |   " << ft_vec_str.size() << std::endl;
        std::cout << "\n\033[36m" << "\t\tcout " << "\033[0m"  << std::endl;
        std::cout << "   std  |  ft " << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << std_vec_str[i] << "  |  " << ft_vec_str[i] << std::endl;
        }
        std::cout << std::endl;
    }

    {
        std::cout << std::endl << "\033[33m" << "*****1.5*****" << "\033[0m" << std::endl;
        std::cout << std::endl << "\033[33m" << "*************" << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t5) template< class InputIt >\n"
                                     "\t   vector( InputIt first, InputIt last,\n"
                                     "\t\t   const Allocator& alloc = Allocator() ); "
                                     << "\033[0m" << std::endl;
        std::vector<std::string>    vect_for_iter;
        vect_for_iter.push_back("Hello ");
        vect_for_iter.push_back("my ");
        vect_for_iter.push_back("very ");
        vect_for_iter.push_back("beautiful ");
        vect_for_iter.push_back("world ");
        vect_for_iter.push_back("!!!\n");
        std::cout << "\n\033[36m" << "\t\tcout std:" << "\033[0m"  << std::endl;
        std::vector<std::string>::iterator  iter = vect_for_iter.begin();
        for (;iter < vect_for_iter.end(); ++iter) {
            std::cout << *iter;
        }

    
        std::cout << "\n\033[36m" << "\t\tcout ft:" << "\033[0m"  << std::endl;
        iter = vect_for_iter.begin();
        std::vector<std::string>::iterator  iter_end = vect_for_iter.end();
        ft::vector<std::string>    ft_vect(iter, iter_end);
        ft::vector<std::string>::iterator  ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;
    }
    
    {
        std::cout << std::endl << "\033[33m" << "*****1.6***** *****3*****" << "\033[0m" << std::endl;
        std::cout << std::endl << "\033[33m" << "**************************" << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t6) vector( const vector& other );"
                                     << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\toperator=\n"
                                  << "\033[0m" << std::endl;
        std::vector<std::string>    vect_for_iter;
        vect_for_iter.push_back("Hello ");
        vect_for_iter.push_back("my ");
        vect_for_iter.push_back("very ");
        vect_for_iter.push_back("beautiful ");
        vect_for_iter.push_back("world ");
        vect_for_iter.push_back("!!!\n");
        ft::vector<std::string>    ft_vect(vect_for_iter.begin(), vect_for_iter.begin() + vect_for_iter.size());
        ft::vector<std::string>    ft_vect_copy = ft_vect;
        ft::vector<std::string>::iterator ft_iter = ft_vect_copy.begin();
        for (;ft_iter < ft_vect_copy.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect_copy.capacity() << std::endl;
        std::cout << "size:     " << ft_vect_copy.size() << std::endl;

        ft::vector<std::string>    ft_ft_vect(vect_for_iter.data(), vect_for_iter.data() + vect_for_iter.size());
        std::vector<std::string>    ft_ft_ft_vect(vect_for_iter.data(), vect_for_iter.data() + vect_for_iter.size());
    }
}

void    check_asisgn() {
    {
        ft::vector<char> characters;

        std::cout << std::endl << "\033[33m" << "*****4.1***** characters" << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t4.1) void assign( size_type count, const T& value );  " << "\033[0m" << std::endl;

        characters.assign(5, 'a');
            for (ft::vector<char>::iterator iter = characters.begin();
            iter != characters.end(); ++iter) {
            std::cout << *iter << ' ';
        }
        std::cout << std::endl; 
        std::cout << "capacity: " << characters.capacity() << std::endl;
        std::cout << "size: " << characters.size() << std::endl;

        std::cout << std::endl << "\033[33m" << "*****4.2***** characters" << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t4.2) template< class InputIt >\n"
                                "\t     void assign( InputIt first, InputIt last );  " << "\033[0m" << std::endl;

        const std::string extra(6, 'b');
        characters.assign(extra.begin(), extra.end());
            for (ft::vector<char>::iterator iter = characters.begin();
            iter != characters.end(); ++iter) {
            std::cout << *iter << ' ';
        }
        std::cout << std::endl;
        std::cout << "capacity: " << characters.capacity() << std::endl;
        std::cout << "size: " << characters.size() << std::endl;
    }
    {
        ft::vector<int> integers;

        std::cout << std::endl << "\033[33m" << "*****4.1***** integers" << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t4.1) void assign( size_type count, const T& value );  " << "\033[0m" << std::endl;

        integers.assign(5, 0);
            for (ft::vector<int>::iterator iter = integers.begin();
            iter != integers.end(); ++iter) {
            std::cout << *iter << ' ';
        }
        std::cout << std::endl;
        std::cout << "capacity: " << integers.capacity() << std::endl;
        std::cout << "size: " << integers.size() << std::endl;

        std::cout << std::endl << "\033[33m" << "*****4.2****** integers" << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t4.2) template< class InputIt >\n"
                                "\t     void assign( InputIt first, InputIt last );  " << "\033[0m" << std::endl;

        const std::string extra_integers(6, 6);
        integers.assign(extra_integers.begin(), extra_integers.end());
            for (ft::vector<int>::iterator iter = integers.begin();
            iter != integers.end(); ++iter) {
            std::cout << *iter << ' ';
        }
        std::cout << std::endl;
        std::cout << "capacity: " << integers.capacity() << std::endl;
        std::cout << "size: " << integers.size() << std::endl;
    }
}

void    check_Element_access_and_iterators() {
    // https://en.cppreference.com/w/cpp/container/vector/at

    std::cout << std::endl << "\033[35m" << "check ELEMENT ACCESS " << "\033[0m" << std::endl;
    std::cout << "\033[35m" << 
                 "\tat\n"
                 "\toperator[]\n" 
                 "\tfront\n" 
                 "\tback\n" 
                 "\tdata\n" 
                 "\033[0m" << std::endl;

    std::cout << std::endl << "\033[33m" << "*****6 - 10*****     Element access" << "\033[0m" << std::endl;

    ft::vector<int> data;
    data.insert(data.end(), 1, 6);
    data.insert(data.end(), 1, 5);
    data.insert(data.end(), 1, 5);
    data.insert(data.end(), 2, 4);
    data.insert(data.end(), 2, 2);
    data.insert(data.end(), 3, 1);

    for (int i = 0; static_cast<size_t>(i) < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\033[34m" << "\t6) at " << "\033[0m" << std::endl;

    
    data.at(1) = 88;
    std::cout << "data.at(1) = 88, cout data[1]: " << data[1] << std::endl;
 
    // Read element 2
    std::cout << "Element at index 2 has value " << data.at(2) << '\n';
 
    std::cout << "data size = " << data.size() << '\n';

    std::cout << std::endl;
    try {
        // Set element 7
        std::cout << "try: data.at(7) = 666" << std::endl;

        data.at(7) = 666;
    } catch (std::out_of_range const& exc) {
        std::cout << exc.what() << '\n';
    }
    std::cout << std::endl;
 
    // Print final values
    std::cout << "Print final values. \ndata:";
    for (long unsigned int i = 0; i < data.size(); ++i)
        std::cout << " " << data[i];
    std::cout << "\n\n";

    std::cout << "\033[34m" << "\t7) operator[] " << "\033[0m" << std::endl;
    std::cout << "data[2] = " << data[2] << std::endl;

    std::cout << "\033[34m" << "\t8) front " << "\033[0m" << std::endl;
    std::cout << "front = " << data.front() << std::endl;

    std::cout << "\033[34m" << "\t9) back " << "\033[0m" << std::endl;
    std::cout << "back = " << data.back() << std::endl;

    std::cout << "\033[34m" << "\t10) data " << "\033[0m" << std::endl;
    std::cout << "*data.data() = " << *data.data() << std::endl;
    std::cout << " data.data() = " << data.data() << std::endl;

    std::cout << std::endl << "\033[35m" << "check ITERATORS " << "\033[0m" << std::endl;
    std::cout << "\033[35m" << 
                 "\tbegin\n"
                 "\tend\n" 
                 "\trbegin\n" 
                 "\trend\n"  
                 "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "*****11-14*****     iterators" << "\033[0m" << std::endl;
    
    std::cout << "\033[34m" << "\t11) begin " << "\033[0m" << std::endl;
    std::cout << "*data.begin(); \n" << *data.begin() << std::endl;

    std::cout << "\033[34m" << "\t12) end " << "\033[0m" << std::endl;
    std::cout << "*(data.end() - 1); \n" << *(data.end() - 1) << std::endl;

    std::cout << "\033[34m" << "\t13) rbegin " << "\033[0m" << std::endl;
    std::cout << "*data.rbegin(); \n" << *data.rbegin() << std::endl;

    std::cout << "\033[34m" << "\t14) rend " << "\033[0m" << std::endl;
    std::cout << "*(data.rend() - 1); \n" << *(data.rend() - 1) << std::endl;

}

void    check_capacity() {
    std::cout << std::endl << "\033[35m" << "check CAPACITY " << "\033[0m" << std::endl;
    std::cout << "\033[35m" << 
                 "\tempty\n"
                 "\tsize\n" 
                 "\tmax_size\n" 
                 "\treserve\n"
                 "\tcapacity\n"
                 "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "*****15-19*****     " << "\033[0m" << std::endl;
    
    std::cout << "\033[34m" << "\t15) empty " << "\033[0m" << std::endl;
        std::cout << std::boolalpha;
    ft::vector<int> numbers;
    std::cout << "Initially, numbers.empty():            " << numbers.empty() << "\n\n";
    numbers.assign(5, 5);
    std::cout << "After adding elements\nnumbers.assign(5, 5); numbers.empty(): " << numbers.empty() << '\n';

    std::cout << "\033[34m" << "\t16) size " << "\033[0m" << std::endl;
    std::cout << "numbers.size(); \n" << numbers.size() << std::endl;

    std::cout << "\033[34m" << "\t17) max_size " << "\033[0m" << std::endl;
    std::cout << "numbers.max_size(); \n" << numbers.max_size() << std::endl;

    std::cout << "\033[34m" << "\t18) reserve " << "\033[0m" << std::endl;
    numbers.reserve(2);
    std::cout << "numbers.reserve(2);  capacity: " << numbers.capacity() << std::endl;
    numbers.reserve(5);
    std::cout << "numbers.reserve(5);  capacity: " << numbers.capacity() << std::endl;
    numbers.reserve(8);
    std::cout << "numbers.reserve(8); capacity: " << numbers.capacity() << std::endl;
    std::cout << "print_vector(numbers): ";
    print_vector(numbers);

    std::cout << "\033[34m" << "\t19) capacity " << "\033[0m" << std::endl;
    std::cout << "numbers.capacity(); \n" << numbers.capacity() << std::endl;
}

void    check_clear() {
    std::cout << std::endl << "\033[33m" << "_____20_____     " << "\033[0m" << std::endl;
    
    std::cout << "\033[34m" << "\t20) clear " << "\033[0m" << std::endl;
    ft::vector<std::string>    vect_clear(5);
    vect_clear[0] = "Hello, ";
    vect_clear[1] = "my ";
    vect_clear[2] = "beautiful ";
    vect_clear[3] = "world ";
    vect_clear[4] = "!!!";
    std::cout << "\n\033[36m" << "\t\tcout vect_clear" << "\033[0m"  << std::endl;
    print_vector(vect_clear);
    std::cout << "capacity: " << vect_clear.capacity() << std::endl;
    std::cout << "size: " << vect_clear.size() << std::endl;
    std::cout << std::endl;
    vect_clear.clear();
    std::cout << "vect_clear.clear();" << std::endl;
    print_vector(vect_clear);
    std::cout << "capacity: " << vect_clear.capacity() << std::endl;
    std::cout << "size: " << vect_clear.size() << std::endl;
}

void    check_insert_erase_21_4_and_22_2() {
    std::cout << std::endl << "\033[33m" << "******21*****     4" << "\033[0m" << std::endl;
    
    {
        std::cout << "\n\033[34m" << "\t21.4) template< class InputIt >\n"
                                     "\t   void insert( iterator pos, InputIt first, InputIt last ); "
                                     << "\033[0m" << std::endl;
        std::vector<std::string>    vect_for_iter;
        vect_for_iter.push_back("Hello ");
        vect_for_iter.push_back("my ");
        vect_for_iter.push_back("very ");
        vect_for_iter.push_back("beautiful ");
        vect_for_iter.push_back("world ");
        vect_for_iter.push_back("!!!\n");
        std::vector<std::string>::iterator  iter = vect_for_iter.begin();
        for (;iter < vect_for_iter.end(); ++iter) {
            std::cout << *iter;
        }
        iter = vect_for_iter.begin();

        ft::vector<std::string>    ft_vect(vect_for_iter.begin(), vect_for_iter.end());
        ft::vector<std::string>::iterator  ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        ft_vect.insert(ft_vect.begin() + ft_vect.size()/3*2, vect_for_iter.begin(), vect_for_iter.end() - 1);
        ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        ft_vect.insert(ft_vect.begin() + ft_vect.size()/3*2, vect_for_iter.begin().base(), vect_for_iter.begin().base() + 4);
        ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        ft_vect.insert(ft_vect.begin() + ft_vect.size()/3*2, vect_for_iter.begin(), vect_for_iter.begin() + 1);
        ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;
       // std::cout << "base:     " << vect_for_iter.begin().base() << std::endl;

        ft_vect.insert(ft_vect.begin() + ft_vect.size()/3*2, vect_for_iter.begin().base(), vect_for_iter.begin().base() + 1);
        ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;
        std::cout << std::endl << "\033[33m" << "*****22*****     2" << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t22.2) iterator erase( iterator first, iterator last );"
                                  << "\033[0m" << std::endl;
        ft_vect.erase(ft_vect.begin() + 4, ft_vect.begin() + 6);
        ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        std::cout << std::endl << "\033[33m" << "*****20*****     " << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t20) void clear();"
                                  << "\033[0m" << std::endl;
        ft_vect.clear();
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;
    }
}

void    check_insert_iter() {
    std::cout << std::endl << "\033[33m" << "*****21*****     4 for int" << "\033[0m" << std::endl;
    {
        std::cout << "\n\033[34m" << "\t21.4) template< class InputIt >\n"
                                     "\t   void insert( iterator pos, InputIt first, InputIt last ); "
                                     << "\033[0m" << std::endl;
        std::vector<int>    vect_for_iter(5);

        std::vector<int>::iterator  iter = vect_for_iter.begin();
        for (int i = 0;iter < vect_for_iter.end(); ++iter, ++i) {
            *iter = i;
            std::cout << *iter;
        }
        std::cout << std::endl;

        std::cout << "****************" << std::endl;
        ft::vector<int>    vect_for_iter_copy;
        iter = vect_for_iter.begin();
        vect_for_iter_copy.insert(vect_for_iter_copy.begin(), vect_for_iter.data(), vect_for_iter.data() + vect_for_iter.size());
        ft::vector<int>::iterator  ft_iter = vect_for_iter_copy.begin();
        for (int i = 0; ft_iter < vect_for_iter_copy.end(); ++ft_iter, ++i) {
            *ft_iter = i;
            std::cout << *ft_iter;
        }
        std::cout << std::endl;
    }
}

void    check_insert_erase_21_1_3_and_22_1() {
    std::cout << std::endl << "\033[33m" << "*****21*****     3" << "\033[0m" << std::endl;
            std::cout << "\n\033[34m" << "\t21.3) "
                                     "void insert( iterator pos, size_type count, const T& value ); "
                                     << "\033[0m" << std::endl;
        std::vector<std::string>    vect_for_iter;
        vect_for_iter.push_back("Hello ");
        vect_for_iter.push_back("my ");
        vect_for_iter.push_back("very ");
        vect_for_iter.push_back("beautiful ");
        vect_for_iter.push_back("world ");
        vect_for_iter.push_back("!!!\n");
        std::vector<std::string>::iterator  iter = vect_for_iter.begin();
        for (;iter < vect_for_iter.end(); ++iter) {
            std::cout << *iter;
        }
        iter = vect_for_iter.begin();

        ft::vector<std::string>    ft_vect(vect_for_iter.begin(), vect_for_iter.end());
        ft_vect.insert(ft_vect.begin() + 2, 3, "BOOO");
        ft::vector<std::string>::iterator  ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        ft_vect.insert(ft_vect.begin() + 2, 1, "_A_");
        ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        std::cout << std::endl << "\033[33m" << "*****21*****     1" << "\033[0m" << std::endl;
            std::cout << "\n\033[34m" << "\t21.1) "
                                     "iterator insert( iterator pos, const T& value ); "
                                     << "\033[0m" << std::endl;
        ft_vect.insert(ft_vect.begin() + 4, "..m(*_*)m..");
        ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        ft::vector<std::string>::iterator ft_iter_insert = ft_vect.insert(ft_vect.end() - 2, "..m(*_*)m..");
        ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "\n\033[36m" << "\t\tafter insert: " << "\033[0m"  << std::endl;
        for (;ft_iter_insert < ft_vect.end(); ++ft_iter_insert) {
            std::cout << *ft_iter_insert;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        std::cout << std::endl << "\033[33m" << "*****22*****     1" << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t22.1) "
                                     "iterator erase( iterator pos ); "
                                     << "\033[0m" << std::endl;
        ft::vector<std::string>::iterator ft_iter_erase = ft_vect.erase(ft_vect.begin() + 4);
        ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "\n\033[36m" << "\t\tafter erase: " << "\033[0m"  << std::endl;
        for (;ft_iter_erase < ft_vect.end(); ++ft_iter_erase) {
            std::cout << *ft_iter_erase;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        {
              // std example (erase)
            std::cout << "\n\033[34m" << "\tstd example \033[0m\n";

            std::vector<std::string>    vect_for_iter1;
            vect_for_iter1.push_back("Hello ");
            vect_for_iter1.push_back("my ");
            vect_for_iter1.push_back("very ");
            vect_for_iter1.push_back("beautiful ");
            vect_for_iter1.push_back("world ");
            vect_for_iter1.push_back("!!!\n");
            std::vector<std::string>::iterator  iter = vect_for_iter1.begin();
            for (;iter < vect_for_iter1.end(); ++iter) {
                std::cout << *iter;
            }
            std::vector<std::string>::iterator std_iter_erase = 
                vect_for_iter1.erase(vect_for_iter1.begin() + 1);
            iter = vect_for_iter1.begin();
            for (;iter < vect_for_iter1.end(); ++iter) {
                std::cout << *iter;
            }
            std::cout << "\033[36m" << "\t\tafter erase: " << "\033[0m"  << std::endl;
            for (;std_iter_erase < vect_for_iter1.end(); ++std_iter_erase) {
                std::cout << *std_iter_erase;
            }
        }
}

void    check_push_back_pop_back() {
    std::cout << std::endl << "\033[33m" << "*****23*****" << "\033[0m" << std::endl;
    std::cout << "\n\033[34m" << "\t23) "
                                    "void push_back( const T& value ); "
                                    << "\033[0m" << std::endl;
    ft::vector<int> vect_int;
    vect_int.push_back(0);
    vect_int.push_back(1);
    vect_int.push_back(2);
    vect_int.push_back(3);
    vect_int.push_back(4);
    vect_int.push_back(5);
    ft::vector<int>::iterator vect_int_iter = vect_int.begin();
    for (; vect_int_iter != vect_int.end(); ++vect_int_iter) {
        std::cout << *vect_int_iter << " ";
    }
    std::cout << std::endl;
    std::cout << "capacity: " << vect_int.capacity() << std::endl;
    std::cout << "size:     " << vect_int.size() << std::endl;

    {
        std::cout << std::endl << "\033[33m" << "*****24*****" << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t24) "
                                    "void pop_back( ); "
                                    << "\033[0m" << std::endl;
        vect_int.pop_back();
        vect_int_iter = vect_int.begin();
        for (; vect_int_iter != vect_int.end(); ++vect_int_iter) {
            std::cout << *vect_int_iter << " ";
        }
        std::cout << std::endl;
        std::cout << "capacity: " << vect_int.capacity() << std::endl;
        std::cout << "size:     " << vect_int.size() << std::endl;
    }
}

void    check_resize() {
    std::cout << std::endl << "\033[33m" << "*****25*****" << "\033[0m" << std::endl;
    std::cout << "\n\033[34m" << "\t25) "
                                 "void resize( size_type count, T value = T() ); "
                              << "\033[0m" << std::endl;

    std::cout << "\n\033[34m" << " _____FT_____ "
                              << "\033[0m" << std::endl;
    
    ft::vector<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    std::cout << "The vector holds: ";
    print_vector(c);
    std::cout << "Capacity: "<< c.capacity()<<std::endl;
    c.resize(5);
    std::cout << "After resize up to 5: ";
    print_vector(c);
    std::cout << "Capacity: "<< c.capacity()<<std::endl;
    c.resize(2);
    std::cout << "After resize down to 2: ";
    print_vector(c);
    std::cout << "Capacity: "<< c.capacity()<<std::endl;
    c.resize(9, 4);
    std::cout << "After resize up to 9 (initializer = 4): ";
    print_vector(c);
    std::cout << "Capacity: "<< c.capacity()<<std::endl;
    
    std::cout << "\n\033[34m" << " _____STD_____ "
                              << "\033[0m" << std::endl;

    std::vector<int> f;
    f.push_back(1);
    f.push_back(2);
    f.push_back(3);
    std::cout << "The vector holds: ";
    print_vector(f);
    std::cout << "Capacity: "<< f.capacity()<<std::endl;
    f.resize(5);
    std::cout << "After resize up to 5: ";
    print_vector(f);
    std::cout << "Capacity: "<< f.capacity()<<std::endl;
    f.resize(2);
    std::cout << "After resize down to 2: ";
    print_vector(f);
    std::cout << "Capacity: "<< f.capacity()<<std::endl;
    f.resize(9, 4);
    std::cout << "After resize up to 9 (initializer = 4): ";
    print_vector(f);
    std::cout << "Capacity: "<< f.capacity()<<std::endl;
}

void    check_swap() {
    std::cout << std::endl << "\033[33m" << "*****26*****" << "\033[0m" << std::endl;
    std::cout << "\n\033[34m" << "\t26) "
                                 "void swap( vector& other ); "
                              << "\033[0m" << std::endl;
    std::vector<int> a1, a2;
    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(3);
    a2.push_back(4);
    a2.push_back(5);

    ft::vector<int> b1, b2;
    b1.push_back(1);
    b1.push_back(2);
    b1.push_back(3);
    b2.push_back(4);
    b2.push_back(5);
 
    std::vector<int>::iterator it1 = a1.begin() + 1;
    std::vector<int>::iterator it2 = a2.begin() + 1;

    ft::vector<int>::iterator it3 = b1.begin() + 1;
    ft::vector<int>::iterator it4 = b2.begin() + 1;
 
    int& ref1 = a1.front();
    int& ref2 = a2.front();

    int& ref3 = b1.front();
    int& ref4 = b2.front();

    std::cout << "\n\033[36m" << "\t\tbefor swap: " << "\033[0m"  << std::endl;
    std::cout << "\t vectors: "  << std::endl;
    print_vector(a1);
    print_vector(a2);
    print_vector(b1);
    print_vector(b2);

    std::cout << "\t   STD "  << "\t\t    FT " << std::endl;
    std::cout << "\t *it1: " << *it1 << "\t | *it3: " << *it3 << std::endl;
    std::cout << "\t *it2: " << *it2 << "\t | *it4: " << *it4 << std::endl;
    std::cout << "\t ref1: " << ref1 << "\t | ref3: " << ref3 << std::endl;
    std::cout << "\t ref2: " << ref2 << "\t | ref4: " << ref4 << std::endl;
    std::cout << "a1 capacity: " << a1.capacity() << "...|b1 capacity: " << b1.capacity() << std::endl;
    std::cout << "a1 size:     " << a1.size() << "...|b1 size:     " << b1.size() <<std::endl;
    std::cout << "a2 capacity: " << a2.capacity() << "...|b2 capacity: " << b2.capacity()<< std::endl;
    std::cout << "a2 size:     " << a2.size() << "...|b2 size:     " << b2.size()<<std::endl;

    std::cout << "\n\033[36m" << "\t\tafter swap: " << "\033[0m"  << std::endl;
    a1.swap(a2);
    b1.swap(b2);
    std::cout << "\t vectors: "  << std::endl;
    print_vector(a1);
    print_vector(a2);
    print_vector(b1);
    print_vector(b2);
    
    std::cout << "\t   STD "  << "\t\t    FT " << std::endl;
    std::cout << "\t *it1: " << *it1 << "\t | *it3: " << *it3 << std::endl;
    std::cout << "\t *it2: " << *it2 << "\t | *it4: " << *it4 << std::endl;
    std::cout << "\t ref1: " << ref1 << "\t | ref3: " << ref3 << std::endl;
    std::cout << "\t ref2: " << ref2 << "\t | ref4: " << ref4 << std::endl;
    std::cout << "a1 capacity: " << a1.capacity() << "...|b1 capacity: " << b1.capacity() << std::endl;
    std::cout << "a1 size:     " << a1.size() << "...|b1 size:     " << b1.size() <<std::endl;
    std::cout << "a2 capacity: " << a2.capacity() << "...|b2 capacity: " << b2.capacity()<< std::endl;
    std::cout << "a2 size:     " << a2.size() << "...|b2 size:     " << b2.size()<<std::endl;
    
}

void    check_non_member_functions() {
    std::cout << std::endl << "\033[35m" << "check NON-MEMBER FUNCTIONS " << "\033[0m" << std::endl;
    std::cout << "\033[35m" << 
                 "\t operator== \n"
                 "\t operator!= \n" 
                 "\t operator< \n" 
                 "\t operator<= \n"
                 "\t operator> \n"
                 "\t operator>= \n"
                 "\t swap \n"
                 "\033[0m" << std::endl;
    ft::vector<std::string>    vect1;
    vect1.push_back("It's ");
    vect1.push_back("a ");
    vect1.push_back("beautiful ");
    vect1.push_back("life, ");
    vect1.push_back("oh ");
    vect1.push_back("oh ");
    vect1.push_back("oh ");
    vect1.push_back("oh ");
    ft::vector<std::string>    vect2(vect1);
    std::cout << std::boolalpha;
    vect2.reserve(vect2.capacity() + 10);

    std::cout << std::endl << "\033[33m" << "*****27-32*****" << "\033[0m" << std::endl;
    std::cout << "\n\033[34m" << "\t27) template< class T, class Alloc >\n"
                                 "\t\tbool operator==( const std::vector<T,Alloc>& lhs,\n"
                                 "\t\t                 const std::vector<T,Alloc>& rhs ); \n"
                              << "\033[0m" << std::endl;
    std::cout << "\n\033[34m" << "\t28) template< class T, class Alloc >\n"
                                 "\t\tbool operator!=( const std::vector<T,Alloc>& lhs,\n"
                                 "\t\t                 const std::vector<T,Alloc>& rhs ); \n"
                              << "\033[0m" << std::endl;
    std::cout << "operator== equal:     " << (vect1 == vect2) << std::endl;
    std::cout << "operator!= equal:     " << (vect1 != vect2) << std::endl;
    vect1.push_back("oh\n");
    std::cout << "operator== not equal: " << (vect1 == vect2) << std::endl;
    std::cout << "operator!= not equal: " << (vect1 != vect2) << std::endl;

    std::cout << "\n\033[34m" << "\t29) template< class T, class Alloc >\n"
                                 "\t\tbool operator<( const std::vector<T,Alloc>& lhs,\n"
                                 "\t\t                 const std::vector<T,Alloc>& rhs ); \n"
                              << "\033[0m" << std::endl;
    std::cout << "\n\033[34m" << "\t30) template< class T, class Alloc >\n"
                                 "\t\tbool operator<=( const std::vector<T,Alloc>& lhs,\n"
                                 "\t\t                 const std::vector<T,Alloc>& rhs ); \n"
                              << "\033[0m" << std::endl;
    std::cout << "\n\033[34m" << "\t31) template< class T, class Alloc >\n"
                                 "\t\tbool operator>( const std::vector<T,Alloc>& lhs,\n"
                                 "\t\t                 const std::vector<T,Alloc>& rhs ); \n"
                              << "\033[0m" << std::endl;
    std::cout << "\n\033[34m" << "\t32) template< class T, class Alloc >\n"
                                 "\t\tbool operator>=( const std::vector<T,Alloc>& lhs,\n"
                                 "\t\t                 const std::vector<T,Alloc>& rhs ); \n"
                              << "\033[0m" << std::endl;
    vect1.pop_back();
    std::cout << "equal:     " << std::endl;
    print_vector(vect1);
    print_vector(vect2);

    std::cout << "operator== equal:     " << (vect1 == vect2) << std::endl;
    std::cout << "\t operator<     " << (vect1 < vect2) << std::endl;
    std::cout << "\t operator<=    " << (vect1 <= vect2) << std::endl;
    std::cout << "\t operator>     " << (vect1 > vect2) << std::endl;
    std::cout << "\t operator>=    " << (vect1 >= vect2) << std::endl;
    vect1[2] = 'a';
    print_vector(vect1);
    print_vector(vect2);
    std::cout << "not equal: " << std::endl;
    std::cout << "\t operator<     " << (vect1 < vect2) << std::endl;
    std::cout << "\t operator<=    " << (vect1 <= vect2) << std::endl;
    std::cout << "\t operator>     " << (vect1 > vect2) << std::endl;
    std::cout << "\t operator>=    " << (vect1 >= vect2) << std::endl;


    std::cout << "\n\033[34m" << "\t33) template< class T, class Alloc >\n"
                                 "\t\t void swap( std::vector<T,Alloc>& lhs,\n"
                                 "\t\t std::vector<T,Alloc>& rhs );"
                              << "\033[0m" << std::endl;
    std::vector<int> alice;
    alice.push_back(1);
    alice.push_back(2);
    alice.push_back(3);
    std::vector<int> bob;
    bob.push_back(7);
    bob.push_back(8);
    bob.push_back(9);
    bob.push_back(10);

    std::cout << "\n\033[36m" << "befor SWAP " << "\033[0m"  << std::endl;
    std::cout << "alice: ";
    print_vector(alice);
    std::cout << "bob:   ";
    print_vector(bob);
    
    std::swap(alice, bob);
    std::cout << "\n\033[36m" << "after SWAP " << "\033[0m"  << std::endl;
    std::cout << "alice: ";
    print_vector(alice);
    std::cout << "bob:   ";
    print_vector(bob);
    std::cout << '\n';
}


int main() {
    check_constructor(); // 1, 2, 3, 5
    check_asisgn(); // 4
    check_Element_access_and_iterators(); // 6 - 14
    check_capacity(); // 15 - 19
    std::cout << std::endl << "\033[35m" << "CHECK MODIFIERS " << "\033[0m" << std::endl;
    check_clear(); // 20  
    check_insert_erase_21_4_and_22_2(); // 21.4, 22.2
    check_insert_iter(); // 21.3, 21.4
    check_insert_erase_21_1_3_and_22_1(); // 21.1, 21.3, 22.1
    check_push_back_pop_back(); // 23, 24
    check_resize(); // 25
    check_swap(); // 26
    check_non_member_functions(); // 27-33
}
