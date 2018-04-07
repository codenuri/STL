#include <iostream>
#include <memory>
using namespace std;

struct FOO
{
    int n1;
    int n2;

    ~FOO() { cout << "~FOO" << endl;}
};

int main()
{
    shared_ptr<int> p4;
    {
        shared_ptr<FOO> p1 = make_shared<FOO>();
        shared_ptr<int> p2(p1, &p1->n1);
        shared_ptr<int> p3(p1, &p1->n2);

        p4 = p3;

        cout << p2.get() << endl;

        cout << p1.use_count() << endl;
    }
    cout <<"----" << endl;

}
