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
void Contact::print() {
  std::cout << "number: " << this->number << " | ";
  std::cout << "name: " << this->name << " | ";
  std::cout << "nickname: " << this->nickname << " | ";
  std::cout << "secret: " << this->secret.substr(0, 10) << " | " << std::endl;
}