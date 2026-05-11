#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : _value(num << 8) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _value(roundf(num * (1 << 8))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _value(copy._value) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &copy)
    _value = copy._value;
  return *this;
}

bool Fixed::operator==(const Fixed &other) const {
  return _value == other._value;
}
bool Fixed::operator!=(const Fixed &other) const {
  return _value != other._value;
}
bool Fixed::operator<(const Fixed &other) const {
  return _value < other._value;
}
bool Fixed::operator<=(const Fixed &other) const {
  return _value <= other._value;
}
bool Fixed::operator>(const Fixed &other) const {
  return _value > other._value;
}
bool Fixed::operator>=(const Fixed &other) const {
  return _value >= other._value;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _value;
}

void Fixed::setRawBits(int const raw) { _value = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(_value) / (1 << 8);
}

int Fixed::toInt(void) const { return _value >> 8; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}

int Fixed::min(int value_one, int value_two) {
  if (value_one < value_two)
    return value_one;
  else
    return value_two;
}
const Fixed &Fixed::max(const Fixed &one, const Fixed &two) {
  return (one._value > two._value) ? one : two;
}
const Fixed &Fixed::min(const Fixed &one, const Fixed &two) {
  return (one._value < two._value) ? one : two;
}

int Fixed::max(int value_one, int value_two) {
  if (value_one < value_two)
    return value_two;
  else
    return value_one;
}

Fixed &Fixed::operator++() {
  ++_value;
  return *this;
}
Fixed Fixed::operator++(int) {
  Fixed t(*this);
  ++_value;
  return t;
}
Fixed &Fixed::operator--() {
  --_value;
  return *this;
}
Fixed Fixed::operator--(int) {
  Fixed t(*this);
  --_value;
  return t;
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed r;
  r._value = (_value * other._value) >> 8;
  return r;
}
Fixed Fixed::operator/(const Fixed &other) const {
  Fixed r;
  r._value = (_value << 8) / other._value;
  return r;
}
Fixed Fixed::operator+(const Fixed &other) const {
  Fixed r;
  r._value = _value + other._value;
  return r;
}
Fixed Fixed::operator-(const Fixed &other) const {
  Fixed r;
  r._value = _value - other._value;
  return r;
}
