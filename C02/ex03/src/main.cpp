#include "../incl/Point.hpp"

int main()
{
    Point A(0, 0);
    Point B(10, 30);
    Point C(20, 0);
    Point Point1(30, 1500);
    Point Point2(5.5f, 6.2f);

    if (bsp(A, B, C, Point1)){
        std::cout << "Point1: Iniside\n";
    }
    else
        std::cout << "Point1: Outside\n";
    if (bsp(A, B, C, Point2)){
        std::cout << "Point2: Iniside\n";
    }
    else
        std::cout << "Point2: Outside\n";
    return 0;
}