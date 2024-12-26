#include "../incl/Span.hpp"
#include <limits>

Span::Span(): m_size(0), m_index(0) {}

Span::Span(unsigned int N): m_size(N), m_index(0) {}

Span::Span(const Span& other): m_size(other.m_size), m_index(0){
    *this = other;
}

Span& Span::operator=(const Span& other){
    if (this != &other){
        this->m_span = other.m_span;
        this->m_size = other.m_size;
        this->m_index = other.m_index;
    }
    return *this;
}

void Span::addNumber(unsigned int num){
    if (m_span.size() >= m_size) {
        throw std::out_of_range("Span is full");
    }
    m_span.insert(num);
}

void Span::addManyNumbers(){
    std::srand(time(0));
    for (std::set<unsigned int>::iterator it = m_span.begin(); it != m_span.end(); ++it) {
        addNumber(rand());
    }
}

unsigned int Span::shortestSpan() const{
    unsigned int shortest = 0;
    if (m_span.size() < 2) {
        throw std::logic_error("Span is not big enough");
    }
    std::set<unsigned int>::iterator it = m_span.begin();
    while (it != m_span.end())
    {
        ++it;
        if (*it - *std::prev(it) < shortest || shortest == 0) {
            shortest = *it - *std::prev(it);
        }
    }
    return shortest;
}

unsigned int Span::longestSpan() const{
    if (m_span.size() < 2) {
        throw std::logic_error("Span is not big enough");
    }
    return *m_span.rbegin() - *m_span.begin();
}
