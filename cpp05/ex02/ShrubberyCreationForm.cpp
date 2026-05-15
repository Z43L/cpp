#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  if (!this->getIsSigned())
    throw AForm::NotSignedException();
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::FormTooLowException();

  std::string filename = _target + "_shrubbery";
  std::ofstream outfile(filename.c_str());
  if (outfile.is_open()) {
    outfile << "      /\\      " << std::endl;
    outfile << "     /\\*\\     " << std::endl;
    outfile << "    /\\O\\*\\    " << std::endl;
    outfile << "   /*/\\/\\/\\   " << std::endl;
    outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
    outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile.close();
  }
}
