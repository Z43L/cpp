#include "Zombie.hpp"

int main(void)
{
    Zombie	*horde = zombieHorde(5, "Paco");
	
	int i = 0;
	while (i < 5)
		horde[i++].anouncen();
	delete[](horde);
	return (0);
}
