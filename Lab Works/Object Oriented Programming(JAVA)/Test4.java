interface Batter {
    void hits();
    void runs();
}

interface Bowler {
    void bowls();
}

class Spinner implements Bowler {
    private String style;
    public Spinner(String style) {
        this.style = style;
    }

    public void bowls() {
        System.out.println("Spinner bowls with a " + style + " style.");
    }

    public void googly() {
        System.out.println("Spinner bowls a googly!");
    }
}

class AllRounder implements Batter, Bowler {
    private String name;
    private Spinner spinner;

    public AllRounder(String name, String spinnerStyle) {
        this.name = name;
        this.spinner = new Spinner(spinnerStyle);
    }

    public void hits() {
        System.out.println(name + " hits the ball!");
    }

    public void runs() {
        System.out.println(name + " runs between the wickets!");
    }

    public void bowls() {
        spinner.bowls();
    }

    public void performGoogly() {
        spinner.googly();
    }
}

public class Test4 {
    public static void main(String[] args) {
        AllRounder sakep = new AllRounder("Sakep", "Leg Spin");

        sakep.hits();
        sakep.runs();
        sakep.bowls();
        sakep.performGoogly();
    }
}
