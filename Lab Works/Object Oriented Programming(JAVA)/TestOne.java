interface Batter {
    void hits();
    void runs();
}

class Opener implements Batter {
    private int score;
    private String hand;

    public Opener() {
        this.score = 0;
        this.hand = "Right Hand";
    }

    public void setscore(int score) {
        this.score = score;
    }

    public void sethand(String hand) {
        this.hand = hand;
    }

    public int getscore() {
        return score;
    }

    public String gethand() {
        return hand;
    }

    public void hits() {
        System.out.println("Opener hits the ball!");
    }

    public void runs() {
        System.out.println("Opener runs between the wickets!");
    }

    public void display() {
        System.out.println("Opener Information:");
        System.out.println("Hand: " + hand);
        System.out.println("Score: " + score);
    }
}

public class TestOne {
    public static void main(String[] args) {
       
        Opener opener1 = new Opener();
        Opener opener2 = new Opener();

        opener1.hits();
        opener1.runs();

        opener1.setscore(50);
        opener1.sethand("Right Hand");
        opener1.display();
		
        opener2.setscore(33);
        opener2.sethand("Left Hand");

        opener2.display();
    }
}
