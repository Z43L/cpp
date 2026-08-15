#include "Bureaucrat.hpp"
#include "Form.hpp"
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
  if (grade <= 0)
    throw GradeTooLowException();
  if (grade > 150)
    throw GradeTooHighException();
  this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {
  if (grade < 1)
    throw GradeTooLowException();
  if (grade > 150)
    throw GradeTooHighException();
  if (this != &other) {
    *this = other;
  }
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->grade = other.grade;
  }
  return *this;
}
void Bureaucrat::signForm(Form &form) { 
  try {
    form.beSigned(*this);
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << this->name << " couldn’t sign " << form.getName() 
              << " because " << e.what() << std::endl;
  }
}
std::string Bureaucrat::getName() { return this->name; }
Bureaucrat::~Bureaucrat() {};

std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

int Bureaucrat::increment() {
  if (grade <= 0)
    throw GradeTooLowException();
  if (grade > 149)
    throw GradeTooHighException();
  this->grade -= 1;
  return this->grade;
}
int Bureaucrat::decrement() {
  if (grade <= 1)
    throw GradeTooLowException();
  if (grade > 150)
    throw GradeTooHighException();
  this->grade += 1;
  return this->grade;
}