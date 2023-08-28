#include <iostream>
#include "Point.h"

int main()
{
    Point point1, point2;

    point1.read();
    point2.read();

    point1.print();
    point2.print();

    std::cout << point1.distanceToCenter() << std::endl;

    std::cout << point1.distanceBetweenTwoDots(point2) << std::endl;

    return 0;
}