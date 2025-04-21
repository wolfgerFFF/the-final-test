#ifndef CAT_H
#define CAT_H

#include "DomesticAnimal.h"

class Cat : public DomesticAnimal
{
public:
    Cat(const std::string &name, const std::string &birthDate);
};

#endif
