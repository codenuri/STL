#include <iostream>
#include <ratio>
using namespace std;


/*
template<intmax_t _Nx, intmax_t _Dx = 1>
struct ratio
{
	static constexpr intmax_t num = _Nx;
	static constexpr intmax_t den = _Dx;

	typedef ratio<num, den> type;
};
*/

int main()
{
	ratio<2, 4> r1; // 2/4  => 1/2

	cout << sizeof(r1) << endl; // 1

	cout << r1.num << endl;
	cout << r1.den << endl;

	cout << ratio<2, 4>::num << endl;  // 1
	cout << ratio<2, 4>::den << endl;  // 2
}









/*
template<intmax_t _Nx, intmax_t _Dx = 1>
struct ratio
{
	static_assert(_Dx != 0, 			"zero denominator");
	static_assert(-INTMAX_MAX <= _Nx,	"numerator too negative");
	static_assert(-INTMAX_MAX <= _Dx,	"denominator too negative");

	static constexpr intmax_t num =
			_Sign_of<_Nx>::value * _Sign_of<_Dx>::value * _Abs<_Nx>::value / _Gcd<_Nx, _Dx>::value;

	static constexpr intmax_t den =
			_Abs<_Dx>::value / _Gcd<_Nx, _Dx>::value;

	typedef ratio<num, den> type;
};
*/









/*
typedef ratio<1, 1000000000000000000LL> atto;
typedef ratio<1, 1000000000000000LL> femto;
typedef ratio<1, 1000000000000LL> pico;
typedef ratio<1, 1000000000> nano;
typedef ratio<1, 1000000> micro;
typedef ratio<1, 1000> milli;
typedef ratio<1, 100> centi;
typedef ratio<1, 10> deci;
typedef ratio<10, 1> deca;
typedef ratio<100, 1> hecto;
typedef ratio<1000, 1> kilo;
typedef ratio<1000000, 1> mega;
typedef ratio<1000000000, 1> giga;
typedef ratio<1000000000000LL, 1> tera;
typedef ratio<1000000000000000LL, 1> peta;
typedef ratio<1000000000000000000LL, 1> exa;
*/
