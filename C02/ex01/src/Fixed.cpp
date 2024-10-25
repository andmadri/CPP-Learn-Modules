#include "../incl/Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
    os << other.toFloat();
    return os;
}

Fixed::Fixed(): fpnum_value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int integer)
{
     std::cout << "Int constructor called\n";
    this->fpnum_value = integer * (1 << frac_bits);
}

Fixed::Fixed(const float floating_point)
{
     std::cout << "Float constructor called\n";
    this->fpnum_value = round(floating_point * (1 << frac_bits));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other){
        this->fpnum_value = other.fpnum_value;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

float Fixed::toFloat(void) const
{
    return ((float)this->fpnum_value / (float)(1 << frac_bits));
}

int Fixed::toInt(void) const
{
    return (this->fpnum_value / (1 << frac_bits));
}
