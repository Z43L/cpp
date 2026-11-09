#include "RNP.hpp"

int main(int ac , char **av)
{
    int result =0;
    int a =0;
    int b=0;
    rnp rnpp();
    if (ac > 10)
    {
        std::cout << "more than 10 args input worng" <<std::endl;
        return 1;
    }
    for(int i=1; i <= ac ; i++)
    {
        if(std::isdigit(av[i]))
            rnpp.pila.push(std::atoi(av[i]));
        else
        {
            b = rnpp.pila.top;
            rnpp.pila.pop;
            a = rnpp.pila.top;
            rnpp.pila.pop;
            result = rnp::operar(a,b,av[i]);
            rnpp.pila.push(result);
        }
        
    }
    std::cout << result << std:endl;
    return 0;
}
