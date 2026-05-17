#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

class Intern {

private:
  static AForm *createRobotomy(std::string target);
  static AForm *createPresidential(std::string target);
  static AForm *createShrubbery(std::string target);

public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *makeForm(std::string name, std::string target);
};

#endif
