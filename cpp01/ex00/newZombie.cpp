#include "Zombie.hpp"

Zombie* newZom(std::string name)
{
    Zombie* zombie = new Zombie(name);
    return zombie;
    delete zombie;
}