#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v1 = {1,2,3};

    find   ( begin(v1), end(v1), 3);
    find_if( begin(v1), end(v1), foo);

    sort( begin(v1), end(v1));   // <
    sort( begin(v1), end(v1), goo);



    vector<int> v2 = { 0,0,0};
    remove_copy( begin(v1), end(v1), begin(v2), 3);

    sort_copy( begin(v1), end(v1), begin(v2)); // error
}










//
