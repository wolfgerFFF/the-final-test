#ifndef DOG_H
#define DOG_H

#include "DomesticAnimal.h"

class Dog : public DomesticAnimal
{
public:
    Dog(const std::string &name, const std::string &birthDate);
};

#endif
