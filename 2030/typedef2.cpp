#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	string s = "hello";
	string::size_type pos2;

	cout << typeid(pos2).name() << endl;

	int pos = s.find('x');


	if ( pos == string::npos)
		cout << "fail" << endl;

	cout << pos << endl;

}


atom - text - editor::shadow.keyword.other.documentation
{
color: red;
}