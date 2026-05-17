#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) {

  (void)other;
  return *this;
}

Intern::~Intern() {};

AForm *Intern::createRobotomy(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubbery(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
  std::string forms[3];

  forms[0] = "robotomy request";
  forms[1] = "presidential pardon";
  forms[2] = "shrubbery creation";

  AForm *(*functions[3])(std::string);

  functions[0] = &Intern::createRobotomy;
  functions[1] = &Intern::createPresidential;
  functions[2] = &Intern::createShrubbery;

  for (int i = 0; i < 3; i++) {

    if (forms[i] == name) {

      std::cout << "Intern creates " << name << std::endl;

      return functions[i](target);
    }
  }

  std::cout << "Error: form doesn't exist" << std::endl;

  return NULL;
}
