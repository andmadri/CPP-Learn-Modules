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
    m_span.push_back(num);
}

void Span::addManyNumbers(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end){
    auto range_size = std::distance(begin, end);
    if (!range_size) {
        throw std::invalid_argument("The range of iterators is empty");
    }
    if (static_cast<unsigned long>(range_size) > this->m_size - m_span.capacity()) {
        throw std::out_of_range("The range of iterators is bigger than the size of the span");
    }
    std::copy(begin, end, std::back_inserter(m_span));
}

unsigned int Span::shortestSpan() {
    if (m_span.empty() || m_span.size() == 1) {
        throw std::invalid_argument("Span is empty or has only one number");
    }
    std::sort(m_span.begin(), m_span.end());
    unsigned int shortest = std::numeric_limits<unsigned int>::max();
    for (size_t i = 0; i < m_span.size() - 1; ++i) {
        if (m_span.at(i + 1) == m_span.at(i))
            continue;
        else if (shortest > m_span.at(i + 1) - m_span.at(i)) {
            shortest = m_span.at(i + 1) - m_span.at(i);
            i = 0;
        }
    }
    return shortest;
}

unsigned int Span::longestSpan() {

    if (m_span.empty() || m_span.size() == 1) {
        throw std::invalid_argument("Span is empty or has only one number");
    }
    auto result = std::minmax_element(m_span.begin(), m_span.end());
    return (*result.second - *result.first);
}
