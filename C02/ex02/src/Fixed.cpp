#include "../incl/Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
    os << other.toFloat();
    return os;
}

Fixed::Fixed(): fpnum_value(0)
{}

Fixed::Fixed(const int integer)
{
    this->fpnum_value = integer * (1 << frac_bits);
}

Fixed::Fixed(const float floating_point)
{
    this->fpnum_value = roundf(floating_point * (1 << frac_bits));
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other){
        this->fpnum_value = other.fpnum_value;
    }
    return *this;
}

float Fixed::toFloat(void) const
{
    return ((float)this->fpnum_value / (float)(1 << frac_bits));
}

int Fixed::toInt(void) const
{
    return (this->fpnum_value / (1 << frac_bits));
}

Fixed Fixed::operator+(const Fixed& other)
{
    Fixed result;
    int   sum = this->fpnum_value + other.fpnum_value;
    result.fpnum_value = sum;
    return result;
}

Fixed Fixed::operator-(const Fixed& other)
{
    Fixed result;
    int   substract = this->fpnum_value - other.fpnum_value;
    result.fpnum_value = substract;
    return result;
}

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed result;
    result.fpnum_value = this->fpnum_value * other.toFloat();
    return result;
}

Fixed Fixed::operator/(const Fixed& other)
{
    Fixed result;
    result.fpnum_value = this->fpnum_value / other.toFloat();
    return result;
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->fpnum_value < other.fpnum_value);
}

bool Fixed::operator>(const Fixed& other) const
{
    return other < *this;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return !(*this < other);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return !(*this > other);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->fpnum_value == other.fpnum_value);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return !(*this == other);
}

Fixed& Fixed::operator++()
{
    this->fpnum_value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed copy = *this;
    operator++();
    return copy;
}

Fixed& Fixed::operator--()
{
    this->fpnum_value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed copy = *this;
    operator++();
    return copy;
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2){
    return (num1 < num2) ? num1 : num2;
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2){
    return (num1 < num2) ? num1 : num2;
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2){
    return (num1 > num2) ? num1 : num2;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2){
    return (num1 > num2) ? num1 : num2;
}
