#pragma once

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string	name;
		int	hp;
		int ep;
		int	dp;
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		~ClapTrap( void );
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &src);
		void attack(const std::string& target);
		void takeDamage(unsigned int value);
		void beRepaired(unsigned int value);
		void setDp(unsigned int value);
		int	getDp( void );
		int getHp( void );
};
