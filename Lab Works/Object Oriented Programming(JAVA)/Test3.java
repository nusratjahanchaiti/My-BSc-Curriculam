interface Batter {
    void hits();
    void runs();
}

interface Bowler {
    void bowls();
}

class AllRounder implements Batter, Bowler {
    private String name;
    private int battingAverage;
    private double bowlingAverage;

    public AllRounder(String name, int battingAverage, double bowlingAverage) {
        this.name = name;
        this.battingAverage = battingAverage;
        this.bowlingAverage = bowlingAverage;
    }

    public void hits() {
        System.out.println(name + " hits the ball!");
    }

    public void runs() {
        System.out.println(name + " runs between the wickets!");
    }

    public void bowls() {
        System.out.println(name + " bowls the ball!");
    }

    public void display() {
        System.out.println("AllRounder Information:");
        System.out.println("Name: " + name);
        System.out.println("Batting Average: " + battingAverage);
        System.out.println("Bowling Average: " + bowlingAverage);
    }
}

public class Test3 {
    public static void main(String[] args) {
     
        AllRounder allRounder = new AllRounder("Sakib", 45, 25.5);
        allRounder.hits();
        allRounder.runs();
        allRounder.bowls();
        allRounder.display();
    }
}
