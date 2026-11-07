
#include "Bitcoinexchange.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <limits>

static std::string trim(const std::string& s)
{
    std::size_t a = 0;
    std::size_t b = s.size();
    while (a < b && std::isspace(static_cast<unsigned char>(s[a])))
        ++a;
    while (b > a && std::isspace(static_cast<unsigned char>(s[b - 1])))
        --b;
    return s.substr(a, b - a);
}

static bool validDate(int y, int m, int d)
{
    if (y < 1 || m < 1 || m > 12 || d < 1)
        return false;
    int maxDay = 31;
    if (m == 4 || m == 6 || m == 9 || m == 11)
        maxDay = 30;
    else if (m == 2)
    {
        bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        if(leap)
            maxDay = 29;
        else
            maxDay = 28;
    }
    return d <= maxDay;
}

int atoifecha(std::string entero, int lendate, int init, int fin)
{
    if (init < 0 || fin < init || fin >= lendate ||
        fin >= static_cast<int>(entero.size()))
        return -1;
    std::string str;
    while (init <= fin)
    {
        if (entero[init] < '0' || entero[init] > '9')
            return -1;
        str += entero[init];
        ++init;
    }
    return std::atoi(str.c_str());
}

Bitcoinexchange::Bitcoinexchange()
{
    this->csv = Bitcoinexchange::ordercsv();
    this->dateactual = Bitcoinexchange::date(this->inputread(this->csv));
}

Bitcoinexchange::Bitcoinexchange(const Bitcoinexchange& other)
    : csv(other.csv), dateactual(other.dateactual) {}

Bitcoinexchange& Bitcoinexchange::operator=(const Bitcoinexchange& other)
{
    if (this != &other)
    {
        this->csv = other.csv;
        this->dateactual = other.dateactual;
    }
    return *this;
}

Bitcoinexchange::~Bitcoinexchange() {}

std::map<std::string, double> Bitcoinexchange::ordercsv()
{
    std::map<std::string, double> result;
    std::ifstream file("data.csv");
    if (!file)
        throw std::runtime_error("Error: could not open data.csv.");

    std::string line;
    while (std::getline(file, line))
    {
        std::size_t coma = line.find(',');
        if (coma == std::string::npos)
            continue;
        std::string fecha = trim(line.substr(0, coma));
        if (fecha == "date")
            continue;

        std::vector<std::string> one;
        one.push_back(fecha);
        if (this->date(one).size() != 3)
            continue;

        std::string txt = trim(line.substr(coma + 1));
        char* end = NULL;
        errno = 0;
        double valor = std::strtod(txt.c_str(), &end);
        if (txt.empty() || end == txt.c_str() || *end != '\0' ||
            errno == ERANGE || valor != valor || valor < 0 ||
            valor > std::numeric_limits<double>::max())
            continue;
        result[fecha] = valor;
    }
    if (result.empty())
        throw std::runtime_error("Error: data.csv contains no valid rates.");
    return result;
}

std::vector<std::string> Bitcoinexchange::inputread(
    std::map<std::string, double> input)
{
    std::vector<std::string> istring;
    std::map<std::string, double>::iterator it = input.begin();
    while (it != input.end())
    {
        istring.push_back(it->first);
        ++it;
    }
    return istring;
}

std::map<std::string, int> Bitcoinexchange::date(
    std::vector<std::string> istring)
{
    std::map<std::string, int> result;
    std::size_t i = 0;
    while (i < istring.size())
    {
        if (istring[i].size() == 10 && istring[i][4] == '-' &&
            istring[i][7] == '-')
        {
            int YYYY = atoifecha(istring[i], 10, 0, 3);
            int MM = atoifecha(istring[i], 10, 5, 6);
            int DD = atoifecha(istring[i], 10, 8, 9);
            if (validDate(YYYY, MM, DD))
            {
                result["YYYY"] = YYYY;
                result["MM"] = MM;
                result["DD"] = DD;
            }
        }
        ++i;
    }
    return result;
}

bool Bitcoinexchange::check(std::vector<int> input)
{
    if (input.size() != 3 || !validDate(input[0], input[1], input[2]))
        return false;
    this->dateactual["YYYY"] = input[0];
    this->dateactual["MM"] = input[1];
    this->dateactual["DD"] = input[2];
    return true;
}

bool Bitcoinexchange::findRate(const std::string& fecha, double& rate) const
{
    std::map<std::string, double>::const_iterator it = this->csv.begin();
    bool found = false;
    while (it != this->csv.end())
    {
        if (it->first > fecha)
            break;
        rate = it->second;
        found = true;
        ++it;
    }
    return found;
}

void Bitcoinexchange::execute(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
        throw std::runtime_error("Error: could not open input file.");

    std::string line;
    if (!std::getline(file, line) || trim(line) != "date | value")
        throw std::runtime_error("Error: invalid input header.");

    while (std::getline(file, line))
    {
        std::size_t bar = line.find('|');
        if (bar == std::string::npos || line.find('|', bar + 1) != std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string fecha = trim(line.substr(0, bar));
        std::string valorStr = trim(line.substr(bar + 1));
        std::vector<std::string> one;
        one.push_back(fecha);
        std::map<std::string, int> d = this->date(one);
        std::vector<int> numbers;
        if (d.size() == 3)
        {
            numbers.push_back(d["YYYY"]);
            numbers.push_back(d["MM"]);
            numbers.push_back(d["DD"]);
        }
        if (!this->check(numbers))
        {
            std::cout << "Error: bad input => " << fecha << std::endl;
            continue;
        }

        char* end = NULL;
        errno = 0;
        double value = std::strtod(valorStr.c_str(), &end);
        if (valorStr.empty() || end == valorStr.c_str() || *end != '\0' ||
            errno == ERANGE || value != value)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        double rate = 0;
        if (!this->findRate(fecha, rate))
        {
            std::cout << "Error: no exchange rate available for " << fecha << std::endl;
            continue;
        }
        std::cout << fecha << " => " << value << " = " << value * rate << std::endl;
    }
}

