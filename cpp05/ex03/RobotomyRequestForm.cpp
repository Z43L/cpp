#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned())
    throw AForm::NotSignedException();
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::FormTooLowException();

  std::cout << "Making drill sounds... BZZZZZ BRRRRRR CRACK SHHHHH"
            << std::endl;

  if (std::rand() % 2 == 0) {
    std::cout << "Successfully robotomized " << this->_target
              << " into a badger!" << std::endl;
  } else {
    std::cout << "Robotomy failed. " << this->_target
              << " is still just a boring person." << std::endl;
  }
}
