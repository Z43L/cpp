#include "FragTrap.hpp"


FragTrap::FragTrap( void )
	: ClapTrap() {
		std::cout  <<"FragTrap default constructor for " << this->name  << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name) {
		this->hp = 100;
		this->ep = 100;
		this->dp = 30;
		std::cout  <<"FragTrap with arg constructor for " << this->name  << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) 
	: ClapTrap() {
	std::cout  <<"FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
	std::cout  <<"FragTrap copy constructor operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->dp = src.dp;

	return (*this);
}

FragTrap::~FragTrap( void ) {
		std::cout  <<"FragTrap deconstructor for " << this->name  << std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if (this->hp <= 0) {
		std::cout << "FragTrap " << this->name << " dead" << std::endl;
		return ;
	}
	if (this->ep < 1) {
		std::cout << "FragTrap " << this->name << "cannot attack; insufficient energy!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->dp << " points of damage!" << std::endl;
	this->ep -= 1;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "High five bro" << std::endl;
}