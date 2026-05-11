#include <iostream>
#include <string>

class TypeError{
    private:
        std::string message_debug ; 
        std::string message_info ;
        std::string message_warning ;
        std::string message_werror ;

    public:
        TypeError();
        ~TypeError();
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        void setMessage_debug();
        void setMessage_info();
        void setMessage_warning();
        void setMessage_werror();
        std::string getMessage_debug();
        std::string getMessage_info();
        std::string getMessage_warning();
        std::string getMessage_werror();
};