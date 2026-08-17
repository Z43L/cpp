#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>
class Bureaucrat;
class Form {
private:
  const std::string name;
  bool isSingned;
  const int gradeToSing;
  const int gradeToExecute;

public:
  class FormTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Form is too high! (Must be >= 1)";
    }
  };

  class FormTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "From is too low! (Must be <= 150)";
    }
  };
  class FormTooLowPermisionException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Form is too low permission to sing";
    }
  };

  Form(std::string name, bool isSigned, int gradeToSing, int gradeToExecute);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();
  void beSigned(Bureaucrat &Burocrat);
  void setName(std::string name);
  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
};

std::ostream &operator<<(std::ostream &os, const Form &form);
#endif
