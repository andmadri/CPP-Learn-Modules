#include "../incl/Fixed.hpp"

Fixed::Fixed(): fpnum_value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
    this->fpnum_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other){
        this->fpnum_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return this->fpnum_value;
    //returns the raw value of fixed point value
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->fpnum_value = raw;
    //sets the raw value of the fixed-point number
}
