class Vehicle {
    private String type;

    public Vehicle(String type) {
        this.type = type;
    }

    public void startEngine() {
        System.out.println("Starting the engine of a generic vehicle");
    }

    public String getType() {
        return type;
    }
}

class Car extends Vehicle {
    public Car(String type) {
        super(type);
    }

    public void startEngine() {
        System.out.println("Starting the engine of a " + getType() + " car");
    }
}

class Motorcycle extends Vehicle {
    public Motorcycle(String type) {
        super(type);
    }

    public void startEngine() {
        System.out.println("Starting the engine of a " + getType() + " motorcycle");
    }
}

public class TestVehicle {
    public static void main(String[] args) {
        Vehicle vehicle1 = new Car("Sedan");
        Vehicle vehicle2 = new Motorcycle("Sport");

        vehicle1.startEngine();
        vehicle2.startEngine();
}
