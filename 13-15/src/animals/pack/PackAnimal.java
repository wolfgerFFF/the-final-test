// PackAnimal.java
package animals.pack;

import animals.Animal;

public class PackAnimal extends Animal {
    public PackAnimal(String name, String birthDate) {
        super(name, birthDate);
    }
}

// Horse.java
package animals.pack;

public class Horse extends PackAnimal {
    public Horse(String name, String birthDate) {
        super(name, birthDate);
    }
}

// Camel.java
package animals.pack;

public class Camel extends PackAnimal {
    public Camel(String name, String birthDate) {
        super(name, birthDate);
    }
}

// Donkey.java
package animals.pack;

public class Donkey extends PackAnimal {
    public Donkey(String name, String birthDate) {
        super(name, birthDate);
    }
}
