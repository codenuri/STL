#include <codecvt>   // for codecvt_utf8
#include <iostream>  // cor cout
#include <locale>    // for wstring_convert
#include <string>    // for string, u16string

using namespace std;

// Compiles on LLVM 3.3 with:
// clang++ -std=c++11 -stdlib=libc++ xxx.cpp

int main() {
	u16string s = u"alpha";
	wstring_convert<codecvt_utf8<char16_t>, char16_t> cv;
	cout << cv.to_bytes(s) << endl;
	return 0;
}