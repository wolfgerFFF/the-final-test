package animals;

import java.util.ArrayList;
import java.util.List;

public class Animal {
    private String name;
    private String birthDate;
    private List<String> commands;

    public Animal(String name, String birthDate) {
        this.name = name;
        this.birthDate = birthDate;
        this.commands = new ArrayList<>();
    }

    public void addCommand(String command) {
        commands.add(command);
    }

    public List<String> getCommands() {
        return new ArrayList<>(commands);
    }

    public String getName() {
        return name;
    }

    public String getBirthDate() {
        return birthDate;
    }
}
