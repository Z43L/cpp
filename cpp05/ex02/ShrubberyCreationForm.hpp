#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
  const std::string _target;

public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  virtual ~ShrubberyCreationForm();

  void execute(Bureaucrat const & executor) const;
};

#endif
