#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main() {
  Animal *meta[10];
  for (int i = 0; i < 5; i++) {
    meta[i] = new Dog();
    std::cout << meta[i]->getType() << " ";
    meta[i]->makeSound();
    meta[i]->setThinks("hola", i);
  }
  for (int i = 5; i < 10; i++) {
    meta[i] = new Cat();
    std::cout << meta[i]->getType() << " ";
    meta[i]->makeSound();
  }
  for (int i = 0; i < 10; i++) {
    delete meta[i];
  }
  return 0;
}
