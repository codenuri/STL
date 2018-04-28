#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
//    cout << "hello"; // 화면 출력

//    ofstream f("a.txt");
//    f << "hello";   // 파일 출력

    ostringstream oss;
    oss << "hello"; // oss의 버퍼에 출력

    string s = oss.str();
    cout << s << endl; // "hello"

    int n = 10;
    // n의 값을 문자열로
    char buf[10];
    sprintf(buf, "n = %d", n);

    ostringstream oss2;

    oss2 << "n = " << n;

    string s3 = oss2.str();

    cout << s3 << endl; // n = 10

}









//
