#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(Weapon(""))
{
    HumanB::setName(name);
}

HumanB::~HumanB() {}

void HumanB::attack()
{
    std::string name = HumanB::getName();
    Weapon weapon = HumanB::getWeapon();

    std::string text = " attacks with their ";
    std::cout << name << text << weapon.getType() << std::endl;
}

Weapon HumanB::setWeapon(Weapon weapon2)
{
    HumanB::weapon = weapon2;
    return HumanB::weapon;
}

Weapon HumanB::getWeapon()
{
    return HumanB::weapon;
}

std::string HumanB::setName(std::string name)
{
    HumanB::name = name;
    return HumanB::name;
}

std::string HumanB::getName()
{
    return HumanB::name;
}