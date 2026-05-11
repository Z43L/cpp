#include "Dog.hpp"

Dog::Dog() {
  this->type = "Dog";
  this->brain = new Brain();
  std::cout << "dog constructor" << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other) {
  *this = other;
  this->brain = new Brain(*other.brain);
  std::cout << "dog constructor copy" << std::endl;
}
Dog Dog::operator=(const Dog &other) {
  std::cout << "dog constructor operator" << std::endl;

  if (this->type != other.type) {
    this->type = other.type;
    delete this->brain;
    this->brain = new Brain(*other.brain);
  }
  return *this;
}
Dog::~Dog() {
  delete this->brain;
  std::cout << "dog desconstructor" << std::endl;
}
void Dog::makeSound() const { std::cout << "dog make sound guau" << std::endl; }
std::string Dog::getType() const { return this->type; }
std::string Dog::setThinks(std::string think, int i) const {
  std::stringstream toint;
  toint << i;
  std::string result = think + " " + toint.str();
  std::cout << result << std::endl;
  return result;
}
