#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<int, string> m;

    m[1] = "ONE";
    m[0] = "ZERO";
    m[2] = "TWO";

    auto p = begin(m); // p 는 pair를 가리키는 포인

    cout << p->first << endl; // 0
    cout << p->second << endl; // "ZERO"
    ++p;
    cout << p->first << endl; // 1
    cout << p->second << endl; // "ONE"



}










//
