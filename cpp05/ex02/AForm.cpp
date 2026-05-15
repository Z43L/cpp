#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw AForm::FormTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw AForm::FormTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    this->_isSigned = other._isSigned;
  }
  return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign)
    throw AForm::FormTooLowException();
  _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
     << ", Grade to Sign: " << form.getGradeToSign()
     << ", Grade to Execute: " << form.getGradeToExecute();
  return os;
}
