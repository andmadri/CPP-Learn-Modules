#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <set>
#include <iterator>

class Span{
private:
    std::set<unsigned int> m_span;
    unsigned int m_size;
    int m_index;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span() = default;

    void addNumber(unsigned int num);
    void addManyNumbers();
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};

#endif