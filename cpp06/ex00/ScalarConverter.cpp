#include "ScalarConverter.hpp"
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <iomanip>

static bool parse(const std::string &s, double &value) {
    std::string number = s;
    if (!number.empty() && number[number.size() - 1] == 'f') number.erase(number.size() - 1);
    char *end = NULL;
    errno = 0;
    value = std::strtod(number.c_str(), &end);
    return end != number.c_str() && *end == '\0';
}

void ScalarConverter::convert(const std::string &literal) {
    bool special = literal == "nan" || literal == "nanf" || literal == "+inf" ||
                   literal == "+inff" || literal == "-inf" || literal == "-inff";
    double value = 0.0;
    if (!special && !parse(literal, value)) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        return;
    }
    if (special) {
        if (literal == "nan" || literal == "nanf") value = std::numeric_limits<double>::quiet_NaN();
        else value = literal[0] == '-' ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
    }
    bool finite = !std::isnan(value) && !std::isinf(value);
    bool intRange = finite && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
    bool charRange = finite && value >= 0 && value <= 127;
    if (!charRange) std::cout << "char: impossible" << std::endl;
    else if (value < 32) std::cout << "char: Non displayable" << std::endl;
    else std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    if (!intRange) std::cout << "int: impossible" << std::endl;
    else std::cout << "int: " << static_cast<int>(value) << std::endl;
    if (std::isnan(value)) std::cout << "float: nanf\ndouble: nan" << std::endl;
    else if (std::isinf(value)) {
        std::cout << "float: " << (value < 0 ? "-inff" : "inff") << std::endl;
        std::cout << "double: " << (value < 0 ? "-inf" : "inf") << std::endl;
    } else {
        std::cout << "float: " << std::fixed << std::setprecision(1)
                  << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1)
                  << value << std::endl;
    }
}
