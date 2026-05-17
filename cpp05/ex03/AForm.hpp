#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <ostream>
class Bureaucrat;
class AForm {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  class FormTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Form grade is too high!";
    }
  };

  class FormTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Form grade is too low!";
    }
  };

  class NotSignedException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Form is not signed!"; }
  };

  AForm(std::string name, int gradeToSign, int gradeToExecute);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  void beSigned(Bureaucrat &burocrat);
  virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
