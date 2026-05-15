#include "Form.hpp"

Form::Form(std::string name, bool isSigned, int gradeToSing, int gradeToExecute)
    : name(name), isSingned(isSigned), gradeToSing(gradeToSing),
      gradeToExecute(gradeToExecute) {
  if (gradeToExecute > 150 || gradeToSing > 150)
    throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), gradeToSing(other.gradeToSing),
      gradeToExecute(other.gradeToExecute) {
  if (this != &other) {
    this->isSingned = other.isSingned;
  }
}

Form Form::operator=(const Form &other) {
  if (this->isSingned != other.isSingned) {
    this->isSingned = other.isSingned;
  }
  return *this;
}
Form::~Form() {}

void Form::beSigned(Bureaucrat &burocrat) {
   try{
        Form::singForm(burocrat);
        std::cout << burocrat.getName()<< " is singned " << this->name << std::endl; 

   }catch(const std::exception &e){
        std::cerr << burocrat.getName() << " couldn’t sign " << this->name  << " "<< e.what() << std::endl; 
   }
   
}

void Form::singForm(Bureaucrat &Burocrat) {
    if(this->gradeToSing > Burocrat.getGrade() )    
    {
        throw Form::FormTooLowPermisionException();
    }
    
}
