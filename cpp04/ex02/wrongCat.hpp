#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#pragma once

#include "wrongAnimal.hpp"

class wCat : public wrongAnimal {
public:
  wCat();
  wCat(const wCat &other);
  wCat operator=(const wCat &other);
  ~wCat();
  void makeSound() const;
  std::string getType() const;
};

#endif
