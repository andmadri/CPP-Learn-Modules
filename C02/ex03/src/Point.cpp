#include "../incl/Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(const float num1, const float num2)
: x(num1), y(num2) {}

Point::Point(const Point& other)
: x(other.x), y(other.y)
{}

int Point::getPoint(const int i) const
{
    if (i == X){
        return x.getRawBits();
    }
    return y.getRawBits();
}
