#include "../incl/Span.hpp"

int main()
{
    Span sp(5);

    std::cout << "-----Test Normal Output-----" << std::endl;
    try {
        sp.addNumber(9);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(11);

        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "longest: " << sp.longestSpan() << std::endl;

    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Span sp1(0);
    std::cout << "-----Test Empty Span-----" << std::endl;
    try {
        std::cout << sp1.shortestSpan() << std::endl;
        std::cout << sp1.longestSpan() << std::endl;

    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Span sp2(3);
    std::cout << "-----Test Adding Too Many Values Output-----" << std::endl;
    try {
        sp2.addNumber(9);
        sp2.addNumber(6);
        sp2.addNumber(3);
        sp2.addNumber(17);
        sp2.addNumber(11);
        sp2.addNumber(11);
        sp2.addNumber(11);
        sp2.addNumber(11);
        sp2.addNumber(11);

        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;

    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Span sp3(15);
    std::cout << "-----Test Add Many Numbers-----" << std::endl;
    try {
        std::vector<unsigned int> vc;
        for (size_t i = 0; i < 15; ++i) {
            vc.push_back(i);
        }
        sp3.addManyNumbers(vc.begin(), vc.end());
        std::cout << sp3.shortestSpan() << std::endl;
        std::cout << sp3.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Span sp4(15);
    std::cout << "-----Test Add Many Numbers Into A Small Span-----" << std::endl;
    try {
        std::vector<unsigned int> vc;
        for (size_t i = 0; i < 100; ++i) {
            vc.push_back(i);
        }
        sp4.addManyNumbers(vc.begin(), vc.end());
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
