/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:46:00 by davmoren          #+#    #+#             */
/*   Updated: 2026/01/26 18:13:38 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

megaphone::megaphone()
{
  for (int i = 0; i < 8; i++)
    this->contact[i] = NULL;
}
megaphone::~megaphone()
{
  for (int i = 0; i < 8; i++)
  {
    if (this->contact[i])
      delete this->contact[i];
  }
}

void megaphone::deletecontact(int i)
{
  if (this->contact[i])
  {
    delete this->contact[i];
    this->contact[i] = NULL;
  }
}

bool is_valid_string(const std::string &str)
{
  if (str.empty())
    return false;

  bool has_content = false;
  for (size_t i = 0; i < str.length(); i++)
  {
    if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r')
    {
      has_content = true;
      break;
    }
  }
  if (!has_content)
    return false;

  for (size_t i = 0; i < str.length(); i++)
  {
    if (str[i] < 32 || str[i] > 126)
    {
      return false;
    }
  }
  return true;
}

bool is_valid_name(const std::string &str)
{
  if (!is_valid_string(str))
    return false;

  for (size_t i = 0; i < str.length(); i++)
  {
    if (!((str[i] >= 'a' && str[i] <= 'z') ||
          (str[i] >= 'A' && str[i] <= 'Z') ||
          str[i] == ' '))
    {
      return false;
    }
  }
  return true;
}

void megaphone::add(void)
{
  int insert_pos = -1;
  for (int i = 0; i < 8; i++)
  {

    for (int i = 0; i <= 8; i++)
    {
      if (this->contact[i] == NULL)
      {
        insert_pos = i;
        break;
      }
    }

    if (insert_pos == -1)
    {
      insert_pos = this->oldest_index;
      deletecontact(insert_pos);
    }
    if (this->contact[i] == NULL)
    {
      std::string name;
      std::string nickname;
      std::string secret;
      int number;

      std::cout << "enter name: ";
      while (true)
      {
        if (!(std::cin >> name))
        {
          if (std::cin.eof())
            return;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "invalid input\n";
          std::cout << "enter name: ";
          continue;
        }
        if (!is_valid_name(name))
        {
          std::cout << "invalid name (only letters allowed)\n";
          std::cout << "enter name: ";
          continue;
        }
        break;
      }

      std::cout << "enter nickname: ";
      while (true)
      {
        if (!(std::cin >> nickname))
        {
          if (std::cin.eof())
            return;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "invalid input\n";
          std::cout << "enter nickname: ";
          continue;
        }
        if (!is_valid_string(nickname))
        {
          std::cout << "invalid nickname (cannot be empty)\n";
          std::cout << "enter nickname: ";
          continue;
        }
        break;
      }

      std::cout << "enter secret: ";
      while (true)
      {
        if (!(std::cin >> secret))
        {
          if (std::cin.eof())
            return;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "invalid input\n";
          std::cout << "enter secret: ";
          continue;
        }
        if (!is_valid_string(secret))
        {
          std::cout << "invalid secret (cannot be empty)\n";
          std::cout << "enter secret: ";
          continue;
        }
        break;
      }

      std::cout << "enter number: ";
      while (true)
      {
        if (!(std::cin >> number))
        {
          if (std::cin.eof())
            return;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "invalid number\n";
          std::cout << "enter number: ";
          continue;
        }
        if (number < 0)
        {
          std::cout << "number must be positive\n";
          std::cout << "enter number: ";
          continue;
        }
        break;
      }

      this->contact[insert_pos] = new Contact();
      this->contact[insert_pos]->setname(name);
      this->contact[insert_pos]->setnickname(nickname);
      this->contact[insert_pos]->setsecret(secret);
      this->contact[insert_pos]->setnumber(number);
      this->oldest_index = (insert_pos + 1) % 8;
      std::cout << "contact added\n";
      return;
    }
    
  }
  std::cout << "phonebook is full\n";
}

void megaphone::searh(std::string name)
{
  if (name == "*")
  {
    for (int i = 0; i < 8; i++)
    {
      if (this->contact[i])
        this->contact[i]->print();
    }
    std::system("sleep 5");
    return;
  }
  for (int i = 0; i < 8; i++)
  {
    if (this->contact[i] && this->contact[i]->getname() == name)
    {
      this->contact[i]->print();
      std::system("sleep 5");
      return;
    }
  }
  std::cout << "no contact found\n";
  std::system("sleep 5");
}

int main(void)
{
  megaphone phonebook;
  while (1)
  {
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
    while (!(std::cin >> option))
    {
      if (std::cin.eof())
      {
        std::cout << "goodbye\n";
        return 0;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "to your home\n";
      std::cout << "enter option: ";
    }
    if (option == 1)
    {
      phonebook.add();
    }
    else if (option == 2)
    {
      std::string name;
      std::cout << "enter name: ";
      while (!(std::cin >> name))
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "to your home\n";
        std::cout << "enter name: ";
      }
      phonebook.searh(name);
    }
    else if (option == 3)
    {
      std::cout << "goodbye\n";
      break;
    }
    else
    {
      std::cout << " dont probe more thanks\n";
    }
    std::system("clear");
  }

  return 0;
}
