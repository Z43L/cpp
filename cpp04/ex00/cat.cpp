#include "Cat.hpp"

Cat::Cat() {
  this->type = "Cat";
  std::cout << "cat constructor" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other) {
  *this = other;
  std::cout << "cat constructor copy" << std::endl;
}
Cat Cat::operator=(const Cat &other) {
  std::cout << "cat constructor operator" << std::endl;
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

Cat::~Cat() { std::cout << "cat desconstructor" << std::endl; }
void Cat::makeSound() const { std::cout << "cat sound miau" << std::endl; }

std::string Cat::getType() const { return this->type; }
