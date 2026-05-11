#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>
class Fixed {
private:
  int _value;
  static const int _fractionalBits = 8;

public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed(const int num);
  Fixed(const float num);
  Fixed &operator=(const Fixed &copy);
  bool operator==(const Fixed &other) const;
  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  Fixed operator+(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  static const Fixed &min(const Fixed &one, const Fixed &two);
  static const Fixed &max(const Fixed &one, const Fixed &two);
  static int min(int value_one, int value_two);

  static int max(int value_one, int value_two);
};
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
