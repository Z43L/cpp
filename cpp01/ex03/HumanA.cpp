#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
    HumanA::name = name;
}
HumanA::~HumanA() {}



void HumanA::attack()
{
    std::string name = HumanA::getName();
    Weapon weapon = HumanA::getWeapon();

    std::string text = " attacks with their ";
    std::cout << name << text << weapon.getType() << std::endl;
}

Weapon HumanA::getWeapon()
{
    return HumanA::weapon;
}

std::string HumanA::getName()
{
    return HumanA::name;
}

