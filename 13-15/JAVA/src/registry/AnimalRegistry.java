package registry;

import animals.*;
import animals.domestic.*;
import animals.pack.*;
import util.Counter;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AnimalRegistry {
    private List<Animal> animals;
    private Counter counter;

    public AnimalRegistry() {
        this.animals = new ArrayList<>();
        this.counter = new Counter();
    }

    public void addAnimal(String animalType, String name, String birthDate) throws Exception {
        try (Counter c = counter) {
            Animal animal;
            switch (animalType.toLowerCase()) {
                case "dog":
                    animal = new Dog(name, birthDate);
                    break;
                case "cat":
                    animal = new Cat(name, birthDate);
                    break;
                case "hamster":
                    animal = new Hamster(name, birthDate);
                    break;
                case "horse":
                    animal = new Horse(name, birthDate);
                    break;
                case "camel":
                    animal = new Camel(name, birthDate);
                    break;
                case "donkey":
                    animal = new Donkey(name, birthDate);
                    break;
                default:
                    throw new IllegalArgumentException("Неизвестный тип животного");
            }
            animals.add(animal);
            System.out.printf("Животное %s добавлено с ID %d\n", name, animals.size());
        }
    }

    public void teachCommand(int animalId, String command) {
        if (animalId < 1 || animalId > animals.size()) {
            throw new IllegalArgumentException("Неверный ID животного");
        }
        animals.get(animalId - 1).addCommand(command);
        System.out.println("Команда добавлена");
    }

    public void listCommands(int animalId) {
        if (animalId < 1 || animalId > animals.size()) {
            throw new IllegalArgumentException("Неверный ID животного");
        }
        List<String> commands = animals.get(animalId - 1).getCommands();
        System.out.println("Команды животного: " + String.join(", ", commands));
    }

    public void showMenu() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("\nРеестр домашних животных");
            System.out.println("1. Завести новое животное");
            System.out.println("2. Обучить животное команде");
            System.out.println("3. Просмотреть команды животного");
            System.out.println("4. Выход");
            System.out.print("Выберите действие: ");

            String choice = scanner.nextLine();

            try {
                switch (choice) {
                    case "1":
                        System.out.print("Введите тип животного (dog, cat, hamster, horse, camel, donkey): ");
                        String type = scanner.nextLine();
                        System.out.print("Введите имя животного: ");
                        String name = scanner.nextLine();
                        System.out.print("Введите дату рождения (ГГГГ-ММ-ДД): ");
                        String birthDate = scanner.nextLine();
                        addAnimal(type, name, birthDate);
                        break;
                    case "2":
                        System.out.print("Введите ID животного: ");
                        int idToTeach = Integer.parseInt(scanner.nextLine());
                        System.out.print("Введите команду: ");
                        String command = scanner.nextLine();
                        teachCommand(idToTeach, command);
                        break;
                    case "3":
                        System.out.print("Введите ID животного: ");
                        int idToList = Integer.parseInt(scanner.nextLine());
                        listCommands(idToList);
                        break;
                    case "4":
                        scanner.close();
                        return;
                    default:
                        System.out.println("Неверный выбор");
                }
            } catch (Exception e) {
                System.out.println("Ошибка: " + e.getMessage());
            }
        }
    }
}
