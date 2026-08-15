#include "ScalarConverter.hpp"


/* 
static bool isPrintableChar(const std::string &literal){
    if(literal.length() == 1 )
    {
        int c = static_cast<char>(literal[0]);
        if(c <= 127 && c >= 1)
        {
            std::cout<< "char: " << c<<std::endl;
            return true;
        }
        else{
            std::cout << "char: impossible\n";
        }
    }
    return false;
} */

static char isNumberPrintableChar(const std::string &literal){
    double num = std::strtod(literal.c_str(), NULL);
    if(num < 127 && num >= 0)
        {
            char c = static_cast<char>(num);
            //std::cout<< "char: " << c  <<std::endl;
            return c;
        }
    if((num > 127 && num <=0 )||(literal.length() == 1 && std::isdigit(literal[0])))
        std::cout << "char: impossible\n";
    return false;;
}

/* static double whatDouble(const std::string &literal){
    double num = std::strtod(literal.c_str(), NULL);
    return num;
} */

static int isNumber(const std::string &literal){

    double num = std::strtod(literal.c_str(), NULL);
    int numInt = std::atoi(literal.c_str());
    //int len = literal.length();
    if(literal.length() == 1 && !std::isdigit(literal[0])){
        num = static_cast<int>(literal[0]);
        numInt= static_cast<int>(literal[0]);
    }
    std::cout<< "float: "<< std::fixed << std::setprecision(1) << num << 'f' << std::endl;
    
    std::cout << "double: "<< std::fixed << std::setprecision(1) << num << std::endl;
    std::cout<< "int: " << numInt << std::endl;
    return numInt;
}

static void whatType(const std::string &literal){
    
    int num =  isNumber(literal);
    char c = isNumberPrintableChar(literal);
    
    if(literal.length() == 1 && !std::isdigit(literal[0]))
        std::cout << "char: " << literal[0]<< std::endl;
    else if(num <= 127 && num >=1)
        std::cout << "char: " <<c << std::endl;
    else if(num >= 127|| num <=1 || isdigit(literal[0]))
        std::cout << "char: impossible\n";
}

void ScalarConverter::converter(const std::string &literal){

    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    whatType(literal);

}