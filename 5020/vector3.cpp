#include <iostream>
#include <vector>
using namespace std;

void print( int* arr, int sz)
{
    for( int i = 0; i < sz; i++ )
        cout << arr[i] << endl;
}

int main()
{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
//    print(arr, 10);

    vector<int> v = { 1,2,3,4,5,6,7,8,9,10};

    //print(v, v.size()); // error

    print(&v[0],    v.size());
    print(v.data(), v.size());


}
