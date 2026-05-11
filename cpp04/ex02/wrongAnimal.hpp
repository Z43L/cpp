#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#pragma once
#include <iostream>
#include <sstream>
#include <string>
class wrongAnimal {
protected:
  std::string type;

public:
  wrongAnimal();
  wrongAnimal(const wrongAnimal &other);
  wrongAnimal operator=(const wrongAnimal &other);
  virtual ~wrongAnimal();
  virtual void makeSound() const = 0;
  std::string getType(void) const;
  virtual std::string setThinks(std::string think, int i) const;
};

#endif
