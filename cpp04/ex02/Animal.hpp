#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#pragma once
#include <iostream>
#include <sstream>
#include <string>
class Animal {
protected:
  std::string type;

public:
  Animal();
  Animal(const Animal &other);
  Animal operator=(const Animal &other);
  virtual ~Animal();
  virtual void makeSound() const;
  std::string getType(void) const;
  virtual std::string setThinks(std::string think, int i) const;
};

#endif
