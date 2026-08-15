#include "iter.hpp"
#include <iostream>
template<typename T>void print(T data)
{
    std::cout << data<< std::endl;
}

template<typename T>void increment(T& data)
{
    ++data;
}


int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};

    std::cout << "Original:" << std::endl;
    iter(numbers, 5, print<int>);

    iter(numbers, 5, increment<int>);

    std::cout << "\nAfter increment:" << std::endl;
    iter(numbers, 5, print<int>);

    std::string words[] = {
        "hello",
        "42",
        "templates"
    };

    std::cout << "\nStrings:" << std::endl;
    iter(words, 3, print<std::string>);

    return 0;
}
