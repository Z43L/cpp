#include "Brain.hpp"

Brain::Brain() { std::cout << "constructor brain called " << std::endl; }
Brain::Brain(const Brain &other) {
  std::cout << "brain constructor copy" << std::endl;

  for (int i = 0; i <= 100; i++) {
    this->thinks[i] = other.thinks[i];
  }
}
Brain Brain::operator=(const Brain &other) {
  std::cout << "brain constructor operator" << std::endl;

  if (this != &other) {
    for (int i = 0; i <= 100; i++) {
      this->thinks[i] = other.thinks[i];
    }
  }
  return *this;
}
Brain::~Brain() { std::cout << "brain desconstructor" << std::endl; }
void Brain::setThinks(std::string think, int i) {
  std::string result = think;

  this->thinks[i] = result;
}
