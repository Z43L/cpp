#ifndef SCALARCONVERTER_HPP
#define  SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>


class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& type);
        ScalarConverter operator=(const ScalarConverter& type);
        ~ScalarConverter();
    public:
        static void converter(const std::string &literal);
       
};


#endif