#include <iostream>
#include <string>

int main(void)
{
    std::string hi = "HI THIS IS A BRAIN";
    std::string *stringPTR = &hi;
    std::string &stringREF = hi;
    std::cout << "The value of the string variable ->" << hi << std::endl;
    std::cout << "The value pointed to by stringPTR ->" << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF ->" << stringREF << std::endl;
    std::cout << "The address of the string variable ->" << &hi << std::endl;
    std::cout << "The address held by stringPTR ->" << &stringPTR << std::endl;
    std::cout << "The address held by stringREF ->" << &stringREF << std::endl;
    
    return 0;
}