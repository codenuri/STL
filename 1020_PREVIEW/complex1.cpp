#include <iostream>
#include <complex>
using std::complex;
using std::sin;
using std::cout;
using std::endl;

using namespace std::literals;
//using namespace std;

int main()
{
	complex<double> c1(1, 0);

	cout << c1 << endl;
	cout << c1.real() << endl;
	cout << c1.imag() << endl;

	complex<double> c2 = sin(c1);
	cout << c2 << endl;

//	complex<int> c3(1, 0);
//	complex<int> c4 = sin(c3);

	complex<float> c5(3); // 3, 0
	complex<float> c6(3, 1); // 3, 1
	complex<float> c7(3if); // 0, 3

	cout << c5 << endl;
	cout << c7 << endl;

}
