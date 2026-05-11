#include "main.hpp"

Readfile::Readfile(std::string filename) : filename(filename) {}
Readfile::~Readfile() {}

std::string Readfile::readfile(std::string s1, std::string s2)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    if (s1.empty())
        return content;
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    file.close();
    return content;
}

std::string Readfile::getFilename() const { return filename; }
void Readfile::setFilename(const std::string &f) { filename = f; }

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    Readfile rf(av[1]);
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::string result = rf.readfile(s1, s2);
    
    std::ofstream ofs((rf.getFilename() + ".replace").c_str(), std::ios::trunc);
    if (!ofs.is_open())
    {
        std::cerr << "Error: Could not write file " << rf.getFilename() << ".replace" << std::endl;
        return 1;
    }
    ofs << result;
    ofs.close();

    std::cout << "Modified content written to " << rf.getFilename() << ".replace" << std::endl;
    return 0;
}