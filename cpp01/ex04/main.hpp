#include<iostream>
#include <string>
#include <fstream>
class Readfile
{
private:
    std::string filename;

public:
    Readfile(std::string filename);
    ~Readfile();

    std::string readfile(std::string s1, std::string s2);
    std::string getFilename() const;
    void setFilename(const std::string &filename);
};