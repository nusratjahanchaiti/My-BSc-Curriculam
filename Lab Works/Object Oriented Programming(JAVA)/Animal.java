public class Animal {
    private String name;

    public Animal(String name) {
        this.name = name;
    }

    public void makeSound() {
        System.out.println("Animal sound"); 
    }

    public String getName() {
        return name;
    }
}

class Dog extends Animal {
   
    public Dog(String name) {
        super(name);
    }
    public void makeSound() {
        System.out.println(getName() + " says Woof!"); 
    }
}

class Cat extends Animal {
    
    public Cat(String name) {
        super(name);
    }

    public void makeSound() {
        System.out.println(getName() + " says Meow!");
    }
}

class Cow extends Animal {
   
    public Cow(String name) {
        super(name);
    }

    public void makeSound() {
        System.out.println(getName() + " says Moo!"); 
    }
}

public class TestAnimal {
    public static void main(String[] args) {
        Animal dog = new Dog("Buddy");
        Animal cat = new Cat("Whiskers");
        Animal cow = new Cow("Moo Moo");

        dog.makeSound(); 
        cat.makeSound(); 
        cow.makeSound(); 
    }
}
