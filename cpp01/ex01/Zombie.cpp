#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "A nameless zombie has been created\n";
}
Zombie::Zombie(std::string name): _name(name)
{
    std::cout << name << " has ben create\n";
}
Zombie::~Zombie(){
    std::cout << this->_name <<"zombie died\n";
}

void Zombie::anouncen()
{
    std::cout << this->_name << " Brainzzzzzzz\n";
}
void Zombie::setName(std::string name)
{
    this->_name = name;
}