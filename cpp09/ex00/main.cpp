#include "Bitcoinexchange.hpp"
#include <iostream>
#include <exception>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: usage: ./btc input.txt" << std::endl;
        return 1;
    }
    try
    {
        Bitcoinexchange btc;
        btc.execute(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
