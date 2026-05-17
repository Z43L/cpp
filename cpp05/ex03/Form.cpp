#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form(std::string name, bool isSigned, int gradeToSing, int gradeToExecute)
    : name(name), isSingned(isSigned), gradeToSing(gradeToSing),
      gradeToExecute(gradeToExecute) {
  if (gradeToExecute > 150 || gradeToSing > 150)
    throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), gradeToSing(other.gradeToSing),
      gradeToExecute(other.gradeToExecute) {
  if (this != &other) {
    this->isSingned = other.isSingned;
  }
}

Form Form::operator=(const Form &other) {
  if (this->isSingned != other.isSingned) {
    this->isSingned = other.isSingned;
  }
  return *this;
}
Form::~Form() {}

std::string Form::getName() { return this->name; }
void Form::beSigned(Bureaucrat &burocrat) {
  try {
    std::cout << burocrat.getName() << " signed " << this->getName() << std::endl;
  } catch (std::exception const &e) {
    std::cout << burocrat.getName() << " couldn’t sign " << this->getName() << std::endl;
  }
}
