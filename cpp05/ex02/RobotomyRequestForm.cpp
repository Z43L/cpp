#include "Robotomyrequestform.hpp"



Robotomyrequestform::Robotomyrequestform (std::string name, bool isSigned, int gradeToSing, int gradeToExecute)
    : AForm(name, isSigned, gradeToSing, gradeToExecute) {
  if (gradeToExecute > 150 || gradeToSing > 150)
    throw AForm::FormTooLowException();
}

Robotomyrequestform::Robotomyrequestform (const AForm &other)
    : AForm(other) {
  if (this != &other) {
    this->isSingned = other.isSingned;
  }
}

Robotomyrequestform  Robotomyrequestform::operator=(const AForm &other) {
  if (this->isSingned != other.isSingned) {
    this->isSingned = other.isSingned;
  }
  return *this;
}
Robotomyrequestform::~Robotomyrequestform() {}

void Robotomyrequestform::beSigned(Bureaucrat &burocrat) {
   try{
        AForm::singForm(burocrat);
        std::cout << burocrat.getName()<< " is singned " << this->name << std::endl; 

   }catch(const std::exception &e){
        std::cerr << burocrat.getName() << " couldn’t sign " << this->name  << " "<< e.what() << std::endl; 
   }
   
}

void Robotomyrequestform::singForm(Bureaucrat &Burocrat) {
    if(this->gradeToSing > Burocrat.getGrade() )    
    {
        throw AForm::FormTooLowPermisionException();
    }
    
}
 
void Robotomyrequestform::execute(Bureaucrat const & executor) const{
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Making drill sounds... BZZZZZ BRRRRRR CRACK SHHHHH" << std::endl;

    if (std::rand() % 2 == 0) {
        std::cout << "Successfully robotomized " << this->target << " into a badger!" << std::endl;
    } else {
        std::cout << "Robotomy failed. " << this->target << " is still just a boring person." << std::endl;
    }
}
