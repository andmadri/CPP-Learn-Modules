#include "../incl/Span.hpp"

int main()
{
    Span sp = Span(10);

    try {
        // sp.addNumber(6);
        sp.addManyNumbers();
        // sp.addNumber(3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11);
        // sp.addNumber(1);
        

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

    } catch(const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    } catch(const std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
