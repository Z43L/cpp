#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main() {
  try {
    Bureaucrat a("uno", 4);
    Bureaucrat b("dos", 5);
    Bureaucrat c("fail", 199);
    Bureaucrat d("fail2", -2);
    std::cout << a.getName() << " has created whit rank" << a.getGrade()
              << std::endl;
    std::cout << b.getName() << " has created whit rank" << b.getGrade()
              << std::endl;
    std::cout << c.getName() << " has created whit rank" << c.getGrade()
              << std::endl;
    std::cout << d.getName() << " has created whit rank" << d.getGrade()
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error creando Bureaucrat: " << e.what() << std::endl;
  }

  try {
    Bureaucrat highRank("Hermes", 0);
    std::cout << highRank.getName() << " with " << highRank.getGrade()
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  try {
    Bureaucrat normal("Fry", 150);
    std::cout << normal.getName() << " has created whit rank"
              << normal.getGrade() << std::endl;
    std::cout << "Burócrata creado con éxito." << std::endl;
    RobotomyRequestForm sing("sig");
    sing.execute(normal);

    sing.beSigned(normal);
    normal.decrement();

  } catch (const std::exception &e) {
    std::cerr << "Error modificating: " << e.what() << std::endl;
  }
  try {
    Bureaucrat normal("Fry", 5);
    PresidentialPardonForm sing("sig");
    sing.beSigned(normal);
    sing.execute(normal);
    RobotomyRequestForm sing1("sig");
    sing1.beSigned(normal);
    sing1.execute(normal);
    ShrubberyCreationForm presidential("presidential");
    presidential.beSigned(normal);
    presidential.execute(normal);
  } catch (const std::exception &e) {
    std::cerr << "error modificating:" << e.what() << std::endl;
  }
  try {
    Bureaucrat afo("afo", 50);

    ShrubberyCreationForm presidential("presidential");
    afo.signForm(presidential);
    presidential.execute(afo);
  } catch (const std::exception &e) {
    std::cerr << "error modificating:" << e.what() << std::endl;
  }

  return 0;
}
