#include "Dog.hpp"

Dog::Dog() {
  this->type = "Dog";
  std::cout << "dog constructor" << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other) {
  *this = other;
  std::cout << "dog constructor copy" << std::endl;
}
Dog Dog::operator=(const Dog &other) {
  std::cout << "dog constructor operator" << std::endl;

  if (this->type != other.type)
    this->type = other.type;
  return *this;
}
Dog::~Dog() { std::cout << "dog desconstructor" << std::endl; }
void Dog::makeSound() const { std::cout << "dog make sound guau" << std::endl; }
std::string Dog::getType() const { return this->type; }
