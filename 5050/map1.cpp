#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, string> m;

    // 1. pair 만들어서 insert
    pair<string, string> p1("월요일","mon");
    m.insert( p1 );

    // 2. make_pair
    m.insert( make_pair("화요일","tue"));

    // 3. [] 연산
    m[ "수요일"] = "wed";

    cout << m[ "월요일"] << endl; // "mon"
    cout << m[ "토요일"] << endl; // make_pair("토요일", "") 항목추가


    auto ret = m.find("일요일");
    if ( ret == m.end())
        cout << "fail" << endl;
}






//
