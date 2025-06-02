interface Bowler {
    void bowls();
}

class FastBowler implements Bowler {
    protected double maxSpeed;
    protected String hand;

    public FastBowler(double maxSpeed, String hand) {
        this.maxSpeed = maxSpeed;
        this.hand = hand;
    }

    public void bowls() {
        System.out.println("Fast bowler bowls at a speed of " + maxSpeed + " km/h.");
    }

    public void display() {
        System.out.println("FastBowler Information:");
        System.out.println("Hand: " + hand);
        System.out.println("Max Speed: " + maxSpeed + " km/h");
    }
}

class FastMedium extends FastBowler {

    public FastMedium(double maxSpeed, String hand) {
        super(maxSpeed, hand);
    }

    public void display() {
        System.out.println("FastMedium Information:");
        System.out.println("Hand: " + hand);
        System.out.println("Max Speed: " + maxSpeed + " km/h");
    }
}

public class Test2 {
    public static void main(String[] args) {
  
        FastBowler fastBowler = new FastBowler(150, "Right Hand");
        fastBowler.bowls();
        fastBowler.display();

        FastMedium fastMedium = new FastMedium(130, "Left Hand");
        fastMedium.bowls();
        fastMedium.display();
    }
}
