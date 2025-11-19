//
// Created by david on 14/11/25.
//

#ifndef CPP_MEGAPHONE_H
#define CPP_MEGAPHONE_H

#include "contact.h"

class megaphone {
private:
    Contact contact[8];

public:
    megaphone();
    ~megaphone();
    void searh(std::string name);
    void add(void);
};  


#endif //CPP_MEGAPHONE_H