// car.h
#include <iostream>

class Car
{
    int color;
    int speed;
public:
    Car(int c = 0, int s = 0) : color(c), speed(s) {}

    ~Car()    { std::cout << "~Car()" << std::endl;}

    void Go() { std::cout << "Car go" << std::endl;}
};
