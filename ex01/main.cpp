
#include "megaphone.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

megaphone::megaphone() {}
megaphone::~megaphone() {}

void megaphone::deletecontact(void) {
  for (int i = 0; i < 8; i++) {
    contact[i].deleteall();
  }
}
void megaphone::add(void) {
  for (int i = 0; i < 8; i++) {
    if (contact[i].getname() == "") {
      std::string name;
      std::string nickname;
      std::string secret;
      int number;
      std::cout << "enter name: ";
      std::cin >> name;
      contact[i].setname(name);
      std::cout << "enter nickname: ";
      std::cin >> nickname;
      contact[i].setnickname(nickname);
      std::cout << "enter secret: ";
      while (!(std::cin >> secret)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "to your home\n";
        std::cout << "enter secret: ";
      }
      contact[i].setsecret(secret);
      std::cout << "enter number: ";
      while (!(std::cin >> number)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "invalid number\n";
        std::cout << "enter number: ";
      }
      contact[i].setnumber(number);
      std::cout << "contact added\n";
      return;
    }
  }
  std::cout << "phonebook is full\n";
}

void megaphone::searh(std::string name) {
  if (name == "*") {
    for (int i = 0; i < 8; i++) {
      contact[i].print();
    }
    std::system("sleep 5");
    return;
  }
  for (int i = 0; i < 8; i++) {
    if (contact[i].getname() == name) {
      contact[i].print();
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
      phonebook.deletecontact();
      break;
    } else {
      std::cout << " dont probe more thanks\n";
    }
    std::system("clear");
  }

  return 0;
}
