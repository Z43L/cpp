#ifndef CAT_HPP
#define CAT_HPP
#pragma once

#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &other);
  Cat operator=(const Cat &other);
  ~Cat();
  void makeSound() const;
  std::string getType() const;
};

#endif
