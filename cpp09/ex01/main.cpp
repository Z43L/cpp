#include "RNP.hpp"
#include <cctype>

int parse(char *input){

    int token = 0;
    int count = 0;
    for(int i = 0; input[i]; i++)
    {
        if(input[i] != '*' && input[i] != '/' && input[i] != '+' && input[i] != '-' && input[i]!= ' ' && !std::isdigit(input[i]))
        {
            std::cout << "bad input" << std::endl;
            return 1;
        }
        if(input[i] == '*' && input[i] == '/' && input[i] == '+' && input[i] == '-' )
            token++;
        if(std::isdigit(input[i]))
            count++;
        if(input[i] == '*' && input[i] == '/' && input[i] == '+' && input[i] == '-' && input[i+1]!= ' ' )
            return 1;
        if(std::isdigit(input[i])&& input[i+1] != ' ')
            return 1;

    }
    if(count <=1 )
    {
        std::cout << "bad input" << std::endl;
        return 1;
    }
    if(count + token > 10)
    {
        std::cout << "bad input" << std::endl;
        return 1;
    }
    return 0;
        
}

bool istoken(char c)
{

    if(c != '*' && c != '/' && c != '+' && c != '-')
        return false;
    return true;
}

int main(int ac , char **av)
{
    int result =0;
    int a =0;
    int b=0;
    rnp rnpp;
    if (ac > 2)
    {
        std::cout << "more than 10 args input worng" <<std::endl;
        return 1;
    }
    int parser = rnpp.parse(av[1]);
    if(parser ==1)
        return 1;
    for(int i = 0; av[1][i]; i++){
        
        if(av[1][i] == ' ' && av[1][i+1] != '\0')
        {
            while(av[1][i] == ' ')
                i++;
        }
        if(std::isdigit(av[1][i]))
            rnpp.pila.push(std::atoi(&av[1][i]));
        else if(rnpp.istoken(av[1][i]))
        {
            if (rnpp.pila.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            b = rnpp.pila.top();
            rnpp.pila.pop();
            a = rnpp.pila.top();
            rnpp.pila.pop();
            result = rnpp.operar(a,b,av[1][i]);
            rnpp.pila.push(result);
            
        }
    }
    std::cout << result << std::endl;
    return 0;
}
