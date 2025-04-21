// DomesticAnimal.java
package animals.domestic;

import animals.Animal;

public class DomesticAnimal extends Animal {
    public DomesticAnimal(String name, String birthDate) {
        super(name, birthDate);
    }
}

// Dog.java
package animals.domestic;

public class Dog extends DomesticAnimal {
    public Dog(String name, String birthDate) {
        super(name, birthDate);
    }
}

// Cat.java
package animals.domestic;

public class Cat extends DomesticAnimal {
    public Cat(String name, String birthDate) {
        super(name, birthDate);
    }
}

// Hamster.java
package animals.domestic;

public class Hamster extends DomesticAnimal {
    public Hamster(String name, String birthDate) {
        super(name, birthDate);
    }
}
