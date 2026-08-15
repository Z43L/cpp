#include "Bureaucrat.hpp"
#include "Form.hpp"
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
    Form sing("sig", false, 140, 140);

    sing.beSigned(normal);
    normal.decrement();
    
  } catch (const std::exception &e) {
    std::cerr << "Error modificating: " << e.what() << std::endl;
  }
  try {
       Bureaucrat normal("Fry", 50);
       Form sing("sig", false, 130, 140);
       normal.signForm(sing);
  }
  catch (const std::exception &e) {
      std::cerr << "error modificating:" << e.what() << std::endl;
  }

  return 0;
}
