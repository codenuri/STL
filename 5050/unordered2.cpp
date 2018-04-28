#include <iostream>
#include <string>
#include <functional>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;

    s.insert(30);
    s.insert(40);   // set : < 사용,  unordered : hash 함수
    s.insert(20);
    s.insert(10);
    s.insert(45);
    s.insert(25);

    s.find(20); // set : 루트 부터 < 사용, unordered : hash 함수

    // set : 정렬유지, unordered :
    for ( auto n : s)
        cout << n << endl;
}








//
