#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main()
{
    Intern someRandomIntern;

    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    if (rrf)
    {
        Bureaucrat boss("Hermes", 1);

        std::cout << *rrf << std::endl;

        boss.signForm(*rrf);

        boss.executeForm(*rrf);

        delete rrf;
    }

    return 0;
}