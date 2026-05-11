#include "Harl.hpp"

TypeError::TypeError(){

}
TypeError::~TypeError(){

}
 void complain( std::string level )
 {
    TypeError tiperror;
    tiperror.setMessage_debug();
    tiperror.setMessage_info();
    tiperror.setMessage_warning();
    tiperror.setMessage_werror();
    
    if(level == "DEBUG")
    {
        std::string message = tiperror.getMessage_debug();
        std::cout << message << std::endl;
    }
        
    else if(level == "INFO")
    {
        std::string message = tiperror.getMessage_info();
        std::cout << message << std::endl;
    }
    else if(level == "WARNING")
    {
        std::string message = tiperror.getMessage_warning();
        std::cout << message << std::endl;
    }
    else if( level == "ERROR")
    {
        std::string message = tiperror.getMessage_werror();
        std::cout << message << std::endl;
    }
    else
        std::cout << "dont prove bad" << std::endl;
 }
int main (int ac , char **av)
{
    TypeError TypeError;
    if(ac != 2)
    {
        std::cout<< "use ./harl type(DEBUG,INFO,WARNING,ERROR)" << std::endl;
        return 1;
    }
    std::string  type = av[1];
    
    complain(type);
    
    return 0;
}