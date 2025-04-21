#ifndef DOMESTIC_ANIMAL_H
#define DOMESTIC_ANIMAL_H

#include "Animal.h"

class DomesticAnimal : public Animal
{
public:
    DomesticAnimal(const std::string &name, const std::string &birthDate);
};

#endif
