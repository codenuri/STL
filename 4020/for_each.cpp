#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include "ecourse_stl.hpp"
using namespace std;

/*
void foo( int& a, str)
{
    //cout << a << endl;
    a = a* 2;
}
*/
struct Show
{
    string sep;
    ostream& os;

    Show( ostream& o = cout, string s = "\n") : os(o), sep(s) {}

    void operator()(int a) const
    {
        os << a << sep;
    }
};

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    //for_each(begin(v), end(v), foo );

    Show s(cout, "\t");
    for_each(begin(v), end(v), s );

    //show(v);

	return 0;
}



















//
