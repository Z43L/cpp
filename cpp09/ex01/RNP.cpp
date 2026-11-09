#include "RNP.hpp"

rnp::rnp(){
    this->pila.push(0);
}

rnp::rnp(const rnp& other){
    *this = other;
}

rnp rnp::operator=(const rnp& other){
    if(*this != other)
        this->pila = other->pila;
    return this;
}

int rnp::operar(int a , int b, char token){
    if(token == '+')
        return a + b;
    else if (token =='-')
        return a - b;
    else if(token =='*')
        return a * b;
    else if(token =='/')
        return a / b;
    return 0;
}
