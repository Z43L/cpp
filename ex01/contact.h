/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:46:20 by davmoren          #+#    #+#             */
/*   Updated: 2025/12/01 08:46:21 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by david on 14/11/25.
//

#ifndef CPP_CONTACT_H
#define CPP_CONTACT_H
#include <iostream>
#include <string>
#include <iomanip>
#include <iomanip>
#include <sstream>
class Contact {
private:
  int number;
  std::string name;
  std::string secret;
  std::string nickname;

public:
  Contact();
  ~Contact();
  int getnumber();
  std::string getname();
  std::string getsecret();
  std::string getnicknmae();
  void setname(std::string names);
  void setnickname(std::string nicknames);
  void setsecret(std::string secrets);
  void setnumber(int numbers);
  void print();
};

#endif // CPP_CONTACT_H