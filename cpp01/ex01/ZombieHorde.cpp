#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{

    Zombie *zombieHordes = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombieHordes[i].setName(name);
        
    }

    return zombieHordes;
}
