#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
class Brain {
protected:
  std::string thinks[100];

public:
  Brain();
  Brain(const Brain &other);
  Brain operator=(const Brain &other);
  ~Brain();
  void setThinks(std::string think, int i);
};

#endif
