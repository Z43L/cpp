
#include "Harl.hpp"
std::string TypeError::getMessage_debug()
{
    std::string message = this->message_debug;
    return message;
}
std::string TypeError::getMessage_info(){
    std::string message = this->message_info;
    return message;
}
std::string TypeError::getMessage_warning(){
    std::string message = this->message_warning;
    return message;
}
std::string TypeError::getMessage_werror()
{
    std::string message = this->message_werror;
    return message;
}
void TypeError::debug( void )
{
    std::cout << getMessage_debug() << std::endl;
}
void TypeError::info( void )
{
    std::cout << getMessage_info() << std::endl;
}
void TypeError::warning( void )
{
std::cout << getMessage_warning() << std::endl;
}
void TypeError::error( void ){
std::cout << getMessage_werror() << std::endl;
}

void TypeError::setMessage_debug(void)
{
    std::string message ="I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
    this->message_debug = message;
    
}

void TypeError::setMessage_info(){
    std::string message = "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
    this->message_info = message;
}

void TypeError::setMessage_warning(){
    std::string message  ="I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.";
    this->message_warning = message;
}
void TypeError::setMessage_werror(){
    std::string message = "This is unacceptable! I want to speak to the manager now.";
    this->message_werror = message;
}