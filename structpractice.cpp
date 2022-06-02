#include <stdio.h>
#include <iostream>

struct Point
{
    int y;
    int x;
};

struct Circle
{
    struct Point point;
    int radius;
};

int main()
{
    struct Point point = {3, 5};
    struct Circle circle = {point, 20};
    // cout only prints primary data types
    std::cout << circle.radius << std::endl;

    struct Circle *c = new struct Circle({point, 20});
    std::cout << c->radius;
    return 0;
}