#include <iostream>
#include <stack>
#include <list>

#include "MutantStack.hpp"

int main()
{
    std::cout << "===== BASIC TEST =====" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: "
              << mstack.top()
              << std::endl;

    mstack.pop();

    std::cout << "Size: "
              << mstack.size()
              << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\n===== ITERATION =====" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }


    std::cout << "\n===== REVERSE TEST =====" << std::endl;

    it = mstack.end();

    while (it != mstack.begin())
    {
        --it;
        std::cout << *it << std::endl;
    }


    std::cout << "\n===== COPY TEST =====" << std::endl;

    MutantStack<int> copy(mstack);

    MutantStack<int>::iterator copyIt = copy.begin();
    MutantStack<int>::iterator copyEnd = copy.end();

    while (copyIt != copyEnd)
    {
        std::cout << *copyIt << std::endl;
        ++copyIt;
    }


    std::cout << "\n===== LIST COMPARISON =====" << std::endl;

    std::list<int> list;

    list.push_back(5);
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator listIt = list.begin();
    std::list<int>::iterator listEnd = list.end();

    while (listIt != listEnd)
    {
        std::cout << *listIt << std::endl;
        ++listIt;
    }


    std::cout << "\n===== EMPTY TEST =====" << std::endl;

    MutantStack<int> empty;

    std::cout << "Empty: "
              << (empty.empty() ? "yes" : "no")
              << std::endl;

    empty.push(42);

    std::cout << "Empty after push: "
              << (empty.empty() ? "yes" : "no")
              << std::endl;

    return 0;
}
