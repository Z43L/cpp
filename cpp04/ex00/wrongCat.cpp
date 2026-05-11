#include "wrongCat.hpp"

wCat::wCat() {
  this->type = "Cat";
  std::cout << "wcat constructor" << std::endl;
}
wCat::wCat(const wCat &other) : WrongAnimal(other) {
  *this = other;
  std::cout << "wcat constructor copy" << std::endl;
}
wCat wCat::operator=(const wCat &other) {
  std::cout << "wcat constructor operator" << std::endl;

  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

wCat::~wCat() { std::cout << "wcat desconstructor" << std::endl; }
void wCat::makeSound() const { std::cout << "cat sound miau" << std::endl; }

std::string wCat::getType() const { return this->type; }
