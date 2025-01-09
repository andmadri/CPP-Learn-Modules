#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iterator>

class Span{
private:
    std::vector<unsigned int> m_span;
    unsigned int m_size;
    int m_index;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span() = default;

    void addNumber(unsigned int num);
    void addManyNumbers(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
    unsigned int shortestSpan();
    unsigned int longestSpan();
};

#endif