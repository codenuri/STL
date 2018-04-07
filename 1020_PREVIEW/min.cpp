#include <iostream>
#include <algorithm>
using namespace std;

struct Point
{
	int x, y;
};

int main()
{
	Point p1, p2;

	min(p1, p2); // <  ,    >

	int n1 = min(1, 2); 
	//int n2 = min(1, 2, 3, 4,5); // error

	int n2 = min( { 1, 2, 3, 4, 5 } ); // ok.

}