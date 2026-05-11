#include "Cat.hpp"
#include "Brain.hpp"
Cat::Cat() : Animal() {
  this->type = "Cat";
  this->brain = new Brain();
  std::cout << "cat constructor" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other) {
  *this = other;
  this->brain = new Brain(*other.brain);
  std::cout << "cat constructor copy" << std::endl;
}
Cat Cat::operator=(const Cat &other) {
  std::cout << "cat constructor operator" << std::endl;
  if (this != &other) {
    this->type = other.type;
    delete this->brain;
    this->brain = new Brain(*other.brain);
  }
  return *this;
}

Cat::~Cat() {
  delete this->brain;
  std::cout << "cat desconstructor" << std::endl;
}
void Cat::makeSound() const { std::cout << "cat sound miau" << std::endl; }

std::string Cat::getType() const { return this->type; }
std::string Cat::setThinks(std::string think, int i) const {
  std::stringstream toint;
  toint << i;
  std::string result = think + " " + toint.str();
  std::cout << result << std::endl;
  return result;
}
