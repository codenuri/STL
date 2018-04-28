#include <iostream>
#include <list>   
#include <vector>
using namespace std;

int main()
{
	list<int> s = { 1,2,3,4,5 };
	//vector<int> s = { 1,2,3,4,5 };

	//int s[5] = { 1,2,3,4,5 };
	
	//list<int>::iterator p = s.begin();

	//auto p1 = s.begin(); // 진짜 배열은 error

	auto p1 = begin(s); // STL container 와 배열

	int n = size(s); //  s.size();
	cout << n << endl;

	auto p2 = end(s);
	*p2 = 10; // runtime error;
	


}



