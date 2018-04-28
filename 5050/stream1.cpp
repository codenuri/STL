#include <iostream> // 표준 입출력
#include <fstream>  // 파일 입출력
#include <sstream>  // string 입출력
#include <string>
using namespace std;

int main()
{
    string s;
//    cin >> s;   // 표준 입력에서 한단어

//    ifstream fin("stream.cpp");
//    fin >> s;   // 파일 에서 한단어.

    istringstream iss("I am a boy");

    while( iss >> s) // I
        cout << s << endl; // I

}
