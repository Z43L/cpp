#include "fixed.hpp"

Fixed::Fixed(): number(0){
    std::cout << "Default constructor called" << std::endl;
    
}
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called" << std::endl;
    this->number = other.number;
 
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->number = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->number;
}

void Fixed::setRawBits(int const raw){
    this->number = raw;
}