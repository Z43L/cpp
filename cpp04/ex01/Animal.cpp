#include "Animal.hpp"

Animal::Animal() { std::cout << "default constructor called\n"; }
Animal::Animal(const Animal &other) {
  std::cout << "copy constructor called\n";
  *this = other;
}

Animal Animal::operator=(const Animal &other) {
  std::cout << "constructor operator called\n";
  if (this->type != other.type) {
    this->type = other.type;
  }
  return *this;
}

Animal::~Animal() { std::cout << "destructor called\n"; }

std::string Animal::getType(void) const { return this->type; }

void Animal::makeSound() const { std::cout << "unAnimal sound" << std::endl; }
std::string Animal::setThinks(std::string think, int i) const {
  std::stringstream toint;
  toint << i;
  std::string result = think + " " + toint.str();
  std::cout << result << std::endl;
  return result;
}
