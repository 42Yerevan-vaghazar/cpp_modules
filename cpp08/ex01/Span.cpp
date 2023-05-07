#include "Span.hpp"
#include <utility>

Span::Span() {
    m_maxSize = 0;
};
Span::Span(unsigned int N) {
    m_maxSize = N;
};

Span::Span(const Span &obj) {
    m_maxSize = obj.m_maxSize;
};

Span::~Span() {
    
};

Span &Span::operator=(const Span &obj) {
    m_maxSize = obj.m_maxSize;
    return (*this);
};

void Span::addNumber(unsigned int num) {
    if (m_elems.size() == m_maxSize) {
         throw std::runtime_error("too many integers");
    }
    m_elems.push_back(num);
};

unsigned int Span::shortestSpan() {
    if (m_elems.size() < 2) {
        throw std::runtime_error("too few integers");
    }
    std::pair<Vector::const_iterator , Vector::const_iterator>   pair;
    std::sort(m_elems.begin(), m_elems.end());
    unsigned int min = m_elems[1] - m_elems[0];
    for (size_t i = 1; i < m_elems.size(); i++) {
        if (m_elems[i + 1] - m_elems[i] < min)
            min = m_elems[i + 1] - m_elems[i];
    }
    return (min);
};

unsigned int Span::longestSpan() const {
    if (m_elems.size() < 2) {
        throw std::runtime_error("too few integers");
    }
    std::pair<Vector::const_iterator , Vector::const_iterator>   pair;
    pair = std::minmax_element(m_elems.begin(), m_elems.end());
    return (*pair.second - *pair.first);
};