#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form(std::string name, bool isSigned, int gradeToSing, int gradeToExecute)
    : name(name), isSingned(isSigned), gradeToSing(gradeToSing),
      gradeToExecute(gradeToExecute) {
  if (gradeToExecute > 150 || gradeToSing > 150)
    throw Form::FormTooLowPermisionException();
  if (gradeToExecute <= 0 || gradeToSing <= 0)
    throw Form::FormTooHighException();
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
void Form::beSigned( Bureaucrat &b) {
  if (b.getGrade() > this->gradeToSing)
    throw Form::FormTooLowPermisionException();
  this->isSingned = true;
}