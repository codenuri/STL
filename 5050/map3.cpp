#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
using namespace std;

int main()
{
    map<string, list<int>> index;
    ifstream f("test.txt");
    int lineno = 0;
    string s;

    while( getline( f, s ) ) // 파일에서 한줄 읽기
    {
        lineno++;
        istringstream iss(s);
        string word;
        while( iss >> word )
        {
            index[word].push_back(lineno);
        }
    }
    //---------------------------
    auto p = begin(index);

    while( p != end(index ))
    {
        cout << p->first << " : "; // 단어 출력
        for ( auto n : p->second )
            cout << n << ", ";

        cout << endl;
        ++p;
    }


}








//
