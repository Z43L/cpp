#include "ScavTrap.hpp"

int main() {

	ScavTrap	c1("pepe");
	ScavTrap	c2("luis");
	ScavTrap	c3 = c1;

	c1.attack("luis");
	c2.attack("pepe");
	c3.attack("luis");
	c1.guardGate();
	c2.guardGate();
	c3.guardGate();
}