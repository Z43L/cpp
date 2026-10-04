#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(42);
    numbers.push_back(50);
    numbers.push_back(42);

    try
    {
        std::vector<int>::iterator it = easyfind(numbers, 42);

        std::cout << "Vector: found "
                  << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    try
    {
        easyfind(numbers, 100);
    }
    catch (const std::exception& e)
    {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    std::list<int> values;

    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(42);

    try
    {
        std::list<int>::iterator it = easyfind(values, 42);

        std::cout << "List: found "
                  << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "List: " << e.what() << std::endl;
    }

    std::deque<int> queue;

    queue.push_back(100);
    queue.push_back(200);
    queue.push_back(300);

    try
    {
        std::deque<int>::iterator it = easyfind(queue, 200);

        std::cout << "Deque: found "
                  << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Deque: " << e.what() << std::endl;
    }

    return 0;
}
