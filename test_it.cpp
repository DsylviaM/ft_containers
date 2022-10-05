#include <iostream>
#include <iterator>
#include "ft_iterator.hpp"
#include "ft_iterator_cat.hpp"
#include "ft_iterator_body.hpp"
#include "ft_revers_it.hpp"

void check_iterators();

void check_iterators_reverse();

#include <cstdlib>
//#include <vector.hpp>

int main(void) {
    check_iterators();
    return (0);
}

void check_iterators() {
    std::cout << std::endl
              << "\033[36m"
              << "CHECK ITERATORS "
              << "\033[0m" << std::endl;

    check_iterators_reverse();
}



void check_iterators_reverse() {
    std::cout << "\033[34m"
              << "\treverse "
              << "\033[0m" << std::endl;

    std::cout << "\033[32m"
              << "int a[] = {0, 1, 2, 3};"
              << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "              ↑  └───── x, y"
              << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "              └──────── z"
              << "\033[0m" << std::endl
              << std::endl;
    std::cout << "\033[32m"
              << "reverse_iterator<int*>"
              << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "    x (&a[4]),"
              << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "    y (&a[4]),"
              << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "    z (&a[3]);"
              << "\033[0m" << std::endl
              << std::endl;

    int a[] = {0, 1, 2, 3};

    std::reverse_iterator<int*>
        x(&a[4]),
        y(&a[4]),
        z(&a[3]);

    ft::reverse_iterator<int*>
        x_ft(&a[4]),
        y_ft(&a[4]),
        z_ft(&a[3]);

    std::cout
        << std::boolalpha
        << "*x_std == " << *x << "    |  " << *x_ft << " == *x_ft" << '\n' // 3
        << "*y_std == " << *y << "    |  " << *y_ft << " == *x_ft" << '\n' // 3
        << "*z_std == " << *z << "    |  " << *z_ft << " == *x_ft" << '\n' // 2
        << "x == y ? " << (x == y) << "  | " << (x_ft == y_ft) << '\n'     // true
        << "x != y ? " << (x != y) << " | " << (x_ft != y_ft) << '\n'      // false
        << "x <  y ? " << (x < y) << " | " << (x_ft < y_ft) << '\n'        // false
        << "x <= y ? " << (x <= y) << "  | " << (x_ft <= y_ft) << '\n'     // true
        << "x == z ? " << (x == z) << " | " << (x_ft == z_ft) << '\n'      // false
        << "x != z ? " << (x != z) << "  | " << (x_ft != z_ft) << '\n'     // true
        << "x <  z ? " << (x < z) << "  | " << (x_ft < z_ft) << '\n'       // true!
        << "x <= z ? " << (x <= z) << "  | " << (x_ft <= z_ft) << '\n'     // true
        ;
}
