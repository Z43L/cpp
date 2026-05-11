#ifndef __ZOMBIE_HPP__
 #define __ZOMBIE_HPP__

#include  <iostream>
#include  <string>
#include  <cctype>

class Zombie{
private:
    std::string _name;
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    std::string get_name(std::string name);
    void anouncen(void);
    void setName(std::string name);

};
Zombie* newZom(std::string name);
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );
void zombieHordeDelete(int N);
#endif 