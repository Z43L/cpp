#include "Harl.hpp"

TypeError::TypeError(){

}
TypeError::~TypeError(){

}

 void complain( int level )
 {
    TypeError tiperror;
    tiperror.setMessage_debug();
    tiperror.setMessage_info();
    tiperror.setMessage_warning();
    tiperror.setMessage_werror();
    std::string message  = "";
    while(level <= 4)
    {
        switch (level)
        {
        case 1:
            message= tiperror.getMessage_debug();
            std::cout << "[DEBUG]"<< std::endl;
            std::cout << message<< std::endl ;
            break;
        case 2:
            message = tiperror.getMessage_info();
            std::cout << "[INFO]"<< std::endl;
            std::cout << message << std::endl;
            break;
        case 3:
            message = tiperror.getMessage_warning();
            std::cout << "[WARNING]"<< std::endl;
            std::cout << message<< std::endl;
            break;
        case 4:
            message = tiperror.getMessage_werror();
            std::cout << "[ERROR]"<< std::endl;
            std::cout << message << std::endl;
            break;
        default:
            break;
        };
        std::cout << std::endl;
        level++;
    }
    
}

int main (int ac , char **av)
{
    TypeError TypeError;
    if(ac != 2)
    {
        std::cout<< "use ./harl type(DEBUG,INFO,WARNING,ERROR)" << std::endl;
        return 1;
    }
    int sig = 5;
    std::string  type = av[1];
    if(type == "DEBUG")
        sig = 1;
    else if(type == "INFO")
        sig = 2;
    else if(type == "WARNING")
        sig = 3;
    else if(type == "ERROR")
        sig = 4;
    else
    {
        std::cout<< "use ./harl type(DEBUG,INFO,WARNING,ERROR)" << std::endl;
        return 1;
    }
    complain(sig);
    
    return 0;
}