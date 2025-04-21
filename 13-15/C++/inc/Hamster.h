#ifndef HAMSTER_H
#define HAMSTER_H

#include "DomesticAnimal.h"

class Hamster : public DomesticAnimal
{
public:
    Hamster(const std::string &name, const std::string &birthDate);
};

#endif 
