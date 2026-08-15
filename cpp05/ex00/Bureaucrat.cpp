#include "Bureaucrat.hpp"

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

Bureaucrat Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->grade = other.grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {};

int Bureaucrat::getGrade() { return this->grade; }

std::string Bureaucrat::getName() { return this->name; }

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
