#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class Robotomyrequestform: AForm {
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


  Robotomyrequestform(std::string name, bool isSigned, int gradeToSing, int gradeToExecute);
  Robotomyrequestform(const AForm &other);
  Robotomyrequestform operator=(const AForm &other);
  ~Robotomyrequestform();
  void beSigned(Bureaucrat &Burocrat);
  void singForm(Bureaucrat &Burocrat);
  void execute(Bureaucrat const & executor) const;
};

inline std::ostream &operator<<(std::ostream &os, const AForm &form);


#endif
