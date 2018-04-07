#include <algorithm>
using namespace std;

template<typename InputIt, typename T>
InputIt 
efind(InputIt first, InputIt last, T value)
{
	while (first != last && *first != value)
		++first;

	return first;
}

int main()
{
	int x[3] = { 1,2,3 };

	int* p = efind(x, x + 3, 2);

	//reverse();
	//sort()

}