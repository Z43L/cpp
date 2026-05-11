#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    Weapon::setType(type);
}
Weapon::~Weapon(){}

std::string Weapon::setType(std::string type)
{
    Weapon::type = type;
    return Weapon::type;
}
std::string Weapon::getType()
{
    return Weapon::type;
}