#include <assert.h>
#include <iostream>
#include "utility.hpp"
using namespace std;
using namespace ft;

typedef pair<int, char> Pair_ic;
Pair_ic p0;

class Int {
    public:
        Int (int v)
            : val(v) {}
            bool operator == (Int x) const
                {return (val == x.val); }
            bool operator< (Int x) const
                {return (val < x.val); }
    private:
        int val;
};

int main()
{
    Pair_ic p1 = p0, p2(3, 'a');
    //test pair
    assert (p1.first ==0);
    assert (p1.second ==0);
    assert (p2.first == 3);
    assert (p2.second == 'a');
    assert (p2 == make_pair ((Pair_ic::first_type) 3,
        (Pair_ic::second_type) 'a'));
    assert (p2 < make_pair ( (Pair_ic::first_type) 4,
        (Pair_ic::second_type) 'a'));
    assert (p2 < make_pair ( (Pair_ic::first_type) 3,
        (Pair_ic::second_type) 'b'));
    assert(p1 !=p2);
    assert(p2 > p1);
    assert(p2 <= p2);
    assert(p2 >= p2);
    //test rel_ops
    using namespace std::rel_ops;
    Int a(2), b(3);
    assert (a == a);
    assert (a < b);
    assert (a != b);
    assert (b > a);
    assert (a <= b);
    assert (b >= a);
    cout << "SUCCESS testing <utility" <<endl;
    return(0);
};