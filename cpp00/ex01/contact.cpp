/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:45:35 by davmoren          #+#    #+#             */
/*   Updated: 2025/12/01 08:45:36 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.h"

Contact::Contact() : number(0) {}
Contact::~Contact() {}
int Contact::getnumber() { return this->number; }
std::string Contact::getname() { return this->name; }
std::string Contact::getsecret() { return this->secret; }
std::string Contact::getnicknmae() { return this->nickname; }
void Contact::setname(std::string names) { this->name = names; }
void Contact::setnickname(std::string nicknames) { this->nickname = nicknames; }
void Contact::setsecret(std::string secrets) { this->secret = secrets; }
void Contact::setnumber(int numbers) { this->number = numbers; }
static std::string trunc_str(const std::string &s) {
  if (s.size() > 10) {
    return s.substr(0, 9) + ".";
  }
  return s;
}
void Contact::print() {
  std::ostringstream oss;
  oss << this->number;
  std::string num = oss.str();

  std::cout << std::right
            << std::setw(10) << trunc_str("name") << " | "
            << std::setw(10) << trunc_str("nickname")<< " | "
            << std::setw(10) << trunc_str("secrect")<< " | "
            << std::setw(10) << trunc_str("number") << " | "
            << std::endl;
  std::cout << std::right
            << std::setw(10) << trunc_str(this->name)     << " | "
            << std::setw(10) << trunc_str(this->nickname) << " | "
            << std::setw(10) << trunc_str(this->secret)   << " | "
            << std::setw(10) << trunc_str(num)   << " | "
            << std::endl;
}