#include "Bureaucrat.hpp"
#include "AForm.hpp"
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
  this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
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
void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << name << " signed " << form.getName() << std::endl;

  } catch (const std::exception &e) {
    std::cerr << name << " couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
  
}
Bureaucrat::~Bureaucrat() {};

std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

int Bureaucrat::decrement() {
  if (grade >= 150)
    throw GradeTooLowException();
  this->grade += 1;
  return this->grade;
}
void Bureaucrat::executeForm(AForm const &form) const {
  try {
    form.execute(*this);

    std::cout << this->getName() << " executed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->getName() << " couldn't execute " << form.getName()
              << " because " << e.what() << std::endl;
  }
}
