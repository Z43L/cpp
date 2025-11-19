//
// Created by david on 14/11/25.
//

#ifndef CPP_CONTACT_H
#define CPP_CONTACT_H
#include <iostream>
#include  <string>


class Contact {
private:
    int number;
    std::string name;
    std::string secret;
    std::string nickname;

public:
    Contact() : number(0) {}
    ~Contact() {}
    int getnumber() {
        return this->number;
    }
    std::string getname() {
        return this->name;
    }
    std::string getsecret() {
        return this->secret;
    }
    std::string getnicknmae() {
        return this->nickname;
    }
    void setname(std::string names) {
        this->name = names;
    }
    void setnickname(std::string nicknames) {
        this->nickname = nicknames;
    }
    void setsecret(std::string secrets) {
        this->secret = secrets;
    }
    void setnumber(int numbers) {
        this->number = numbers;
    }
    void print() {
        std::cout << "number: " << this->number << std::endl;
        std::cout << "name: " << this->name << std::endl;
        std::cout << "nickname: " << this->nickname << std::endl;
        std::cout << "secret: " << this->secret << std::endl;
    }

};

#endif //CPP_CONTACT_H