#include "PackAnimal.h"

PackAnimal::PackAnimal(const std::string &name, const std::string &birthDate)
    : Animal(name, birthDate) {}

// Horse.cpp
#include "Horse.h"

Horse::Horse(const std::string &name, const std::string &birthDate)
    : PackAnimal(name, birthDate) {}

// Camel.cpp
#include "Camel.h"

Camel::Camel(const std::string &name, const std::string &birthDate)
    : PackAnimal(name, birthDate) {}

// Donkey.cpp
#include "Donkey.h"

Donkey::Donkey(const std::string &name, const std::string &birthDate)
    : PackAnimal(name, birthDate) {}


