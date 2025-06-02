abstract class Robot {
    private String name;

    public Robot(String name) {
        this.name = name;
    }

    public abstract void movementType();

    public void displayMovement() {
        System.out.println(name + " moves using " + movementType());
    }
}

class LandRobot extends Robot {
    public LandRobot(String name) {
        super(name);
    }

    public void movementType() {
        System.out.println("Wheels");
    }
}

class FlyingRobot extends Robot {
    public FlyingRobot(String name) {
        super(name);
    }

    public void movementType() {
        System.out.println("Wings");
    }
}

public class Test {
    public static void main(String[] args) {
        LandRobot landRobot = new LandRobot("Land Robot 1");
        FlyingRobot flyingRobot = new FlyingRobot("Flying Robot 1");

        landRobot.displayMovement(); 
        flyingRobot.displayMovement();
    }
}

