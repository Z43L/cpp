#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Span.hpp"

int main()
{
    std::cout << "===== BASIC TEST =====" << std::endl;

    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: "
                  << sp.shortestSpan()
                  << std::endl;

        std::cout << "Longest span: "
                  << sp.longestSpan()
                  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }


    std::cout << "\n===== FULL SPAN TEST =====" << std::endl;

    try
    {
        Span sp(2);

        sp.addNumber(10);
        sp.addNumber(20);

        sp.addNumber(30);
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected error: "
                  << e.what()
                  << std::endl;
    }


    std::cout << "\n===== NOT ENOUGH NUMBERS TEST =====" << std::endl;

    try
    {
        Span sp(10);

        sp.addNumber(42);

        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected error: "
                  << e.what()
                  << std::endl;
    }


    std::cout << "\n===== RANGE TEST =====" << std::endl;

    try
    {
        Span sp(10);

        std::vector<int> numbers;

        numbers.push_back(6);
        numbers.push_back(3);
        numbers.push_back(17);
        numbers.push_back(9);
        numbers.push_back(11);

        sp.addRange(numbers.begin(), numbers.end());

        std::cout << "Shortest span: "
                  << sp.shortestSpan()
                  << std::endl;

        std::cout << "Longest span: "
                  << sp.longestSpan()
                  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: "
                  << e.what()
                  << std::endl;
    }


    std::cout << "\n===== 10,000 NUMBERS TEST =====" << std::endl;

    try
    {
        const unsigned int SIZE = 10000;

        Span sp(SIZE);

        for (unsigned int i = 0; i < SIZE; ++i)
            sp.addNumber(static_cast<int>(i));

        std::cout << "Shortest span: "
                  << sp.shortestSpan()
                  << std::endl;

        std::cout << "Longest span: "
                  << sp.longestSpan()
                  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: "
                  << e.what()
                  << std::endl;
    }


    std::cout << "\n===== 10,000 NUMBERS WITH RANGE =====" << std::endl;

    try
    {
        const unsigned int SIZE = 10000;

        Span sp(SIZE);

        std::vector<int> numbers;

        for (unsigned int i = 0; i < SIZE; ++i)
            numbers.push_back(static_cast<int>(i));

        sp.addRange(numbers.begin(), numbers.end());

        std::cout << "Shortest span: "
                  << sp.shortestSpan()
                  << std::endl;

        std::cout << "Longest span: "
                  << sp.longestSpan()
                  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: "
                  << e.what()
                  << std::endl;
    }

    return 0;
}
