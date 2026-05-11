#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


ScavTrap::ScavTrap( void )
	: ClapTrap() {
		std::cout  << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name) {
		this->hp = 100;
		this->ep = 50;
		this->dp = 20;
		std::cout  << "Scavtrap whit arg constructor for " << this->name  << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) 
	: ClapTrap(){
	std::cout  << "Scavtrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src) {
	std::cout  << "Scavtrap copy assignment operator" << std::endl;
	if (this == &src)
		return (*this);
	this->name = src.name;
	return (*this);
}

ScavTrap::~ScavTrap( void ) {
	std::cout  << "ScavTrap deconstructor for " << this->name  << std::endl;
}

void	ScavTrap::attack (const std::string &target) {
	if (this->hp <= 0) {
		std::cout << "ScavTrap " << this->name << " dead" << std::endl;
		return ;
	}
	if (this->ep < 1) {
		std::cout << "ScavTrap " << this->name << "cannot attack; insufficient energy!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->dp << " points of damage!" << std::endl;
	this->ep -= 1;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " <<  this->name << " is in Gate keeper mode!" << std::endl;
}