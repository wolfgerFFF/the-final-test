#ifndef CAMEL_H
#define CAMEL_H

#include "PackAnimal.h"

class Camel : public PackAnimal
{
public:
    Camel(const std::string &name, const std::string &birthDate);
};

#endif
