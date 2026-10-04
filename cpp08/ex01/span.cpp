#include "Span.hpp"

Span::Span(unsigned int N)
    : _maxSize(N)
{
}

Span::Span(const Span& other)
    : _maxSize(other._maxSize),
      _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }

    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");

    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int> sorted = _numbers;

    std::sort(sorted.begin(), sorted.end());

    unsigned int shortest = static_cast<unsigned int>(
        sorted[1] - sorted[0]
    );

    for (std::vector<int>::size_type i = 1;
         i < sorted.size();
         ++i)
    {
        unsigned int span = static_cast<unsigned int>(
            sorted[i] - sorted[i - 1]
        );

        if (span < shortest)
            shortest = span;
    }

    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(max - min);
}
