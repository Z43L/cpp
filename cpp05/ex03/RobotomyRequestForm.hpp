#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
class RobotomyRequestForm : public AForm {
private:
  const std::string _target;

public:
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
  virtual ~RobotomyRequestForm();

  void execute(Bureaucrat const & executor) const;
};

#endif

