#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <vector>
using namespace std;
using namespace std::placeholders;

class NotificationCenter
{
    using HANDLER = function<void(void*)>;

    map<string, vector<HANDLER>> notif_map;
public:
    void Register(string key, HANDLER h)
    {
        notif_map[key].push_back(h);
    }
    void Notify( string key, void* param)
    {
        vector<HANDLER>& v = notif_map[key];

        for( auto f : v)
            f(param);
    }
};

void f1(void* p) { cout << "f1" << endl;}
void f2(void* p, int a, int b) { cout << "f2" << endl;}

int main()
{
    NotificationCenter nc;
    nc.Register("CONNECT_WIFI", &f1);
    nc.Register("CONNECT_WIFI", bind(&f2, _1, 0, 0) );


    nc.Notify("CONNECT_WIFI", (void*)0);
}



















//
