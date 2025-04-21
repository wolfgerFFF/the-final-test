#include "AnimalRegistry.h"
#include "Dog.h"
#include "Cat.h"
#include "Hamster.h"
#include "Horse.h"
#include "Camel.h"
#include "Donkey.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

void AnimalRegistry::addAnimal(const std::string &animalType, const std::string &name, const std::string &birthDate)
{
    try
    {
        Counter c;
        int id = c.add();

        std::unique_ptr<Animal> animal;
        if (animalType == "dog")
        {
            animal = std::make_unique<Dog>(name, birthDate);
        }
        else if (animalType == "cat")
        {
            animal = std::make_unique<Cat>(name, birthDate);
        }
        else if (animalType == "hamster")
        {
            animal = std::make_unique<Hamster>(name, birthDate);
        }
        else if (animalType == "horse")
        {
            animal = std::make_unique<Horse>(name, birthDate);
        }
        else if (animalType == "camel")
        {
            animal = std::make_unique<Camel>(name, birthDate);
        }
        else if (animalType == "donkey")
        {
            animal = std::make_unique<Donkey>(name, birthDate);
        }
        else
        {
            throw std::invalid_argument("Неизвестный тип животного");
        }

        animals.push_back(std::move(animal));
        std::cout << "Животное " << name << " добавлено с ID " << animals.size() << std::endl;

        c.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}

void AnimalRegistry::teachCommand(int animalId, const std::string &command)
{
    if (animalId < 1 || animalId > static_cast<int>(animals.size()))
    {
        throw std::out_of_range("Неверный ID животного");
    }
    animals[animalId - 1]->addCommand(command);
    std::cout << "Команда добавлена" << std::endl;
}

void AnimalRegistry::listCommands(int animalId) const
{
    if (animalId < 1 || animalId > static_cast<int>(animals.size()))
    {
        throw std::out_of_range("Неверный ID животного");
    }
    auto commands = animals[animalId - 1]->getCommands();
    std::cout << "Команды животного: ";
    for (size_t i = 0; i < commands.size(); ++i)
    {
        if (i != 0)
            std::cout << ", ";
        std::cout << commands[i];
    }
    std::cout << std::endl;
}

void AnimalRegistry::showMenu()
{
    while (true)
    {
        std::cout << "\nРеестр домашних животных\n";
        std::cout << "1. Завести новое животное\n";
        std::cout << "2. Обучить животное команде\n";
        std::cout << "3. Просмотреть команды животного\n";
        std::cout << "4. Выход\n";
        std::cout << "Выберите действие: ";

        std::string choice;
        std::getline(std::cin, choice);

        try
        {
            if (choice == "1")
            {
                std::cout << "Введите тип животного (dog, cat, hamster, horse, camel, donkey): ";
                std::string type;
                std::getline(std::cin, type);

                std::cout << "Введите имя животного: ";
                std::string name;
                std::getline(std::cin, name);

                std::cout << "Введите дату рождения (ГГГГ-ММ-ДД): ";
                std::string birthDate;
                std::getline(std::cin, birthDate);

                addAnimal(type, name, birthDate);
            }
            else if (choice == "2")
            {
                std::cout << "Введите ID животного: ";
                int id;
                std::cin >> id;
                std::cin.ignore();

                std::cout << "Введите команду: ";
                std::string command;
                std::getline(std::cin, command);

                teachCommand(id, command);
            }
            else if (choice == "3")
            {
                std::cout << "Введите ID животного: ";
                int id;
                std::cin >> id;
                std::cin.ignore();

                listCommands(id);
            }
            else if (choice == "4")
            {
                break;
            }
            else
            {
                std::cout << "Неверный выбор\n";
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }
}
