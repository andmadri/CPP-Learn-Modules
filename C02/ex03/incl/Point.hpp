#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "../incl/Fixed.hpp"

#define X 1
#define Y 2

class Point{

public:

    Point();
    Point(const float num1, const float num2);
    Point(const Point& other);
    Point& operator=(const Point& other) = delete;
    ~Point() = default;
    int getPoint(const int i) const;


private:
    const Fixed x;
    const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif