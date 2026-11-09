#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <string>

class rnp{
    private:
        
    public:
        rnp();
        rnp(const rnp& other);
        rnp operator=(const rnp& other);
        ~rnp();
        int operar(int a, int b, char token);
        std::stack<int> pila;
        int parse(char *input);
        bool istoken(char c);

        
};



#endif
