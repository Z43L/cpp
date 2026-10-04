#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span
{
private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end)
    {
        unsigned int distance = std::distance(begin, end);

        if (_numbers.size() + distance > _maxSize)
            throw std::runtime_error("Span is full");

        _numbers.insert(_numbers.end(), begin, end);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};

#endif
