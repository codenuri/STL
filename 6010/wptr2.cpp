#include <iostream>
#include <memory>
#include "car.h"
using namespace std;

int main()
{
    //shared_ptr<Car> wp; // use count 증가

    weak_ptr<Car> wp; // use count 증가 안함.


    shared_ptr<Car> sp( new Car );
    wp = sp;
    cout << sp.use_count() << endl; // 1

    if ( wp.expired() )
        cout << "destroy" << endl;
    else
    {
        cout << "not destroy" << endl;

        // weak_ptr을 사용해서는 대상객체에 접근할수 없다.
        //wp->Go(); // error.

        // weak_ptr을 가지고 다시 shared_ptr을 만들어야 한다.

        shared_ptr<Car> sp2 = wp.lock();

        if ( sp2 )
            sp2->Go();
    }
}









//
