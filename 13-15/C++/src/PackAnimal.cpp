#include "PackAnimal.h"

PackAnimal::PackAnimal(const std::string &name, const std::string &birthDate)
    : Animal(name, birthDate) {}


#include "Horse.h"

Horse::Horse(const std::string &name, const std::string &birthDate)
    : PackAnimal(name, birthDate) {}


#include "Camel.h"

Camel::Camel(const std::string &name, const std::string &birthDate)
    : PackAnimal(name, birthDate) {}


#include "Donkey.h"

Donkey::Donkey(const std::string &name, const std::string &birthDate)
    : PackAnimal(name, birthDate) {}


