#include "FragTrap.hpp"


int main() {
	FragTrap	derechas("derechas");
	FragTrap	izquierdas("izquierdas");
	FragTrap	copia = derechas;

	derechas.attack("izquierdas");
	izquierdas.attack("derechas");
	copia.attack("izquierdas");
	derechas.highFivesGuys();
	izquierdas.highFivesGuys();
	copia.highFivesGuys();
}