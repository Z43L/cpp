#include "Base.hpp"
int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "Generating 5 random objects..." << std::endl;
    std::cout << "------------------------------" << std::endl;

    for (int i = 0; i < 5; ++i) {
        Base* random_obj = generate();
        
        std::cout << "Test " << (i + 1) << ":" << std::endl;
        
        std::cout << "  Identify via Pointer   : ";
        identify(random_obj);
        
        std::cout << "  Identify via Reference : ";
        identify(*random_obj);
        
        std::cout << "------------------------------" << std::endl;
        
        delete random_obj;
    }

    return 0;
}
