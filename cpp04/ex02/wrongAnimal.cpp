#include "wrongAnimal.hpp"

wrongAnimal::wrongAnimal() {
  std::cout << "wrongAnimal default constructor called\n";
}
wrongAnimal::wrongAnimal(const wrongAnimal &other) {
  std::cout << "wrongAnimal copy constructor called\n";
  *this = other;
}

wrongAnimal wrongAnimal::operator=(const wrongAnimal &other) {
  std::cout << "wrongAnimal constructor operator called\n";
  if (this->type != other.type) {
    this->type = other.type;
  }
  return *this;
}

wrongAnimal::~wrongAnimal() { std::cout << "wrongAnimal destructor called\n"; }

std::string wrongAnimal::getType(void) const { return this->type; }

void wrongAnimal::makeSound() const {
  std::cout << "unAnimal sound" << std::endl;
}
