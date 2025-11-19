#include  <iostream>
#include  <string>
#include  <cctype>
int main(int ac , char **av) {
    if (ac == 1) {
        std::cout << " to your home";
    }

    else {
        for (int i = 1; i < ac; i++) {
            std::string arg = av[i];
            for (std::string::iterator it = arg.begin(); it != arg.end();++it) {

                unsigned char c = *it;
                if (!std::isprint(c)) {
                    std::cout << "go to your home and dont prove any more bad is not fun\n";
                    return 0;
                }else {
                    std::cout << (char)toupper(c);
                }
            }
            if (i < ac -1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}