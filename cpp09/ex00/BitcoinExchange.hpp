#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <vector>
#include <string>

class Bitcoinexchange
{
    private:
        std::map<std::string, double> csv;
        std::map<std::string, int> dateactual;

    public:
        Bitcoinexchange();
        Bitcoinexchange(const Bitcoinexchange& other);
        Bitcoinexchange& operator=(const Bitcoinexchange& other);
        ~Bitcoinexchange();

        std::map<std::string, double> ordercsv();
        std::vector<std::string> inputread(std::map<std::string, double> input);
        std::map<std::string, int> date(std::vector<std::string> istring);
        bool check(std::vector<int> input);
        bool findRate(const std::string& fecha, double& rate) const;
        void execute(const std::string& filename);
};

#endif
