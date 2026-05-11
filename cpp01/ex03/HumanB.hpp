#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB{
private:
    std::string name;
    Weapon weapon;

public:
    HumanB(std::string name);
    ~HumanB();
    
    std::string setName(std::string name);
    std::string getName();
    Weapon setWeapon(Weapon weapon2);
    Weapon getWeapon();
    
    void attack();
};



#endif