#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

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
  Form(std::string name, bool isSigned, int gradeToSing, int gradeToExecute);
  Form(const Form &other);
  Form operator=(const Form &other);
  ~Form();
  void beSigned(Bureaucrat Burocrat);
  std::string singForm(Bureaucrat Burocrat);
};

inline std::ostream &operator<<(std::ostream &os, const Form &form);
#endif
