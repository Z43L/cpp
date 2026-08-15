#include "Base.hpp"

Base* generate(void) {
    int random_choice = std::rand() % 3;
    
    if (random_choice == 0) {
        return new A();
    } else if (random_choice == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception& e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception& e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception& e) {}
    
    std::cout << "Unknown type" << std::endl;
}
