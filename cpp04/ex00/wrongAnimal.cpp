#include "wrongAnimal.hpp"

WrongAnimal::WrongAnimal() { std::cout << "default constructor called\n"; }
WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "WrongAnimal copy constructor called\n";
  *this = other;
}

WrongAnimal WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << " WrongAnimal constructor operator called\n";
  if (this->type != other.type) {
    this->type = other.type;
  }
  return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called\n"; }

std::string WrongAnimal::getType(void) const { return this->type; }

void WrongAnimal::makeSound() const {
  std::cout << "unAnimal sound" << std::endl;
}
