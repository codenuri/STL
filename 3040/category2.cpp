#include <forward_list>
#include <list>
using namespace std;

int main()
{
	//forward_list<int> s1 = { 1,2,3 };

	list<int> s1 = { 1,2,3 };

	auto p = begin(s1);

	++p;
	--p; // ??

}