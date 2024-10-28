#include "../incl/Point.hpp"

static int absolute(int num)
{
    if(num < 0)
        return -num;
    return num;
}

static int triangleComponent(const int x, const int y1, const int y2)
{
    int result = x * (y1 - y2);
    return result;
}

static int areaTriangle(Point const num1, Point const num2, Point const num3)
{
    int tc1 = triangleComponent(num1.getPoint(X), num2.getPoint(Y), num3.getPoint(Y));
    int tc2 = triangleComponent(num2.getPoint(X), num3.getPoint(Y), num1.getPoint(Y));
    int tc3 = triangleComponent(num3.getPoint(X), num1.getPoint(Y), num2.getPoint(Y));
    int area = absolute(tc1 + tc2 + tc3);
    
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    int ABC = areaTriangle(a, b, c);
    int PAC = areaTriangle(point, a, c);
    int PBA = areaTriangle(point, b, a);
    int PCB = areaTriangle(point, c, b);

    if (ABC == PAC + PBA + PCB)
        return true;
    return false;
}
