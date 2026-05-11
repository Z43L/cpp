#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string.h>

class Bureaucrat {
protected:
  const std::string name;
  int grade;

public:
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Grade is too high! (Must be >= 1)";
    }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Grade is too low! (Must be <= 150)";
    }
  };
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat operator=(const Bureaucrat &other);
  ~Bureaucrat();

  std::string getName();
  int getGrade();
  int decrement();
};

#endif
