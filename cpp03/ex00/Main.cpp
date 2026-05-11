#include "ClapTrap.hpp"

int main() {
	ClapTrap	derechas("derechas");
	ClapTrap	izquierdas("izquierdas");

	derechas.attack("izquierdas");
	izquierdas.takeDamage(derechas.getDp());
	izquierdas.beRepaired(derechas.getDp());

	izquierdas.setDp(3);
	izquierdas.attack("derechas");
	derechas.takeDamage(izquierdas.getDp());
	izquierdas.setDp(8);
	izquierdas.attack("derechas");
	derechas.takeDamage(izquierdas.getDp());

	return 0;
}