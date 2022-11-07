#include <iostream>

#include "../src/vector.hpp"
#include "../src/is_integral.hpp"
#include "../src/normal_iterator.hpp"
#include "../src/lexicographical_compare.hpp"

#include <cmath>
#include <memory>
#include <iostream>
#include <sstream>
#include <vector>

int main() {

    std::vector<int> b;
	std::cout << "_________STD_|_FT__________" << std::endl;
	for (int i=0; i<100; i++) b.push_back(i);
	
    ft::vector<int> a;
	for (int i=0; i<100; i++) a.push_back(i);

    std::cout << "_________" << b.capacity() << "_|_"<< a.capacity() <<"__________|" << "_________" <<std::endl;

    std::cout << "******************************************************" << std::endl;
    std::cout << "******************************************************" << std::endl;
    
    std::vector<int> g(0); 
    ft::vector<int> f(0); 
    std::vector<int> h(1); 
    ft::vector<int> k(1); 
    
    std::cout << "_________" << g.capacity() << "_|_"<< f.capacity() <<"__________" << h.capacity() << "_|_"<< k.capacity() <<"__________|" <<std::endl;

    g.push_back(1);   
    f.push_back(1);
    h.push_back(1);   
    k.push_back(1);
std::cout << "_________" << g.capacity() << "_|_"<< f.capacity() <<"__________" << h.capacity() << "_|_"<< k.capacity() <<"__________|" <<std::endl;
    g.push_back(1);
    g.push_back(2);
 
    f.push_back(1);
    f.push_back(2);

    h.push_back(1);
    h.push_back(2); 
    k.push_back(1);  
    k.push_back(2);
   
std::cout << "_________" << g.capacity() << "_|_"<< f.capacity() <<"__________" << h.capacity() << "_|_"<< k.capacity() <<"__________|" <<std::endl;
    g.push_back(1);
    g.push_back(1);
    g.push_back(3);
   
    f.push_back(1);
    f.push_back(1);
    f.push_back(3);

    h.push_back(1);
    h.push_back(2);
    h.push_back(3);  

    k.push_back(1);  
    k.push_back(2);
    k.push_back(3);
std::cout << "_________" << g.capacity() << "_|_"<< f.capacity() <<"__________" << h.capacity() << "_|_"<< k.capacity() <<"__________|" <<std::endl;
    
    g.push_back(1);
    g.push_back(1);
    g.push_back(3);
    g.push_back(4);

    f.push_back(1);
    f.push_back(1);
    f.push_back(3);
    f.push_back(4);

    h.push_back(1);
    h.push_back(2);
    h.push_back(3);
    h.push_back(4);  

    k.push_back(1);  
    k.push_back(2);
    k.push_back(3);
    k.push_back(4);
std::cout << "_________" << g.capacity() << "_|_"<< f.capacity() <<"__________" << h.capacity() << "_|_"<< k.capacity() <<"__________|" <<std::endl;
    g.push_back(1);
    g.push_back(1);
    g.push_back(3);
    g.push_back(4);
    g.push_back(5);

    f.push_back(1);
    f.push_back(1);
    f.push_back(3);
    f.push_back(4);
    f.push_back(5);

    h.push_back(1);
    h.push_back(2);
    h.push_back(3);
    h.push_back(4);
    h.push_back(5);  

    k.push_back(1);  
    k.push_back(2);
    k.push_back(3);
    k.push_back(4);
    k.push_back(5);
    std::cout << "_________" << g.capacity() << "_|_"<< f.capacity() <<"__________" << h.capacity() << "_|_"<< k.capacity() <<"__________|" <<std::endl;
    
    g.push_back(1);
    g.push_back(1);
    g.push_back(3);
    g.push_back(4);
    g.push_back(5);
    g.push_back(6);

    f.push_back(1);
    f.push_back(1);
    f.push_back(3);
    f.push_back(4);
    f.push_back(5);
    f.push_back(6);

    h.push_back(1);
    h.push_back(2);
    h.push_back(3);
    h.push_back(4);
    h.push_back(5);
    h.push_back(6);  

    k.push_back(1);  
    k.push_back(2);
    k.push_back(3);
    k.push_back(4);
    k.push_back(5);
    k.push_back(6);
    std::cout << "_________" << g.capacity() << "_|_"<< f.capacity() <<"__________" << h.capacity() << "_|_"<< k.capacity() <<"__________|" <<std::endl;
    
    
    
    return 0;
}

