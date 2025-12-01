/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:46:00 by davmoren          #+#    #+#             */
/*   Updated: 2025/12/01 08:46:01 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "megaphone.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

megaphone::megaphone() {
  for (int i = 0; i < 8; i++)
    this->contact[i] = NULL;
}
megaphone::~megaphone() {
  for (int i = 0; i < 8; i++) {
    if (this->contact[i])
      delete this->contact[i];
  }
}

void megaphone::deletecontact(void) {
  for (int i = 0; i < 8; i++) {
    if (this->contact[i]) {
      delete this->contact[i];
      this->contact[i] = NULL;
    }
  }
}
void megaphone::add(void) {
  for (int i = 0; i < 8; i++) {
    if (this->contact[i] == NULL) {
      std::string name;
      std::string nickname;
      std::string secret;
      int number;
      std::cout << "enter name: ";
      if (!(std::cin >> name)) {
        if (std::cin.eof())
          return;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      } else {
        // continue
      }
      std::cout << "enter nickname: ";
      if (!(std::cin >> nickname)) {
        if (std::cin.eof())
          return;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      std::cout << "enter secret: ";
      while (!(std::cin >> secret)) {
        if (std::cin.eof())
          return;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "to your home\n";
        std::cout << "enter secret: ";
      }

      std::cout << "enter number: ";
      while (!(std::cin >> number)) {
        if (std::cin.eof())
          return;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "invalid number\n";
        std::cout << "enter number: ";
      }

      // All inputs succeeded; allocate and store the contact
      this->contact[i] = new Contact();
      this->contact[i]->setname(name);
      this->contact[i]->setnickname(nickname);
      this->contact[i]->setsecret(secret);
      this->contact[i]->setnumber(number);
      std::cout << "contact added\n";
      return;
    }
  }
  std::cout << "phonebook is full\n";
}

void megaphone::searh(std::string name) {
  if (name == "*") {
    for (int i = 0; i < 8; i++) {
      if (this->contact[i])
        this->contact[i]->print();
    }
    std::system("sleep 5");
    return;
  }
  for (int i = 0; i < 8; i++) {
    if (this->contact[i] && this->contact[i]->getname() == name) {
      this->contact[i]->print();
      std::system("sleep 5");
      return;
    }
  }
  std::cout << "no contact found\n";
  std::system("sleep 5");
}

int main(void) {
  megaphone phonebook;
  while (1) {
    int option;
    std::cout << "welcome to de phonebook        \n";
    std::cout << "-------------------------------\n";
    std::cout << "-please one option dont stupid-\n";
    std::cout << "-    1.ADD                    -\n";
    std::cout << "-    2.SEARCH                 -\n";
    std::cout << "-    3.EXIT                   -\n";
    std::cout << "if you are silly to your home  \n";
    std::cout << "-------------------------------\n";
    std::cout << "enter option: 1 , 2 , 3  \n";
    std::cout << "dont probe more or to your home\n";
    std::cout << "-------------------------------\n";
    while (!(std::cin >> option)) {
      if (std::cin.eof()) {
        std::cout << "goodbye\n";
        return 0;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "to your home\n";
      std::cout << "enter option: ";
    }
    if (option == 1) {
      phonebook.add();
    } else if (option == 2) {
      std::string name;
      std::cout << "enter name: ";
      while (!(std::cin >> name)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "to your home\n";
        std::cout << "enter name: ";
      }
      phonebook.searh(name);
    } else if (option == 3) {
      std::cout << "goodbye\n";
      break;
    } else {
      std::cout << " dont probe more thanks\n";
    }
    std::system("clear");
  }

  return 0;
}
