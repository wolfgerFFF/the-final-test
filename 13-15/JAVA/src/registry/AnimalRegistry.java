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
                // ... другие case
                default:
                    throw new IllegalArgumentException("Неизвестный тип животного");
            }
            animals.add(animal);
        }
    }

    // Другие методы класса...
}
