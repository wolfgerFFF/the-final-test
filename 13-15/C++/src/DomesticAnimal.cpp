#include "DomesticAnimal.h"

DomesticAnimal::DomesticAnimal(const std::string &name, const std::string &birthDate)
    : Animal(name, birthDate) {}

#include "Dog.h"
Dog::Dog(const std::string &name, const std::string &birthDate)
    : DomesticAnimal(name, birthDate) {}

#include "Cat.h"
Cat::Cat(const std::string &name, const std::string &birthDate)
    : DomesticAnimal(name, birthDate) {}

#include "Hamster.h"

Hamster::Hamster(const std::string &name, const std::string &birthDate)
    : DomesticAnimal(name, birthDate) {}
