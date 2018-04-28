#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


struct FindChar
{
    string data;

    FindChar( string s) : data(s) {}

    bool operator()(char c) const
    {
        auto p = find( begin(data), end(data), c);

        return p != end(data);
    }
};



//FindChar fc("aieouAIEOU");





int main()
{
//    vector<list<int>> h(10);
//    h[0].push_back(10);
///   h[0].push_back(20);

    //vector<int> v;
    vector<string> v;

    ifstream f("vector4.cpp");

    string s;

    while( getline( f, s) )
        v.push_back(s);

    //---------------------





    //reverse( begin(v), end(v));
    for ( int i =0; i < v.size(); i++)
    {
        //reverse( begin(v[i]), end(v[i]));

        //replace(begin(v[i]), end(v[i]), 'i', ' ');

        // 모든 모음을 공백 치환
        //replace_if(begin(v[i]), end(v[i]),
        //              [](char c) { return c == 'a';},' ');

        FindChar fc("aieouAIEOU");

        replace_if(begin(v[i]), end(v[i]), fc, ' ');


    }






    //-----------------------
    for( auto str : v)
        cout << str << endl;


        //f >> s;
}












//
