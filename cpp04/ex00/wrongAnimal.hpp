#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#pragma once
#include <iostream>
#include <sstream>
#include <string>
class WrongAnimal {
protected:
  std::string type;

public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal operator=(const WrongAnimal &other);
  virtual ~WrongAnimal();
  void makeSound() const;
  std::string getType(void) const;
  std::string setThinks(std::string think, int i) const;
};

#endif
