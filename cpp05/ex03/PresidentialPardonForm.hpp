#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm {
private:
  const std::string _target;

public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  virtual ~PresidentialPardonForm();

  void execute(Bureaucrat const & executor) const;
};

#endif