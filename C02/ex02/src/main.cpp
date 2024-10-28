#include "../incl/Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const multiply( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const divide( Fixed( 4.05f ) / Fixed( 2 ) );
    Fixed const substract( Fixed(5.05f) - Fixed(2) );
    Fixed const add( Fixed(5.05f) + Fixed(2) );


    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << multiply << std::endl;
    std::cout << divide << std::endl;
    std::cout << substract << std::endl;
    std::cout << add << std::endl;
    std::cout << Fixed::max( a, multiply ) << std::endl;
    std::cout << Fixed::min( substract, add) << std::endl;
    std::cout << Fixed::max( substract, add) << std::endl;;
    return 0;
}
