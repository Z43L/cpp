#include "Zombie.hpp"


int main(void)
{
    Zombie *zombieHeap = newZom("Foo");
    zombieHeap->anouncen();
    zombieHeap->anouncen();
    zombieHeap->anouncen();
    
    std::cout << "\nComprobando en el STACK\n";
    randomChump("FooStack");
    randomChump("Fooo2Stack");
    delete zombieHeap;
    return 0;
    
}
