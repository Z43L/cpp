#include "RNP.hpp"

rnp::rnp(){
    this->pila.push(0);
}

rnp::rnp(const rnp& other){
    *this = other;
}

rnp rnp::operator=(const rnp& other){
    if(this != &other)
        this->pila = other.pila;
    return *this;
}
rnp::~rnp(){}
int rnp::operar(int a , int b, char token){
    if(token == '+')
        return a + b;
    else if (token =='-')
        return a-b;
    else if(token =='*')
        return a * b;
    else if(token =='/')
        return a / b;
    return 0;
}

int rnp::parse(char *input){

    int token = 0;
    int count = 0;
    for(int i = 0; input[i]; i++)
    {
        if(input[i] != '*' && input[i] != '/' && input[i] != '+' && input[i] != '-' && input[i]!= ' ' && !std::isdigit(input[i]))
        {
            std::cout << "bad input" << std::endl;
            return 1;
        }
        if(input[i] == '*' && input[i] == '/' && input[i] == '+' && input[i] == '-' )
            token++;
        if(std::isdigit(input[i]))
            count++;
        if(input[i] == '*' && input[i] == '/' && input[i] == '+' && input[i] == '-' && input[i+1]!= ' ' )
            return 1;
        if(std::isdigit(input[i])&& input[i+1] != ' ')
            return 1;

    }
    if(count <=1 )
    {
        std::cout << "bad input" << std::endl;
        return 1;
    }
    return 0;
        
}

bool rnp::istoken(char c)
{

    if(c != '*' && c != '/' && c != '+' && c != '-')
        return false;
    return true;
}
